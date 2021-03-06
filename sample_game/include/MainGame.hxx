#include "MainGame.h"

#undef min

#include <iostream>
#include <algorithm>
#include <glm/gtc/matrix_transform.hpp>

#include "tewi/Utils/Log.h"
#include "tewi/Video/Uniform.h"


constexpr float g_cameraSpeed = 20.0f;


template <typename APINum>
MainGame<APINum>::MainGame(const std::string& name, int width, int height)
        : tewi::GameCommon<MainGame<APINum>, APINum>(name, width, height)
        , m_camera(width, height)
{
    tewi::Log::info("MainGame<APINum>::MainGame");
}

template <typename APINum>
MainGame<APINum>::~MainGame()
{
    tewi::Log::info("MainGame<APINum>::~MainGame");
}

template <typename APINum>
void MainGame<APINum>::init()
{
    tewi::Log::info("MainGame<APINum>::init");
    m_sprite = std::make_unique<tewi::Sprite<APINum>>(
                    glm::vec2(0.0f, 0.0f), "textures/left_standing.png");

    m_player = std::make_unique<Player<APINum>>
            (glm::vec2(0.0f, 0.0f), "textures/spr.png",
             this->getInputManager(), g_cameraSpeed);


    constexpr const std::array<gsl::string_span, 4> attribs
    {
        "vertexPosition",
        "vertexUV",
        "vertexTID",
        "vertexColor"
    };

    tewi::Shader<APINum, tewi::VertexShader> vert(m_device, "shaders/shader.vert");
    tewi::Shader<APINum, tewi::FragmentShader> frag(m_device, "shaders/shader.frag");

    m_shader = std::make_unique<tewi::ShaderProgram<APINum>>(
        attribs, vert, frag
    );

}

template <typename APINum>
void MainGame<APINum>::processInputs()
{
    if (this->getInputManager().isKeyDown(GLFW_MOUSE_BUTTON_LEFT))
    {
        auto mouseCoords = this->getInputManager().getMouseCoords();
        m_camera.getWorldCoordsFromScreenCoords(mouseCoords);

        glm::vec2 playerPos(0.0f);
        glm::vec2 direction = mouseCoords - playerPos;
        direction = glm::normalize(direction);
        m_projectiles.emplace_back(glm::vec3(playerPos.x, playerPos.y, 0),
                        glm::vec3(direction.x, direction.y, 0), 1.0f, 2000, "textures/left_standing.png");
    }
}

template <typename APINum>
void MainGame<APINum>::update()
{
    m_timer.update();
    auto totalDelta = m_timer.getDeltaTime(60);

    for (int j = 0; j < 6 && totalDelta > 0.0; ++j)
    {
        // THE FUCKING DELTA
        auto deltaTime = std::min(totalDelta, 1.0);
        m_player->update(deltaTime);

        m_camera.setPosition(m_player->getRenderable().pos);
        m_camera.update();

        for (std::size_t i = 0; i < m_projectiles.size(); )
        {
            if (m_projectiles[i].update(deltaTime))
            {
                m_projectiles[i] = m_projectiles.back();
                m_projectiles.pop_back();
            }
            else
            {
                ++i;
            }
        }

        totalDelta -= deltaTime;
    }

    if (tewi::Physics::checkAABB(m_player->getCollidable(), m_sprite->getCollidable()))
    {
    }

}

template <typename APINum>
void MainGame<APINum>::draw()
{

    m_shader->enable();

    constexpr std::array<int, 22> tex_id_array = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21
    };

    tewi::setUniform(m_shader->getUniformLocation("textures"), tex_id_array);

    auto cameraMatrix = m_camera.getMatrix();

    tewi::setUniform(m_shader->getUniformLocation("vw_matrix"), cameraMatrix);

    m_batch.begin();

    m_batch.add(m_sprite->getRenderable());
    m_batch.add(m_player->getRenderable());

    for (const auto& elem : m_projectiles)
    {
        m_batch.add(elem.getRenderable());
    }

    m_batch.end();

    m_batch.draw();

    m_shader->disable();

    tewi::Log::info("Tickrate: " + std::to_string(this->getTimer().getTickRate()));
}

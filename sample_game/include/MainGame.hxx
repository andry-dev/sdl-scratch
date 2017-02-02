#include "MainGame.h"

#include <iostream>
#include <algorithm>
#include "Log.h"

#include "Video/Uniform.h"

#define CAMERA_SPEED 20.0f

template <int APINum>
MainGame<APINum>::MainGame(const std::string& name, int width, int height)
	: tewi::GameCommon<MainGame<APINum>, APINum>(name, width, height),
	m_camera(width, height)
{
	tewi::Log::info("MainGame<APINum>::MainGame");
}

template <int APINum>
MainGame<APINum>::~MainGame()
{
	tewi::Log::info("MainGame<APINum>::~MainGame");
}

template <int APINum>
void MainGame<APINum>::init()
{
#ifdef WORKING_IMPL
	tewi::Log::info("MainGame<APINum>::init");
	m_sprite = std::make_unique<tewi::Sprite<APINum>>(glm::vec2(0.0f, 0.0f),  "textures/left_standing.png");
	m_player = std::make_unique<Player>(glm::vec2(0.0f, 0.0f), "textures/spr.png", m_inputManager, CAMERA_SPEED);
	m_shader = std::make_unique<tewi::Shader>("shaders/shader.vert", "shaders/shader.frag");

	m_shader->addAttrib({"vertexPosition", "vertexUV", "vertexTID", "vertexColor"});
	m_shader->link();
#endif
}

template <int APINum>
void MainGame<APINum>::processInputs()
{
#ifdef WORKING_IMPL
	if (m_inputManager.isKeyDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		auto mouseCoords = m_inputManager.m_mouseCoords;
		m_camera.getWorldCoordsFromScreenCoords(mouseCoords);

		glm::vec2 playerPos(0.0f);
		glm::vec2 direction = mouseCoords - playerPos;
		direction = glm::normalize(direction);

		m_projectiles.emplace_back(glm::vec3(playerPos.x, playerPos.y, 0),
				glm::vec3(direction.x, direction.y, 0), 1.0f, 2000, "textures/left_standing.png");
	}
#endif
}

template <int APINum>
void MainGame<APINum>::update()
{
#ifdef WORKING_IMPL
	m_timer.update();
	double totalDelta = m_timer.getDeltaTime(60);
	tewi::Log::info("Delta: " + std::to_string(totalDelta));

	for (int j = 0; j < 6 && totalDelta > 0.0; ++j)
	{
		// THE FUCKING DELTA
		float deltaTime = std::min(totalDelta, 1.0);
		m_player->update(deltaTime);

		m_camera.setPosition(m_player->getRenderable().pos);
		m_camera.update();

		for (std::size_t i = 0; i < m_projectiles.size(); )
		{
			if (m_projectiles[i].update(deltaTime) == true)
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
		tewi::Log::info("Sprites collided");
	}

	tewi::Log::info("Tickrate: " + std::to_string(m_timer.getTickRate()));
#endif
}

template <int APINum>
void MainGame<APINum>::draw()
{
#ifdef WORKING_IMPL

	m_shader->enable();

	const std::vector<int> tex_id_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

	tewi::setUniform(m_shader->getUniformLocation("textures"), tex_id_array);

	tewi::setUniform(m_shader->getUniformLocation("P"), m_camera.getMatrix());

	//tewi::BatchRenderer2D<0> m_batch;

	m_batch.begin();

	m_batch.add(*m_sprite.get());
	m_batch.add(*m_player.get());

	// Typical C++ bullshit
	// Or even OOP bullshit in general
	// for (const auto& prj : m_projectiles)
	// {
	//	 m_batch.add(prj.getRenderable());
	// }


	std::vector<tewi::Renderable2D> proj;

	proj.reserve(m_projectiles.size());

	std::for_each(m_projectiles.begin(), m_projectiles.end(), [&proj](auto& elem)
			{
			proj.push_back(elem.getRenderable());
			});

	m_batch.add(proj);

	proj.clear();

	m_batch.end();

	m_batch.draw();

	m_shader->disable();
#endif
}

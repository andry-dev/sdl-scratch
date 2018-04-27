#include <string>
#include <array>
#include <iostream>

#include "asl/string_view"
#include "tewi/Video/Window.hpp"
#include "tewi/Video/API/API.h"
#include "tewi/IO/InputManager.h"
#include "tewi/Video/Sprite.h"
#include "tewi/Video/Renderer2D.hpp"
#include "tewi/Video/BatchRenderer2D.hpp"
#include "tewi/Video/Shader.hpp"
#include "tewi/Video/Uniform.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <optional>

constexpr std::array<int, 22> g_shaderTexIDs =
{
    0,  1,  2,  3,  4,  5,  6, 7,
    8,  9,  10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21
};

constexpr auto g_vertsrc = R"(
    #version 330 core
    layout (location = 0) in vec3 Pos;
    layout (location = 1) in vec3 Color;
    layout (location = 2) in vec3 TexCoord;

    void main()
    {

    }

)";

template <typename APITag>
using BatchRenderer2D = tewi::Renderer2D<APITag, tewi::BatchRenderer2D>;

template <typename APITag>
void startGame(asl::string_view str, tewi::Width width, tewi::Height height)
{
    tewi::InputManager inputManager;
    tewi::Window<APITag> win(str, width, height, &inputManager);

    tewi::setWindowKeyboardCallback(win, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
        auto& inputman = *(static_cast<tewi::InputManager*>(glfwGetWindowUserPointer(win)));

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            glfwWindowShouldClose(win);
        }
        else if (action == GLFW_PRESS)
        {
            inputman.pressKey(key);
        }
        else if (action == GLFW_RELEASE)
        {
            inputman.releaseKey(key);
        }
    });

    tewi::Sprite<APITag> spr(glm::vec2(0.0f, 0.0f), "textures/left_standing.png");
    BatchRenderer2D<APITag> rend{};

    using VertexShader = tewi::Shader<APITag, tewi::VertexShader, tewi::ShaderFromMemoryPolicy>;
    using FragmentShader = tewi::Shader<APITag, tewi::FragmentShader, tewi::ShaderFromMemoryPolicy>;

    auto shader = rend.createShaderProgram();

    glm::mat4 proj = glm::translate(glm::ortho<float>(0.0f, width.value(), 0.0f, height.value()), glm::vec3(30.0f, 20.0f, 0.0f));

    while (!tewi::isWindowClosed(win))
    {
        tewi::pollWindowEvents(win);

        win.context.preDraw();

        shader.enable();

        //tewi::setUniform(shader.getUniformLocation("textures"), g_shaderTexIDs);
        tewi::setUniform(shader.getUniformLocation("MVP"), proj);

        rend.begin();

        rend.add(spr.getRenderable());

        rend.end();

        rend.draw();

        shader.disable();

        win.context.postDraw();

        tewi::swapWindowBuffers(win);
    }
}

int main(int argc, const char* argv[])
{
    startGame<tewi::API::OpenGLTag>("Test", tewi::Width{800}, tewi::Height{600});
}

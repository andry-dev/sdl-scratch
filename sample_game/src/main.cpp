#include <string>
#include <array>

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

constexpr std::array<int, 22> g_shaderTexIDs =
{
    0,  1,  2,  3,  4,  5,  6, 7,
    8,  9,  10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21
};

template <typename APITag>
using BatchRenderer2D = tewi::Renderer2D<APITag, tewi::BatchRenderer2D>;

template <typename APITag>
void startGame(asl::string_view str, int width, int height)
{
    tewi::InputManager inputManager;
    tewi::Window<APITag> win(asl::to_string(str), width, height, &inputManager);

    win.setKeyboardCallback([](GLFWwindow* win, int key, int scancode, int action, int mods) {
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
    tewi::Sprite<APITag> spr2(glm::vec2(0.0f, 0.0f), "textures/spr.png");
    BatchRenderer2D<APITag> rend{};

    auto shader = rend.createShaderProgram();
    glm::mat4 proj = glm::translate(glm::ortho<float>(0.0f, width, 0.0f, height), glm::vec3(30.0f, 20.0f, 0.0f));

    while (!win.isWindowClosed())
    {
        win.pollEvents();

        win.getContext().preDraw();

        shader.enable();

        tewi::setUniform(shader.getUniformLocation("textures"), g_shaderTexIDs);
        tewi::setUniform(shader.getUniformLocation("MVP"), proj);

        rend.begin();

        rend.add(spr.getRenderable());
        rend.add(spr2.getRenderable());

        rend.end();

        rend.draw();

        shader.disable();

        win.getContext().postDraw();

        win.swap();
    }
}

int main(int argc, const char* argv[])
{
    startGame<tewi::API::OpenGLTag>("Test", 800, 600);
}

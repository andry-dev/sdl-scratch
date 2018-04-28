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
#include "tewi/Utils/TickTimer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <optional>

constexpr auto g_vertsrc = R"(
    #version 430
    layout (location = 0) in vec3 Pos;
    layout (location = 1) in vec2 Uv;

    uniform mat4 MVP;

    void main()
    {
        gl_Position = MVP * vec4(Pos, 1);
    }

)";

constexpr std::array<asl::string_view, 1> g_vertlocations {
    "Pos"
};

constexpr auto g_fragsrc = R"(
    #version 430
    out vec3 color;

    void main()
    {
        color = vec3(1, 0, 0);
    }
)";

struct Vertex3D
{
    glm::vec3 position;
    glm::vec2 uv;
};

const std::array<Vertex3D, 36> g_triangle_data {
#if 0
    Vertex3D{{ -1.0f, -1.0f, 0.0f }},
    Vertex3D{{ 1.0f, -1.0f, 0.0f }},
    Vertex3D{{ 0.0f, 1.0f, 0.0f }},
#else
    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ {  0.5f, -0.5f, -0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ {  0.5f,  0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ {  0.5f,  0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ { -0.5f,  0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 0.0f } },

    Vertex3D{ { -0.5f, -0.5f,  0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ {  0.5f, -0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ {  0.5f,  0.5f,  0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ {  0.5f,  0.5f,  0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ { -0.5f,  0.5f,  0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { -0.5f, -0.5f,  0.5f },  { 0.0f, 0.0f } },

    Vertex3D{ { -0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ { -0.5f,  0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { -0.5f, -0.5f,  0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ { -0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },

    Vertex3D{ { 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ { 0.5f,  0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ { 0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { 0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ { 0.5f, -0.5f,  0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ { 0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },

    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ {  0.5f, -0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ {  0.5f, -0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ {  0.5f, -0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ { -0.5f, -0.5f,  0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ { -0.5f, -0.5f, -0.5f },  { 0.0f, 1.0f } },

    Vertex3D{ { -0.5f,  0.5f, -0.5f },  { 0.0f, 1.0f } },
    Vertex3D{ {  0.5f,  0.5f, -0.5f },  { 1.0f, 1.0f } },
    Vertex3D{ {  0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ {  0.5f,  0.5f,  0.5f },  { 1.0f, 0.0f } },
    Vertex3D{ { -0.5f,  0.5f,  0.5f },  { 0.0f, 0.0f } },
    Vertex3D{ { -0.5f,  0.5f, -0.5f },  { 0.0f, 1.0f } },
#endif
};

template <typename APITag>
struct SimpleRenderer3D
{
};

template <>
struct SimpleRenderer3D<tewi::API::OpenGLTag>
{
protected:
    template <typename Container>
    SimpleRenderer3D(Container&& vertexlayout)
    {
        init();
    }

    SimpleRenderer3D()
    {
        init();
    }

    ~SimpleRenderer3D()
    {
        glDeleteBuffers(1, &m_VBO);
        glDeleteVertexArrays(1, &m_VAO);
    }

    void begin()
    {
        glBindVertexArray(m_VAO);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)(offsetof(Vertex3D, uv)));
    }

    template <typename T>
    void add(T&&)
    {

    }

    void end()
    {
    }

    void draw()
    {
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
private:
    void init()
    {
        glGenVertexArrays(1, &m_VAO);

        glGenBuffers(1, &m_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3D) * 36, &g_triangle_data[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLuint m_VBO;
    GLuint m_VAO;
};

struct Camera3D
{
    auto getViewMatrix()
    {
        return glm::lookAt(m_position, m_position + m_direction, m_up);
    }

    auto update()
    {
        glm::vec3 frontCamera;
        frontCamera.x = cos(glm::radians(m_pitch)) * cos(glm::radians(m_yaw));
        frontCamera.y = sin(glm::radians(m_pitch));
        frontCamera.z = cos(glm::radians(m_pitch)) * sin(glm::radians(m_yaw));

        m_direction = glm::normalize(frontCamera);

        m_right = glm::normalize(glm::cross(m_direction, m_worldUp));
        m_up = glm::normalize(glm::cross(m_right, m_direction));
    }

    void forward(const float deltatime, const float velocity)
    {
        m_position += (velocity * deltatime) * m_direction;
    }
    
    void backward(const float deltatime, const float velocity)
    {
        m_position -= (velocity * deltatime) * m_direction;
    }

    void left(const float deltatime, const float velocity)
    {
        m_position -= (velocity * deltatime) * m_right;
    }

    void right(const float deltatime, const float velocity)
    {
        m_position += (velocity * deltatime) * m_right;
    }
    
    void moveMouse(float xoffset, float yoffset, const float sensitivity)
    {
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        m_yaw += xoffset;
        m_pitch += yoffset;

        if (m_pitch > 89.0f)
        {
            m_pitch = 89.0f;
        }
        else if (m_pitch < -89.0f)
        {
            m_pitch = -89.0f;
        }

        update();
    }

private:
    glm::vec3 m_position{0.0f, 0.0f, 0.0f};
    glm::vec3 m_direction{0.0f, 0.0f, -1.0f};
    glm::vec3 m_right{0.0f, 0.0f, 0.0f};
    const glm::vec3 m_worldUp{0.0f, 1.0f, 0.0f};
    glm::vec3 m_up{0.0f, 1.0f, 0.0f};
    float m_pitch = 0.0f;
    float m_yaw = 0.0f;
};


void moveCameraMouse(Camera3D& camera, tewi::InputManager& inputManager)
{
    auto mousecoords = inputManager.getMouseCoords();
    static float lastx = 0;
    static float lasty = 0;

    float xoffset = mousecoords.x - lastx;
    float yoffset = lasty - mousecoords.y;
    lastx = mousecoords.x;
    lasty = mousecoords.y;

    float sensitivity = 1.0f;
    camera.moveMouse(xoffset, yoffset, sensitivity);
}

template <typename APITag>
using Renderer = tewi::Renderer2D<APITag, SimpleRenderer3D>;

template <typename APITag>
using Renderer2D = tewi::Renderer2D<APITag, tewi::BatchRenderer2D>;


template <typename APITag>
void startGame(asl::string_view str, tewi::Width width, tewi::Height height)
{
    tewi::InputManager inputManager;
    tewi::Window<APITag> win(str, width, height, &inputManager);
    tewi::TickTimer timer;

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

    tewi::setWindowMouseCursorPosCallback(win, [] (GLFWwindow* win, double x, double y) {
        auto& inputman = *(static_cast<tewi::InputManager*>(glfwGetWindowUserPointer(win)));

        inputman.setMouseCoords(glm::vec2{x, y});
    });

    Renderer<APITag> rend{};

    using VertexShader = tewi::Shader<APITag, tewi::VertexShader, tewi::ShaderFromMemoryPolicy>;
    using FragmentShader = tewi::Shader<APITag, tewi::FragmentShader, tewi::ShaderFromMemoryPolicy>;
    VertexShader vert(tewi::API::Device<APITag>{}, g_vertsrc);
    FragmentShader frag(tewi::API::Device<APITag>{}, g_fragsrc);
    
    tewi::ShaderProgram<APITag> shader(g_vertlocations, vert, frag);

    auto proj = glm::perspective(glm::radians(45.0f), (float)width.value() / (float)height.value(), 0.1f, 100.0f);
    auto MVP = proj;
    glm::mat4 view;

    Camera3D camera;

    while (!tewi::isWindowClosed(win))
    {
        tewi::pollWindowEvents(win);

        {
            const float deltatime = timer.getDeltaTime();
            const float cameraSpeed = 200.0f * deltatime;
            if (inputManager.isKeyDown(GLFW_KEY_W))
            {
                camera.forward(deltatime, cameraSpeed);
            }
            else if (inputManager.isKeyDown(GLFW_KEY_S))
            {
                camera.backward(deltatime, cameraSpeed);
            }
            else if (inputManager.isKeyDown(GLFW_KEY_A))
            {
                camera.left(deltatime, cameraSpeed);
            }
            else if (inputManager.isKeyDown(GLFW_KEY_D))
            {
                camera.right(deltatime, cameraSpeed);
            }
        }

        moveCameraMouse(camera, inputManager);
        camera.update();

        {
            float window_width = (float)(tewi::getWindowWidth(win).value());
            float window_height = (float)(tewi::getWindowHeight(win).value());
            proj = glm::perspective(glm::radians(90.0f), window_width / window_height, 0.1f, 100.0f);
        }

        view = camera.getViewMatrix();

        MVP = proj * view;

        win.context.preDraw();

        shader.enable();

        tewi::setUniform(shader.getUniformLocation("MVP"), MVP);

        rend.begin();

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

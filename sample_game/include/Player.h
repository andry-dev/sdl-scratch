#ifndef PLAYER_H
#define PLAYER_H

#include "tewi/Video/Sprite.h"
#include "tewi/Physics/Collidable2D.h"

#include "tewi/IO/InputManager.h"

#include "tewi/Utils/Log.h"

template <typename APIType>
class Player : public tewi::Sprite<APIType>
{
public:
    Player(const glm::vec2& pos, const std::string& path, tewi::InputManager& inputMan, float speed)
        : tewi::Sprite<APIType>(pos, path),
        m_speed(speed),
        m_inputManager(inputMan)
    {
    }

    void update(float delta)
    {
        if (m_inputManager.isKeyDown(GLFW_KEY_D))
        {
            this->m_renderable.pos.y += m_speed * delta;
        }
        else if (m_inputManager.isKeyDown(GLFW_KEY_E))
        {
            this->m_renderable.pos.y -= m_speed * delta;
        }
        if (m_inputManager.isKeyDown(GLFW_KEY_S))
        {
            this->m_renderable.pos.x += m_speed * delta;
        }
        else if (m_inputManager.isKeyDown(GLFW_KEY_F))
        {
            this->m_renderable.pos.x -= m_speed * delta;
        }
    }

private:
    
    float m_speed;
    tewi::InputManager& m_inputManager;
};

#endif /* PLAYER_H */

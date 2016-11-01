#ifndef PLAYER_H
#define PLAYER_H

#include "Video/Sprite.h"
#include "Physics/Collidable2D.h"

#include "IO/InputManager.h"

#include "Log.h"

class Player : public tewi::Video::Sprite
{
public:
	Player(const glm::vec2& pos, const std::string& path, tewi::IO::InputManager& inputMan, float speed)
		: Sprite(pos, path),
		m_speed(speed),
		m_inputManager(inputMan)
	{
	}

	void update(double delta)
	{
		if (m_inputManager.isKeyDown(GLFW_KEY_D))
		{
			m_renderable.pos.y += m_speed * delta;
		}
		else if (m_inputManager.isKeyDown(GLFW_KEY_E))
		{
			m_renderable.pos.y -= m_speed * delta;
		}
		if (m_inputManager.isKeyDown(GLFW_KEY_S))
		{
			m_renderable.pos.x += m_speed * delta;
		}
		else if (m_inputManager.isKeyDown(GLFW_KEY_F))
		{
			m_renderable.pos.x -= m_speed * delta;
		}
	}

private:
	
	float m_speed;
	tewi::IO::InputManager& m_inputManager;
};

#endif /* PLAYER_H */

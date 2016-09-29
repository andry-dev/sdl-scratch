#ifndef PLAYER_H
#define PLAYER_H

#include "Video/Sprite.h"
#include "Physics/Collidable2D.h"

#include "IO/InputManager.h"

class Player : public tewi::Video::Sprite
{
public:
	Player(const glm::vec2& pos, const std::string& path, tewi::IO::InputManager& inputMan, float speed)
		: Sprite(pos, path),
		m_speed(speed),
		m_inputManager(inputMan)
	{
	}

	void update()
	{
		if (m_inputManager.isKeyDown(SDLK_d))
			m_pos.y += m_speed;
		else if (m_inputManager.isKeyDown(SDLK_e))
			m_pos.y -= m_speed;
		if (m_inputManager.isKeyDown(SDLK_s))
			m_pos.x += m_speed;
		else if (m_inputManager.isKeyDown(SDLK_f))
			m_pos.x -= m_speed;
	}

private:
	
	float m_speed;
	tewi::IO::InputManager& m_inputManager;
};

#endif /* PLAYER_H */

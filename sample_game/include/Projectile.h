#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <glm/glm.hpp>

#include "Video/Sprite.h"

template <typename APIType>
class Projectile : public tewi::Sprite<APIType>
{
public:
	Projectile(const glm::vec2& pos, const glm::vec3& direction, float speed, int lifetime, const std::string& texturePath)
		: tewi::Sprite<APIType>(pos, 0.25f, texturePath), m_direction(direction), m_lifetime(lifetime), m_speed(speed)
	{

	}

	bool update(float delta)
	{
		this->m_renderable.pos += m_direction * (m_speed * delta);
		m_lifetime -= delta;

		if (m_lifetime <= 0)
		{
			return true;
		}

		return false;
	}

private:
	
	glm::vec2 m_direction;
	float m_lifetime;
	float m_speed;
};

#endif /* PROJECTILE_H */

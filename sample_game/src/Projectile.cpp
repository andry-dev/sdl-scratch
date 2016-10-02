#include "Projectile.h"

Projectile::Projectile(const glm::vec2& pos, const glm::vec3& direction, float speed, int lifetime, const std::string& texturePath)
	: tewi::Video::Sprite(pos, glm::vec2(10.0f, 10.0f), texturePath), m_direction(direction), m_lifetime(lifetime), m_speed(speed)
{

}

Projectile::~Projectile()
{

}


bool Projectile::update()
{
	m_pos += m_direction * m_speed;
	--m_lifetime;

	if (m_lifetime <= 0)
	{
		return true;
	}

	return false;
}

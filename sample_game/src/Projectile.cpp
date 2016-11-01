#include "Projectile.h"

Projectile::Projectile(const glm::vec2& pos, const glm::vec3& direction, float speed, int lifetime, const std::string& texturePath)
	: tewi::Video::Sprite(pos, 0.25f, texturePath), m_direction(direction), m_lifetime(lifetime), m_speed(speed)
{

}

Projectile::~Projectile()
{

}


bool Projectile::update(float delta)
{
	m_renderable.pos += m_direction * (m_speed * delta);
	m_lifetime -= delta;

	if (m_lifetime <= 0)
	{
		return true;
	}

	return false;
}

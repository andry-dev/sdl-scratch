#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <glm/glm.hpp>

#include "Video/Sprite.h"

class Projectile : public tewi::Sprite
{
public:
	Projectile(const glm::vec2& pos, const glm::vec3& direction, float speed, int lifetime, const std::string& texturePath);

	bool update(float delta);
private:
	
	glm::vec2 m_direction;
	float m_lifetime;
	float m_speed;
};

#endif /* PROJECTILE_H */

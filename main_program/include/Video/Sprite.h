#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Sprite
{
public:
	Sprite(float x, float y, float w, float h);
	~Sprite();
	
	void draw();
private:


	float m_xpos = 0;
	float m_ypos = 0;
	float m_width = 0;
	float m_height = 0;

	std::uint32_t m_VBOID = 0;
	
};

#endif /* SPRITE_H */
#ifndef SPRITE_H
#define SPRITE_H

#include <cstdint>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Sprite
{
public:
	Sprite(int x, int y, int w, int h);
	~Sprite();
	
	void draw();
private:


	int m_xpos = 0;
	int m_ypos = 0;
	int m_width = 0;
	int m_height = 0;

	std::uint32_t m_VBOID = 0;
	
};

#endif /* SPRITE_H */

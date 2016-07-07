#include "Video/Sprite.h"

#include <array>

Sprite::Sprite(float x, float y, float w, float h)
	: m_xpos(x), m_ypos(y), m_width(w), m_height(h)
{
	if (m_VBOID == 0)
	{
		glGenBuffers(1, &m_VBOID);
	}

	std::array<float, 6 * 2> vertexData;

	// First Triangle
	vertexData.at(0) = m_xpos + m_width;
	vertexData.at(1) = m_ypos + m_height;

	vertexData.at(2) = m_xpos;
	vertexData.at(3) = m_ypos + m_height;

	vertexData.at(4) = m_xpos;
	vertexData.at(5) = m_ypos;

	// Seconda Triangle
	vertexData.at(6) = m_xpos;
	vertexData.at(7) = m_ypos;

	vertexData.at(8) = m_xpos + m_width;
	vertexData.at(9) = m_ypos;

	vertexData.at(10) = m_xpos + m_width;
	vertexData.at(11) = m_ypos + m_height;
	
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size(), vertexData.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Sprite::~Sprite()
{
	if (m_VBOID != 0)
	{
		glDeleteBuffers(1, &m_VBOID);
	}
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

#include "Video/Sprite.h"

#include <array>
#include <cstddef>

#include "Video/Vertex.h"

Sprite::Sprite(float x, float y, float w, float h)
	: m_xpos(x), m_ypos(y), m_width(w), m_height(h)
{
	if (m_VBOID == 0)
	{
		glGenBuffers(1, &m_VBOID);
	}

	std::array<Vertex, 6> vertexData;

	// First Triangle
	vertexData.at(0).position.x = m_xpos + m_width;
	vertexData.at(0).position.y = m_ypos + m_height;

	vertexData.at(1).position.x = m_xpos;
	vertexData.at(1).position.y = m_ypos + m_height;

	vertexData.at(2).position.x = m_xpos;
	vertexData.at(2).position.y = m_ypos;

	// Second Triangle
	vertexData.at(3).position.x = m_xpos;
	vertexData.at(3).position.y = m_ypos;

	vertexData.at(4).position.x = m_xpos + m_width;
	vertexData.at(4).position.y = m_ypos;

	vertexData.at(5).position.x = m_xpos + m_width;
	vertexData.at(5).position.y = m_ypos + m_height;

	for (auto& v : vertexData)
	{
		v.color.r = 255;
		v.color.g = 0;
		v.color.b = 255;
		v.color.a = 255;
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(Vertex), vertexData.data(), GL_STATIC_DRAW);
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

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*> (offsetof(Vertex, position)));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

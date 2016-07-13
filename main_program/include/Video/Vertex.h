#ifndef VERTEX_H
#define VERTEX_H

#include <array>
#include <cstdint>

struct Vertex
{
	struct Position
	{
		float x;
		float y;
	} position;

	struct Color
	{
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;
		std::uint8_t a;
	} color;
};

std::uint32_t setColors(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
{
	return r << 24 | g << 16 | b << 8 | a;
}

// You really shouldn't use this function with other types
template <typename T>
std::uint32_t getColors(T, T, T, T) = delete;

std::array<std::uint8_t, 4> getColors(std::uint32_t color)
{
	// This may not seem obvious at first
	// Basically, it bit-manipulate the 'hard-coded' colors into an array of single channels
	return {{
		static_cast<std::uint8_t> ((color >> 24) & 0xFF), // R
		static_cast<std::uint8_t> ((color >> 16) & 0xFF), // G
		static_cast<std::uint8_t> ((color >> 8) & 0xFF), // B
		static_cast<std::uint8_t> (color & 0xFF) // A
	}};
}

// Same as above
template <typename T>
std::array<std::uint8_t, 4> getColors(T) = delete;

#endif /* VERTEX_H */

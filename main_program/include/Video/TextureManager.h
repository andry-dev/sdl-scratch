#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <map>

#include "lodepng/picopng.h"
#include "Video/Texture.h"

class TextureManager
{
public:
	static Texture getTexture(const std::string& path);
private:
	static Texture load(const std::string& path);
	static std::map<std::string, Texture> m_map;
};

#endif /* TEXTURE_MANAGER_H */

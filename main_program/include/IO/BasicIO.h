#ifndef BASIC_IO_H
#define BASIC_IO_H

#include <vector>
#include <string>
#include <fstream>

#include "Log.h"

inline std::vector<unsigned char> fileToBuffer(const std::string& path)
{
	std::ifstream file(path, std::ios::binary);

	Expects(!file.fail(), "Can't open file " + path);

	file.seekg(0, std::ios::end);

	int fileSize = file.tellg();

	std::vector<unsigned char> buffer(fileSize);

	// This cast.
	file.read((char*)(&buffer[0]), fileSize);

	return buffer;
}

#endif /* BASIC_IO_H */

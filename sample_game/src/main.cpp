#include <iostream>
#include <string>

#include "Video/API/Context.hpp"

#include "MainGame.h"

int main(int argc, const char** argv)
{
	int res = 0;
	std::cout << "Choose API, 1 = OGL, 2 = Vk\n";
	std::cin >> res;

	if (res == 1)
	{
		std::cout << "Opengl\n";
		MainGame<tewi::API::OpenGLTag> game("Test", 800, 600);
		game.start();
	}
	/* else if (res == 2) */
	/* { */
	/* 	std::cout << "Vulkan\n"; */
	/* 	MainGame<tewi::API::VulkanTag> game("Test", 800, 600); */
	/* 	game.start(); */
	/* } */

	return 0;
}

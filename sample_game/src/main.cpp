#include <iostream>
#include <string>

#include "Video/API/Context.hpp"

#include "MainGame.h"

int main(int argc, char** argv)
{
	int res = 0;
	std::cout << "Choose API, 1 = OGL, 2 = Vk\n";
	std::cin >> res;

	if (res == tewi::API::API_TYPE::OPENGL)
	{
		std::cout << "Opengl\n";
		MainGame<tewi::API::API_TYPE::OPENGL> game("Test", 800, 600);
		game.start();
	}
	else if (res == tewi::API::API_TYPE::VULKAN)
	{
		std::cout << "Vulkan\n";
		MainGame<tewi::API::API_TYPE::VULKAN> game("Test", 800, 600);
		game.start();
	}

	return 0;
}

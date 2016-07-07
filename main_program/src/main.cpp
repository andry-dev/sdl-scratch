#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "../include/MainGame.h"

#define WINLEL_WIDTH 640
#define WINLEL_HEIGHT 480

int main(int, char**)
{
	MainGame game("Test OpenGL", 800, 600);

	return 0;
}



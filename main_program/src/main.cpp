#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINLEL_WIDTH 640
#define WINLEL_HEIGHT 480

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINLEL_WIDTH, WINLEL_HEIGHT, SDL_WINDOW_OPENGL);

	while (true) {
		
	}

	return 0;
}



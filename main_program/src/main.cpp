#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#define WINLEL_WIDTH 640
#define WINLEL_HEIGHT 480

int main()
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
			"Test",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			WINLEL_WIDTH,
			WINLEL_HEIGHT,
			SDL_WINDOW_OPENGL);

	while (true) {

	}

	return 0;
}



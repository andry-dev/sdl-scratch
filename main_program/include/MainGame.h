#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <string>

class MainGame
{
public:
	MainGame(const std::string& name, int width, int height);
	~MainGame();
	

private:
	void init();
	void initInputs();
	void gameLoop();

	int m_width  = 0;
	int m_height = 0;
	
	SDL_Window* m_window;
};

#endif /* MAIN_GAME_H */

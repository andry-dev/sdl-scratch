#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <string>
#include <memory>

#include "Video/Sprite.h"

enum class GameState
{
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame(const std::string& name, int width, int height);
	~MainGame();
	

private:
	void init();
	void processInputs();
	void gameLoop();
	void drawGame();

	int m_width  = 0;
	int m_height = 0;
	
	SDL_Window* m_window;

	GameState m_gameState;

	std::unique_ptr<Sprite> m_sprite;
};

#endif /* MAIN_GAME_H */

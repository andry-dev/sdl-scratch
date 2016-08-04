#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <vector>

#include <string>
#include <memory>

#include "Video/Sprite.h"
#include "Video/Shader.h"

#include "Utils/TickTimer.h"


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

	std::vector<Sprite*> m_sprite;
	std::unique_ptr<Shader> m_shader;

	float m_time;

	TickTimer m_tcTimer;
};

#endif /* MAIN_GAME_H */

#ifndef MAIN_GAME_H
#define MAIN_GAME_H


#include <vector>

#include <string>
#include <memory>

#include "GameCommon.hpp"

#include "Video/Sprite.h"
#include "Video/Shader.h"

#include "Utils/TickTimer.h"


enum class GameState
{
	PLAY,
	EXIT
};

class MainGame : public tewi::GameCommon<MainGame>
{
public:
	MainGame(const std::string& name, int width, int height);
	~MainGame();

	void init();
	void processInputs();
	void draw();

private:
	GameState m_gameState;

	std::vector<Sprite*> m_sprite;
	std::unique_ptr<Shader> m_shader;

	float m_time;
};

#endif /* MAIN_GAME_H */

#ifndef MAIN_GAME_H
#define MAIN_GAME_H


#include <vector>

#include <string>
#include <memory>

#include "GameCommon.hpp"

#include "Video/Sprite.h"
#include "Video/Shader.h"

#include "Utils/TickTimer.h"

#include "Video/Camera2D.h"
#include "Video/BatchRenderer2D.h"

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
	void update();
	void draw();

private:
	std::unique_ptr<tewi::Video::Sprite> m_sprite;
	std::vector<tewi::Video::Sprite> m_spriteArray;
	std::unique_ptr<tewi::Video::Shader> m_shader;

	tewi::Video::Camera2D m_camera;
	tewi::Video::BatchRenderer2D m_batch;
	tewi::Utils::TickTimer m_timer;
};

#endif /* MAIN_GAME_H */

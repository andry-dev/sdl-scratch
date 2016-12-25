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
#include "Video/BatchRenderer2D.hpp"

#include "IO/InputManager.h"

#include "Projectile.h"

#include "Player.h"

class MainGame : public tewi::GameCommon<MainGame, tewi::API::API_TYPE::OPENGL>
{
public:
	MainGame(const std::string& name, int width, int height);
	~MainGame();

	void init();
	void processInputs();
	void update();
	void draw();

private:
	tewi::Camera2D m_camera;
	
	std::unique_ptr<tewi::Sprite> m_sprite;
	std::unique_ptr<Player> m_player;
	std::unique_ptr<tewi::Shader> m_shader;

	tewi::BatchRenderer2D<tewi::API::API_TYPE::OPENGL> m_batch;
	tewi::TickTimer m_timer;

	std::vector<Projectile> m_projectiles;
};

#endif /* MAIN_GAME_H */

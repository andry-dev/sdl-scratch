#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <vector>

#include <string>
#include <memory>

#include "GameCommon.hpp"

#include "Video/Sprite.h"
#include "Video/API/Shader.hpp"
#include "Platform/OpenGL/Shader.hpp"

#include "Utils/TickTimer.h"

#include "Video/Camera2D.h"
#include "Video/BatchRenderer2D.hpp"

#include "IO/InputManager.h"

#include "Projectile.h"

#include "Player.h"

template <int APINum>
class MainGame : public tewi::GameCommon<MainGame<APINum>, APINum>
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
	
#ifdef WORKING_IMPL
	std::unique_ptr<tewi::Sprite<APINum>> m_sprite;
	std::unique_ptr<Player> m_player;
	std::unique_ptr<tewi::Shader<APINum>> m_shader;

	tewi::BatchRenderer2D<APINum> m_batch;
	tewi::TickTimer m_timer;

	std::vector<Projectile> m_projectiles;
#endif
};

#include "MainGame.hxx"

#endif /* MAIN_GAME_H */

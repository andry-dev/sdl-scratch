#pragma once

#include <vector>

#include <string>
#include <memory>

#include "tewi/GameCommon.hpp"

#include "tewi/IO/InputManager.h"

#include "tewi/Platform/OpenGL/Shader.hpp"
#include "tewi/Platform/OpenGL/BatchRenderer2D.hpp"

#include "tewi/Utils/TickTimer.h"

#include "tewi/Video/Shader.hpp"
#include "tewi/Video/Renderer2D.hpp"
#include "tewi/Video/BatchRenderer2D.hpp"
#include "tewi/Video/Camera2D.h"
#include "tewi/Video/Sprite.h"

#include "Projectile.h"
#include "Player.h"

#define WORKING_IMPL

template <typename APINum>
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
	tewi::API::Device<APINum> m_device;
	
#ifdef WORKING_IMPL
	std::unique_ptr<tewi::Sprite<APINum>> m_sprite;
	std::unique_ptr<Player<APINum>> m_player;
        std::unique_ptr<tewi::ShaderProgram<APINum>> m_shader;

	tewi::Renderer2D<APINum, tewi::BatchRenderer2D> m_batch;
	tewi::TickTimer m_timer;

	std::vector<Projectile<APINum>> m_projectiles;
#endif
};

#include "MainGame.hxx"

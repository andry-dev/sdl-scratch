#pragma once

#include <vector>

#include <string>
#include <memory>

#include "GameCommon.hpp"

#include "Video/Shader.hpp"
#include "Platform/OpenGL/Shader.hpp"
#include "Video/Renderer2D.hpp"
#include "Video/BatchRenderer2D.hpp"
#include "Platform/OpenGL/BatchRenderer2D.hpp"
#include "Video/Camera2D.h"
#include "Video/Sprite.h"
#include "IO/InputManager.h"
#include "Utils/TickTimer.h"

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
	std::unique_ptr<tewi::Shader<APINum, tewi::VertexShader>> m_vertShader;
	std::unique_ptr<tewi::Shader<APINum, tewi::FragmentShader>> m_fragShader;
	std::unique_ptr<tewi::ShaderProgram<APINum>> m_shader;

	tewi::Renderer2D<APINum, tewi::BatchRenderer2D> m_batch;
	tewi::TickTimer m_timer;

	std::vector<Projectile<APINum>> m_projectiles;
#endif
};

#include "MainGame.hxx"

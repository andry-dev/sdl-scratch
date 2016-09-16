#include "MainGame.h"

#include <iostream>
#include "Log.h"

#include "Video/Uniform.h"

#define CAMERA_SPEED 20.0f

MainGame::MainGame(const std::string& name, int width, int height)
	: GameCommon(name, width, height),
	m_camera(width, height)
{
	tewi::Log::info("MainGame::MainGame");
}

MainGame::~MainGame()
{
	tewi::Log::info("MainGame::~MainGame");
}

void MainGame::init()
{
	const int spriteSize = m_window->getWidth() / 4;

	tewi::Log::info("MainGame::init");
	m_sprite = std::make_unique<tewi::Video::Sprite>(glm::vec2(0.0f, 0.0f),  "textures/left_standing.png");
	m_player = std::make_unique<Player>(glm::vec2(0.0f, 0.0f), "textures/spr.png", m_inputManager, 2.0f);
	m_shader = std::make_unique<tewi::Video::Shader>("shaders/shader.vert", "shaders/shader.frag");

	m_shader->addAttrib({"vertexPosition", "vertexUV", "vertexTID", "vertexColor"});
	m_shader->link();
}

void MainGame::processInputs()
{

	if (m_inputManager.isKeyPressed(SDL_BUTTON_LEFT))
	{
		auto mouseCoords = m_inputManager.m_mouseCoords;
		m_camera.getWorldCoordsFromScreenCoords(mouseCoords);

		glm::vec2 playerPos(0.0f);
		glm::vec2 direction = mouseCoords - playerPos;
		direction = glm::normalize(direction);

		m_projectiles.emplace_back(glm::vec3(playerPos.x, playerPos.y, 0),
									glm::vec3(direction.x, direction.y, 0), 1.0f, 2000, "textures/left_standing.png");
	}
}

void MainGame::update()
{
	m_timer.update();
	m_player->update();

	m_camera.setPosition(m_player->getPosition());
	m_camera.update();

	for (std::size_t i = 0; i < m_projectiles.size(); )
	{
		if (m_projectiles[i].update() == true)
		{
			m_projectiles[i] = m_projectiles.back();
			m_projectiles.pop_back();
		}
		else
		{
			++i;
		}
	}

	if (m_player->checkAABB(m_sprite.get()))
	{
		tewi::Log::info("Sprites collided");
	}

	std::printf("%lu\n", m_timer.getTickRate());
}

void MainGame::draw()
{
	m_shader->enable();

	const std::vector<int> tex_id_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

	tewi::Video::setUniform(m_shader->getUniformLocation("mySampler"), tex_id_array);

	tewi::Video::setUniform(m_shader->getUniformLocation("P"), m_camera.getMatrix());

	m_batch.begin();

	m_batch.add(m_sprite.get());
	m_batch.add(m_player.get());

	for (const auto& prj : m_projectiles)
	{
		m_batch.add(&prj);
	}

	m_batch.end();

	m_batch.draw();

	m_shader->disable();
}

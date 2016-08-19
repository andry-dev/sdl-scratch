#include "MainGame.h"

#include <iostream>
#include "Log.h"

#include "Video/Uniform.h"

#define CAMERA_SPEED 10.0f

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
	tewi::Log::info("MainGame::init");
	m_sprite = std::make_unique<tewi::Video::Sprite>(glm::vec2(0.0f, 0.0f), glm::vec2(m_window->getWidth() / 2, m_window->getWidth() / 2), "textures/left_standing.png");
	m_shader = std::make_unique<tewi::Video::Shader>("shaders/shader.vert", "shaders/shader.frag");

	m_shader->addAttrib({"vertexPosition", "vertexUV", "vertexTID", "vertexColor"});
	m_shader->link();
}

void MainGame::processInputs()
{
	switch (m_event.type)
	{
#if 1
		case SDL_KEYDOWN:
			switch (m_event.key.keysym.sym)
			{
				case SDLK_e:
					m_camera.setPosition(m_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
					break;
				case SDLK_s:
					m_camera.setPosition(m_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0f));
					break;
				case SDLK_d:
					m_camera.setPosition(m_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
					break;
				case SDLK_f:
					m_camera.setPosition(m_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
					break;
				case SDLK_w:
					m_camera.setScale(m_camera.getScale() + 0.1f);
					break;
				case SDLK_r:
					m_camera.setScale(m_camera.getScale() - 0.1f);
					break;
			}
			break;

		case SDL_MOUSEWHEEL:
			switch(m_event.wheel.type)
			{
				case SDL_MOUSEWHEEL:
					m_camera.setScale(m_camera.getScale() + m_event.wheel.x);
			}
			break;
#endif
	}

}

void MainGame::update()
{
	m_camera.update();
}

void MainGame::draw()
{
	m_shader->enable();

	tewi::Video::setUniform(m_shader->getUniformLocation("mySampler"), 0);

	tewi::Video::setUniform(m_shader->getUniformLocation("P"), m_camera.getMatrix());

	m_batch.begin();

	m_batch.add(m_sprite.get());

	m_batch.end();

	m_batch.draw();

	m_shader->disable();
}

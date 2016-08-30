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
	m_sprite = std::make_unique<tewi::Video::Sprite>(glm::vec2(0.0f, 0.0f), glm::vec2(spriteSize, spriteSize), "textures/left_standing.png");
	for (std::size_t j = 0; j < 10; ++j)
	{
		for (std::size_t i = 0; i < 10; ++i)
		{
			m_spriteArray.emplace_back(glm::vec2(i * 200.0f, j * 200.0f), glm::vec2(spriteSize, spriteSize), "textures/left_standing.png");
		}
	}
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
			m_inputMan.pressKey(m_event.key.keysym.sym);
			break;

		case SDL_KEYUP:
			m_inputMan.relaseKey(m_event.key.keysym.sym);


		case SDL_MOUSEWHEEL:
			switch(m_event.wheel.type)
			{
				case SDL_MOUSEWHEEL:
					m_camera.setScale(m_camera.getScale() + m_event.wheel.x);
			}
			break;
#endif
	}


	if (m_inputMan.isKeyPressed(SDLK_e))
		m_camera.setPosition(m_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
	if (m_inputMan.isKeyPressed(SDLK_s))
		m_camera.setPosition(m_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0f));
	if (m_inputMan.isKeyPressed(SDLK_d))
		m_camera.setPosition(m_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
	if (m_inputMan.isKeyPressed(SDLK_f))
		m_camera.setPosition(m_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
	if (m_inputMan.isKeyPressed(SDLK_w))
		m_camera.setScale(m_camera.getScale() + 0.1f);
	if (m_inputMan.isKeyPressed(SDLK_r))
		m_camera.setScale(m_camera.getScale() - 0.1f);

}

void MainGame::update()
{
	m_timer.update();
	m_camera.update();
	tewi::Log::info(std::to_string(m_timer.getTickRate()));
}

void MainGame::draw()
{
	m_shader->enable();

	const std::vector<int> tex_id_array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

	tewi::Video::setUniform(m_shader->getUniformLocation("mySampler"), tex_id_array);

	tewi::Video::setUniform(m_shader->getUniformLocation("P"), m_camera.getMatrix());

	m_batch.begin();

	//m_batch.add(m_sprite.get());

	for (const auto& v : m_spriteArray)
	{
		m_batch.add(&v);
	}

	m_batch.end();

	m_batch.draw();

	m_shader->disable();
}

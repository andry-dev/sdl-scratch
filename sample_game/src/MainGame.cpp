#include "MainGame.h"

#include <iostream>
#include "Log.h"

#include "Video/Uniform.h"

MainGame::MainGame(const std::string& name, int width, int height)
	: GameCommon(name, width, height)
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
	m_sprite = std::make_unique<tewi::Video::Sprite>(-1.0f, -1.0f, 1.0f, 1.0f, "textures/left_standing.png");
	m_shader = std::make_unique<tewi::Video::Shader>("shaders/shader.vert", "shaders/shader.frag");

	m_shader->addAttrib({"vertexPosition", "vertexColor", "vertexUV"});
	m_shader->link();
}

void MainGame::processInputs()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{

	}
}

void MainGame::draw()
{
	m_shader->enable();

	// Pure questo
	glActiveTexture(GL_TEXTURE0);
	tewi::Video::setUniform(m_shader->getUniformLocation("mySampler"), 0);

	m_sprite->draw();

	// Questo va ucciso ASAP
    glBindTexture(GL_TEXTURE_2D, 0);

	m_shader->disable();
}

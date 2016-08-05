#include "MainGame.h"

#include <iostream>
#include "Log.h"

#include "Video/Uniform.h"

MainGame::MainGame(const std::string& name, int width, int height)
	: GameCommon(name, width, height)
{
	Log::info("CALLED MainGame::MainGame");
}

MainGame::~MainGame()
{
	Log::info("CALLED MainGame::~MainGame");
}

void MainGame::init()
{
	m_sprite.push_back(new tewi::Video::Sprite(-1.0f, -1.0f, 1.0f, 1.0f, "textures/left_standing.png"));
	m_sprite.push_back(new tewi::Video::Sprite(0.0f, -1.0f, 1.0f, 1.0f, "textures/left_standing.png"));
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

	glActiveTexture(GL_TEXTURE0);
	tewi::Video::setUniform(m_shader->getUniformLocation("mySampler"), 0);

	for (const auto& v : m_sprite)
	{
		v->draw();
	}

    glBindTexture(GL_TEXTURE_2D, 0);

	m_shader->disable();
}

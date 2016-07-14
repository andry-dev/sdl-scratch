#include "MainGame.h"

#include <iostream>
#include "Log.h"

#include "Video/Uniform.h"


MainGame::MainGame(const std::string& name, int width, int height)
	: m_width(width), m_height(height), m_gameState(GameState::PLAY)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	Ensures(m_window != nullptr, "Window not initialized");

	SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
	Ensures(glContext != nullptr, "Context not initialized");

	int error = glewInit();
	Ensures(error == GLEW_OK, "Failed GLEW initialization");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	init();
}

MainGame::~MainGame()
{

}

void MainGame::init()
{
	m_sprite = std::make_unique<Sprite>(-1, -1, 1, 1);
	m_shader = std::make_unique<Shader>("shaders/shader.vert", "shaders/shader.frag");

	m_shader->addAttrib("vertexPos");
	m_shader->addAttrib("vertexCol");
	m_shader->link();

	gameLoop();
}

void MainGame::gameLoop()
{
	while (m_gameState != GameState::EXIT)
	{
		processInputs();
		m_time += 0.001;
		drawGame();
	}
}

void MainGame::processInputs()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				m_gameState = GameState::EXIT;
				break;
		}
	}
	
}

void MainGame::drawGame()
{
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_shader->enable();

	std::int32_t timeLoc = m_shader->getUniformLocation("time");
	setUniform(timeLoc, m_time);

	m_sprite->draw();
	m_shader->disable();

	SDL_GL_SwapWindow(m_window);
}

#include "../include/MainGame.h"
#include <iostream>

MainGame::MainGame(const std::string& name, int width, int height)
	: m_gameState(GameState::PLAY)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	init();
}

MainGame::~MainGame()
{

}

void MainGame::init()
{
	gameLoop();
}

void MainGame::gameLoop()
{
	while (m_gameState != GameState::EXIT)
	{
		processInputs();
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

			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " : " << evnt.motion.y << '\n';
				break;
		}
	}
	
}

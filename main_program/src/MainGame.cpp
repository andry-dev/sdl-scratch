#include <MainGame.h>

MainGame::MainGame(const std::string& name, int width, int height)
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

}

void MainGame::initInputs()
{

}

void MainGame::gameLoop()
{

}

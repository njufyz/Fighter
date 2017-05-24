#include "Game.h"
#include"MyPlane.h"

Game::Game()
{
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 0.0);
}

Game::~Game()
{
	delete myplane;
	delete screen;
}

void Game::Render()
{
	screen->render();
}

void Game::Clear()
{
	screen->clear();
}

void Game::update()
{
	myplane->render();
}



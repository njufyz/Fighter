#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

void Game::updatebullet()
{
	for (auto i = bullet.begin(); i != bullet.end(); i++)
	{
		(*i)->update();
		if ((*i)->isout())
		{
			auto j = i;
			i++;
			bullet.erase(j);
		}
	}
}

Game::Game()
{
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 0.0);
	enemy.push_back(new Enemy(0.0, 0.0, 0.0));
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

void Game::Update()
{
	myplane->setPos();
	GenerateBullet();
	myplane->render();

	//(*bullet.begin())->update();
	updatebullet();
}

void Game::GenerateBullet()
{
	//TODO: Enermy 
	bullet.push_back(new Bullet(myplane->PosX-2 , myplane->PosY, ME));
}



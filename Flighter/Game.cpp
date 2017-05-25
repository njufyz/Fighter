#include"Windows.h"
#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

void Game::updatebullet()
{
	for (auto i = bullet.begin(); i != bullet.end(); )
	{
		(*i)->update();
		if ((*i)->isout())
		{
			bullet.erase(i++);
		}
		else i++;
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
	//更新飞机位置
	myplane->setPos();
	
	//让所有子弹飞一会
	updatebullet();

	//按下鼠标 我方飞机发射子弹
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//所有的敌机发射子弹
	//generateEMBullet();

	//TODO: 碰撞检测 & 敌机更新

	//显示我方飞机
	myplane->render();

	//TODO：显示enable的敌机

	
}

void Game::generateMYBullet()
{
	bullet.push_back(new Bullet(myplane->PosX - planeSizeX , myplane->PosY, ME));
}

void Game::generateEMBullet()
{
	for (auto i = enemy.begin(); i != enemy.end(); i++)
		bullet.push_back(new Bullet((*i)->PosX + planeSizeX, (*i)->PosY, EM));
}



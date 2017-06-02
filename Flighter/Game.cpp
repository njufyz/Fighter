#include"Windows.h"
#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

void Game::updatebullet()
{
	for (auto i = bullet.begin(); i != bullet.end(); )
	{
		(*i)->move();					//移动子弹
		if ((*i)->isout())				//飞出去了
		{
			bullet.erase(i++);
		}
		else i++;
	}
}

void Game::updatenemy()
{
	for (auto i = enemy.begin(); i != enemy.end(); )
	{
		(*i)->move();						//移动飞机
		if ((*i)->isout())					//飞出去了
		{
			enemy.erase(i++);
		}
		else i++;
	}
}

void Game::render()
{
	myplane->render();					//画我方飞机
	for (auto i : enemy)
		i->render();							//画敌方飞机
	for (auto i : bullet)
		i->render();							//画子弹
}

Game::Game()
{
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 10.0);
	for (int i = 0; i < 5; i++)
	{
		//先产生5架敌机
		enemy.push_back(new Enemy(0.0, rand()%80, 3.0, 1.0));
	}

}

Game::~Game()
{
	delete myplane;
	delete screen;
}

void Game::Render()
{
	//写入屏幕
	screen->render();
}

void Game::Clear()
{
	screen->clear();
}

//更新战场
void Game::Update()
{
	//更新飞机位置
	myplane->setPos();
	//添加低级
	generateEMplane();

	//让所有子弹飞一会
	updatebullet();
	updatenemy();

	//按下鼠标 我方飞机发射子弹
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//所有的敌机发射子弹
	generateEMBullet();

	//TODO: 碰撞检测 & 敌机更新

	//显示战场
	render();

	
}

//添加我方子弹
void Game::generateMYBullet()
{
	bullet.push_back(new Bullet(myplane->PosX - planeSizeX , myplane->PosY, ME));
}

//添加敌机子弹
void Game::generateEMBullet()
{
	if (game_time % 5 == 0)
	{
		for (auto i = enemy.begin(); i != enemy.end() && (*i)->isin(); i++)
			bullet.push_back(new Bullet((*i)->PosX + planeSizeX, (*i)->PosY, EM));
	}
}

//产生地方飞机
void Game::generateEMplane()
{
	if (game_time % 25 == 0)
		//某一部分随机产生飞机，可能位于屏幕上方
		enemy.push_back(new Enemy(rand()%10 - 10, rand() % 80, 3.0, 1.0));
}

void Game::collidewithmyplane()
{
	for (auto i : bullet)
	{
		if (i->type == EM)
		{

		}
	}
}

void init()
{

}



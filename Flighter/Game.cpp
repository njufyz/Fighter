#include<Windows.h>
#include<string>
#include <stdio.h>
#include<memory>
#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

int bullet_freq = 5;
int enemy_freq = 20;

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
			miss++;
		}
		else i++;
	}
}

void Game::updateboard()
{
	int score = this->scores;
	screen->writeboard(score, miss, myplane->HP);
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

}

Game::~Game()
{
	delete myplane;
	delete screen;
}

void Game::Init()
{
	scores = 0;
	miss = 0;

	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 5.0);
	for (int i = 0; i < 5; i++)
	{
		//先产生5架敌机
		shared_ptr<Enemy> ptr(new Enemy(0.0, rand() % BattleWidth, 1.0, 1.0));
		enemy.push_back(ptr);
	}
	game_stat = PLAY;
}

void Game::Replay()
{
	scores = 0;
	miss = 0;

	delete screen;
	delete myplane;
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 5.0);

	enemy.clear();
	bullet.clear();

	for (int i = 0; i < 5; i++)
	{
		//先产生5架敌机
		shared_ptr<Enemy> ptr(new Enemy(0.0, rand() % BattleWidth, 1.0, 1.0));
		enemy.push_back(ptr);
	}
	game_stat = PLAY;
}

//写入屏幕
void Game::Render()
{
	screen->render();
}

//清空屏幕
void Game::Clear()
{
	screen->clear();
}

//更新战场
void Game::Update()
{
	//更新飞机位置
	myplane->setPos();

	//添加敌机
	generateEMplane();

	//让所有子弹飞一会
	updatebullet();

	//让敌机飞一会
	updatenemy();

	//按下鼠标 我方飞机发射子弹
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//所有的敌机发射子弹
	generateEMBullet();

	//碰撞检测
	collide_with_myplane();
	collide_with_enemy();
	enemy_collide_with_myplane();

	//更新分数
	updateboard();

	//显示战场
	render();

}

bool Game::Die()
{
	
	game_stat = REPLAY;
	return screen->messagebox();
}

void Game::Cls()
{
	screen->cls();
}

//添加我方子弹
void Game::generateMYBullet()
{
	shared_ptr<Bullet> ptr(new Bullet(myplane->PosX - planeSizeX, myplane->PosY, ME));
	bullet.push_front(ptr);
}

//添加敌机子弹
void Game::generateEMBullet()
{
	if (game_time % bullet_freq == 0)
	{
		for (auto i = enemy.begin(); i != enemy.end() && (*i)->isin(); i++)
		{
			shared_ptr<Bullet> ptr(new Bullet((*i)->PosX + planeSizeX, (*i)->PosY, EM));
			bullet.push_front(ptr);
		}
	}
}

//产生敌方飞机
void Game::generateEMplane()
{
	if (game_time % enemy_freq == 0)
		//随机产生飞机，位于屏幕上方，从上向下飞向战场
	{
		shared_ptr<Enemy> ptr(new Enemy(rand() % 10 - 10, rand() % BattleWidth, 1.0, 2.0));
		enemy.push_back(ptr);
	}
}


//敌机子弹与我方飞机碰撞
void Game::collide_with_myplane()
{
	for (auto i : bullet)
	{
		if (i->type == EM)
		{
			int x = i->x, y = i->y;
			int posx = myplane->PosX, posy = myplane->PosY;

			if ((x == posx - 1) && (y == posy - 1)
				|| (x == posx - 1) && (y == posy)
				|| (x == posx - 1) && (y == posy + 1)
				|| (x == posx) && (y == posy - 1)
				|| (x == posx) && (y == posy)
				|| (x == posx) && (y == posy + 1))
				
				myplane->HP--;				//血量减少

			if (myplane->HP <= 0)
				game_stat = DIE;				//DIE
		}
	}
}


//敌方飞机和我方子弹相撞
void Game::collide_with_enemy()
{
	for (auto i : bullet)
	{
		if (i->type == ME)
		{
			for (auto j = enemy.begin(); j!=enemy.end();  )
			{
				int x = i->x, y = i->y;
				int posx = (*j)->PosX, posy = (*j)->PosY;

				if ((x == posx + 1) && (y == posy - 1)
					|| (x == posx + 1) && (y == posy)
					|| (x == posx + 1) && (y == posy + 1)
					|| (x == posx) && (y == posy - 1)
					|| (x == posx) && (y == posy)
					|| (x == posx) && (y == posy + 1))
					
				{
					(*j)->HP -=1;
					if ((*j)->HP <=0)
						enemy.erase(j++);						//飞机死掉
					scores += 25;
				}
				else 
					j++;	
			}
		}
	}
}

//敌机与我方飞机相撞
void Game::enemy_collide_with_myplane()
{
	int posx = myplane->PosX, posy = myplane->PosY;
	for (auto i : enemy)
	{
		int x = i->PosX, y = i->PosY;
		if ((x == posx - 2 && y == posy - 2)
			|| (x == posx - 2 && y == posy - 1)
			|| (x == posx - 2 && y == posy)
			|| (x == posx - 2 && y == posy + 1)
			|| (x == posx - 2 && y == posy + 2))
		{
			game_stat = DIE;
			myplane->HP = 0;
		}
	}
}



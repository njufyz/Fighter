#include<Windows.h>
#include<iostream>
#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

void Game::updatebullet()
{
	for (auto i = bullet.begin(); i != bullet.end(); )
	{
		(*i)->move();					//�ƶ��ӵ�
		if ((*i)->isout())				//�ɳ�ȥ��
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
		(*i)->move();						//�ƶ��ɻ�
		if ((*i)->isout())					//�ɳ�ȥ��
		{
			enemy.erase(i++);
			miss++;
		}
		else i++;
	}
}

void Game::render()
{
	myplane->render();					//���ҷ��ɻ�
	for (auto i : enemy)
		i->render();							//���з��ɻ�
	for (auto i : bullet)
		i->render();							//���ӵ�
}

Game::Game()
{
	scores = 0;
	miss = 0;

	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 5.0);
	for (int i = 0; i < 5; i++)
	{
		//�Ȳ���5�ܵл�
		enemy.push_back(new Enemy(0.0, rand()% BattleWidth, 1.0, 1.0));
	}

}

Game::~Game()
{
	delete myplane;
	delete screen;
}

//д����Ļ
void Game::Render()
{
	screen->render();
}

//�����Ļ
void Game::Clear()
{
	screen->clear();
}

//����ս��
void Game::Update()
{
	//���·ɻ�λ��
	myplane->setPos();

	//��ӵл�
	generateEMplane();

	//�������ӵ���һ��
	updatebullet();
	updatenemy();

	//������� �ҷ��ɻ������ӵ�
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//���еĵл������ӵ�
	//generateEMBullet();

	//��ײ���
	collide_with_myplane();
	collide_with_enemy();
	enemy_collide_with_myplane();

	//��ʾս��
	render();

}

void Game::WriteScores()
{
	std::cout << scores << endl;
	std::cout << miss << endl;
}

//����ҷ��ӵ�
void Game::generateMYBullet()
{
	bullet.push_back(new Bullet(myplane->PosX - planeSizeX , myplane->PosY, ME));
}

//��ӵл��ӵ�
void Game::generateEMBullet()
{
	if (game_time % 5 == 0)
	{
		for (auto i = enemy.begin(); i != enemy.end() && (*i)->isin(); i++)
			bullet.push_back(new Bullet((*i)->PosX + planeSizeX, (*i)->PosY, EM));
	}
}

//�����з��ɻ�
void Game::generateEMplane()
{
	if (game_time % 25 == 0)
		//��������ɻ���λ����Ļ�Ϸ����������·���ս��
		enemy.push_back(new Enemy(rand()%10 - 10, rand() % BattleWidth, 1.0, 2.0));
}


//�л��ӵ����ҷ��ɻ���ײ
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
				
				myplane->HP--;				//Ѫ������

			if (myplane->HP <= 0)
				game_stat = DIE;				//DIE
		}
	}
}

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
						enemy.erase(j++);						//�ɻ�����
					scores += 25;
				}
				else 
					j++;	
			}
		}
	}
}

//�л����ҷ��ɻ���ײ
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
			game_stat = DIE;
	}
}


void init()
{
	memset(ori_screen, ' ', ScreenHeight * ScreenWidth);
	for (int i = 0; i < ScreenHeight; i++)
		ori_screen[i][BattleWidth] = '|';
}



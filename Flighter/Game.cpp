#include"Windows.h"
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
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 5.0);
	for (int i = 0; i < 5; i++)
	{
		//�Ȳ���5�ܵл�
		enemy.push_back(new Enemy(0.0, rand()%80, 2.0, 1.0));
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
	generateEMBullet();

	//TODO: ��ײ��� & �л�����
	collide_with_myplane();
	collide_with_enemy();

	//��ʾս��
	render();

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

//�����ط��ɻ�
void Game::generateEMplane()
{
	if (game_time % 25 == 0)
		//ĳһ������������ɻ�������λ����Ļ�Ϸ�
		enemy.push_back(new Enemy(rand()%10 - 10, rand() % 80, 3.0, 1.0));
}

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

				myplane->HP--;
			if (myplane->HP <= 0)
				game_stat = DIE;
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

					enemy.erase(j++);
				
				else 
					j++;	
			}
		}
	}
}


//void init()
//{
//
//}



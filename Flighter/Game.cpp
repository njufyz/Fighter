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
	myplane = new MyPlane(0.0, 0.0, 10.0);
	for (int i = 0; i < 5; i++)
	{
		//�Ȳ���5�ܵл�
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
	//д����Ļ
	screen->render();
}

void Game::Clear()
{
	screen->clear();
}

//����ս��
void Game::Update()
{
	//���·ɻ�λ��
	myplane->setPos();
	//��ӵͼ�
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



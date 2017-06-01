#include"Windows.h"
#include "Game.h"
#include"MyPlane.h"
#include"Enemy.h"

void Game::updatebullet()
{
	for (auto i = bullet.begin(); i != bullet.end(); )
	{
		(*i)->move();
		if ((*i)->isout())
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
		(*i)->move();
		if ((*i)->isout())
		{
			enemy.erase(i++);
		}
		else i++;
	}
}

void Game::render()
{
	myplane->render();
	for (auto i : enemy)
		i->render();
	for (auto i : bullet)
		i->render();
}

Game::Game()
{
	screen = new Screen;
	myplane = new MyPlane(0.0, 0.0, 0.0);
	for (int i = 0; i < 5; i++)
	{
		enemy.push_back(new Enemy(0.0, 25.0, 3.0, 1.0));
		enemy.push_back(new Enemy(0.0, 5.0, 3.0, 1.0));
		enemy.push_back(new Enemy(0.0, 40.0, 3.0, 1.0));
		enemy.push_back(new Enemy(0.0, 67.0, 3.0, 1.0));
		enemy.push_back(new Enemy(0.0, 56.0, 3.0, 1.0));
	}

}

Game::~Game()
{
	delete myplane;
	delete screen;
}

void Game::Render()
{
	render();
	screen->render();
}

void Game::Clear()
{
	screen->clear();
}

void Game::Update()
{
	//���·ɻ�λ��
	myplane->setPos();
	
	//�������ӵ���һ��
	updatebullet();
	updatenemy();

	//������� �ҷ��ɻ������ӵ�
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//���еĵл������ӵ�
	generateEMBullet();

	//TODO: ��ײ��� & �л�����

	//��ʾ�ҷ��ɻ�
	render();

	//TODO����ʾenable�ĵл�
	
}

void Game::generateMYBullet()
{
	bullet.push_back(new Bullet(myplane->PosX - planeSizeX , myplane->PosY, ME));
}

void Game::generateEMBullet()
{
	for (auto i = enemy.begin(); i != enemy.end() && (*i)->isin(); i++)
		bullet.push_back(new Bullet((*i)->PosX + planeSizeX, (*i)->PosY, EM));
}



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
	//���·ɻ�λ��
	myplane->setPos();
	
	//�������ӵ���һ��
	updatebullet();

	//������� �ҷ��ɻ������ӵ�
	if(KEYDOWN(VK_LBUTTON))
		generateMYBullet();

	//���еĵл������ӵ�
	//generateEMBullet();

	//TODO: ��ײ��� & �л�����

	//��ʾ�ҷ��ɻ�
	myplane->render();

	//TODO����ʾenable�ĵл�

	
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



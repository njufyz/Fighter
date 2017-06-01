#include"common.h"
#include"Game.h"
#include "Bullet.h"
#include"MyPlane.h"

void Bullet::render()
{
	if (enable)
	{
		//�ӵ���ʽ��һ��
		if(type == ME)
			game.screen->writechar('*', (int)x, (int)y);
		else
			game.screen->writechar('.', (int)x, (int)y);
	}
}

void Bullet::setPos()
{
	//Ϊ�ҷ��ɻ���λ
	x = game.myplane->PosX - 2;
	y = game.myplane->PosY;
}


void Bullet::move()
{
	//�ƶ��ӵ�
	x += velocity;
	if (isout())					//�ɳ�ȥ��
		enable = false;		
}

bool Bullet::isout()
{
	if (x <= 0 || x >= ScreenHeight)
		return true;
	return false;
}

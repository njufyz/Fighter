#include"common.h"
#include"Game.h"
#include "Bullet.h"
#include"MyPlane.h"

void Bullet::render()
{
	if (enable)
	{
		//�ӵ���ʽ��һ��
		CHAR_INFO c[2];
		
		c[0].Attributes = FOREGROUND_RED | FOREGROUND_INTENSITY;
		c[1].Attributes = FOREGROUND_INTENSITY | 0;
		c[0].Char.UnicodeChar = '*';
		c[1].Char.UnicodeChar = '.';

		if(type == ME)
			game.screen->writechar(c[0], (int)x, (int)y);
		else
			game.screen->writechar(c[1], (int)x, (int)y);
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

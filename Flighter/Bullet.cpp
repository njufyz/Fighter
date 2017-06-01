#include"common.h"
#include"Game.h"
#include "Bullet.h"
#include"MyPlane.h"

void Bullet::render()
{
	if (enable)
	{
		//子弹样式不一样
		if(type == ME)
			game.screen->writechar('*', (int)x, (int)y);
		else
			game.screen->writechar('.', (int)x, (int)y);
	}
}

void Bullet::setPos()
{
	//为我方飞机定位
	x = game.myplane->PosX - 2;
	y = game.myplane->PosY;
}


void Bullet::move()
{
	//移动子弹
	x += velocity;
	if (isout())					//飞出去了
		enable = false;		
}

bool Bullet::isout()
{
	if (x <= 0 || x >= ScreenHeight)
		return true;
	return false;
}

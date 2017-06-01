#include"common.h"
#include"Game.h"
#include "Bullet.h"
#include"MyPlane.h"

void Bullet::render()
{
	if (enable)
	{
		if(type == ME)
			game.screen->writechar('*', (int)x, (int)y);
		else
			game.screen->writechar('.', (int)x, (int)y);
	}
}

void Bullet::setPos()
{
	x = game.myplane->PosX - 2;
	y = game.myplane->PosY;
}


void Bullet::move()
{
	x += velocity;
	if (isout())
		enable = false;		
}

bool Bullet::isout()
{
	if (x <= 0 || x >= ScreenHeight)
		return true;
	return false;
}

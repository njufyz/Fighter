#include "Enemy.h"
#include"Game.h"

bool Enemy::isout()
{
	if (PosX >= ScreenHeight)
		return true;
	return false;
}

bool Enemy::isin()
{
	if (PosX <= 0 || PosX >= ScreenHeight)
		return false;
	return true;
}

void Enemy::move()
{
	if (game_time % 5 == 0)
	{
		PosX += velocity;
		if (isout())
			enable = false;
		else
			enable = true;
	}
}

void Enemy::render()
{
	if (!enable) return;

	int x = (int)PosX;
	int y = (int)PosY;

	game.screen->writechar('#', x, y);
	game.screen->writechar('$', x + 1, y);

	game.screen->writechar('#', x, y + 1);
	
	game.screen->writechar('#', x, y - 1);
	
}

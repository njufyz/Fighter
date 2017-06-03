#include "Enemy.h"
#include"Game.h"

int hard = 1;
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

	CHAR_INFO c[2];
	for (int i = 0; i<2; i++)
		c[i].Attributes = FOREGROUND_INTENSITY | 0;
	c[0].Char.UnicodeChar = '#';
	c[1].Char.UnicodeChar = '$';

	game.screen->writechar(c[0], x, y);
	game.screen->writechar(c[1], x + 1, y);

	game.screen->writechar(c[0], x, y + 1);
	
	game.screen->writechar(c[0], x, y - 1);
	
}

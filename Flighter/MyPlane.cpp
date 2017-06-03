#include "MyPlane.h"
#include"Game.h"
#include<Windows.h>
#include<stdio.h>

/*
char ImagePlanePlayer[planeSizeX][planeSizeY] =
{
	{ '.',	'|',		'.' },
	{ '^',	'^',	'^' },
};
*/

void MyPlane::render()
{
	int x = (int)PosX;
	int y = (int)PosY;

	//TODO:
	CHAR_INFO c[5];
	for (int i = 0; i<5; i++)
		c[i].Attributes = FOREGROUND_RED  |FOREGROUND_INTENSITY;

	c[0].Char.UnicodeChar = '=';
	c[1].Char.UnicodeChar = '|';
	c[2].Char.UnicodeChar = '<';
	c[3].Char.UnicodeChar = '$';
	c[4].Char.UnicodeChar = '>';

	game.screen->writechar(c[0], x, y);
	game.screen->writechar(c[1], x - 1, y);

	game.screen->writechar(c[2], x, y + 1);
	game.screen->writechar(c[3], x - 1, y + 1);

	game.screen->writechar(c[4], x, y - 1);
	game.screen->writechar(c[3], x - 1, y - 1);
	
}
void MyPlane::setPos()
{
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标

	PosX = point.y >> 4;
	PosY = point.x >> 3;

	if (PosX >= BattleHeight)	PosX = BattleHeight - 1;
	if (PosX <= 0)						PosX = 1;
	if (PosY >= BattleWidth)   PosY = BattleWidth - 1;
	if (PosY <= 0)						PosY = 0;
	
}
	



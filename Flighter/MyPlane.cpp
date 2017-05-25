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
	game.screen->writechar('^', x, y);
	game.screen->writechar('|', x - 1, y);

	game.screen->writechar('^', x, y + 1);
	game.screen->writechar('$', x - 1, y + 1);

	game.screen->writechar('^', x, y - 1);
	game.screen->writechar('$', x - 1, y - 1);
	
}
void MyPlane::setPos()
{
	POINT point;
	GetCursorPos(&point);
	HWND hWnd = GetConsoleWindow();
	ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标

	PosX = point.y >> 4;
	PosY = point.x >> 3;
}
	



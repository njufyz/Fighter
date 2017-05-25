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
	/*POINT point;
	GetCursorPos(&point);
	HWND hWnd = GetConsoleWindow();
	ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标
	
	PosX = point.y >> 4;
	PosY = point.x >> 3;
	*/
	int x = (int)PosX;
	int y = (int)PosY;
	game.screen->writechar('^', x, y);
	game.screen->writechar('|', x - 1, y);

	game.screen->writechar('^', x, y + 1);
	game.screen->writechar('o', x - 1, y + 1);

	game.screen->writechar('^', x, y - 1);
	game.screen->writechar('o', x - 1, y - 1);
	
}
//	game.screen->writechar('b', point.y >> 4, point.x >> 3);
	
//	game.screen->writechar('b', point.y >> 4, (point.x >> 3)+1);
	



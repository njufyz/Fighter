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
	POINT point;
	GetCursorPos(&point);
	HWND hWnd = GetConsoleWindow();
	ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标
	
	PosX = point.y >> 4;
	PosY = point.x >> 3;
	
	game.screen->writechar('^', (point.y >> 4), (point.x >> 3));
	game.screen->writechar('|', (point.y >> 4)-1, (point.x >> 3));

	game.screen->writechar('^', (point.y >> 4), (point.x >> 3)+1);
	game.screen->writechar('o', (point.y >> 4)-1, (point.x >> 3)+1);

	game.screen->writechar('^', (point.y >> 4), (point.x >> 3)-1);
	game.screen->writechar('o', (point.y >> 4)-1, (point.x >> 3)-1);
	
}
//	game.screen->writechar('b', point.y >> 4, point.x >> 3);
	
//	game.screen->writechar('b', point.y >> 4, (point.x >> 3)+1);
	



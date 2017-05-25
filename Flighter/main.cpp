#include"common.h"
#include"Screen.h"
#include "Game.h"
#include<Windows.h>
#include<stdio.h>

Game game;
int main()
{

//	Screen s;
	system("MODE con: COLS=80 LINES=40");
	while (1)
	{
	/*	Screen s;
		POINT point;
		::GetCursorPos(&point);
		HWND hWnd = GetConsoleWindow();
		ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标
	//printf("x=%d,y=%d\n", point.y>>4, point.x>>3);
		s.clear();
		//s.writechar('a', point.x >> 3, point.y >> 4);
		s.writechar('a', 39, 78);
		s.render();
		*/
		game.Clear();
		game.Update();
		game.Render();
		Sleep(30);
	}
	
}



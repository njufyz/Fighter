#include"Screen.h"
#include"Plane.h"
#include"common.h"
#include<stdio.h>
#include<Windows.h>

inline bool isInScr(int x, int y)
{
	return (x >= 0) && (x < BattleHeight) && (y >= 0) && (y < BattleWidth);
}

Screen::Screen()
{
	memset(screen, ' ', ScreenHeight * ScreenWidth);
	for (int i = 0; i < ScreenHeight; i++)
		screen[i][BattleWidth] = '|';

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);	//获取控制台光标信息  
	CursorInfo.bVisible = false;								//隐藏控制台光标  
	SetConsoleCursorInfo(hOut, &CursorInfo);	//设置控制台光标状态
}

void Screen::clear()
{
	system("cls");
	memset(screen, ' ', ScreenHeight * ScreenWidth);
	for (int i = 0; i < ScreenHeight; i++)
		screen[i][BattleWidth] = '|';
}

void Screen::render()
{
	//COORD consoleCursor;
	//char data;
	//for (int i = 0; i<ScreenHeight; i++)
	//{
	//	for (int j = 0; j < ScreenWidth; j++)
	//	{
	//		if (screen[i][j] != ' ')
	//		{
	//			consoleCursor.X = j;
	//			consoleCursor.Y = i;
	//			SetConsoleCursorPosition(hOut, consoleCursor);
	//			printf("%c", screen[i][j]);
	//		}
	//	}
	//}
	COORD consoleCursor;
	consoleCursor.X = 0;
	DWORD bytes = 0;
	for (int i = 0; i<ScreenHeight; i++)
	{
		consoleCursor.Y = i;
		WriteConsoleOutputCharacterA(hOut, screen[i], BattleWidth + 1, consoleCursor, &bytes);
	}
	
}

void Screen::writechar(char c, int x, int y)
{
	if(isInScr(x, y))
		screen[x][y] = c;
}



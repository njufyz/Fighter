#include"Screen.h"
#include"Plane.h"
#include<stdio.h>
#include<Windows.h>
#include<assert.h>

inline bool isInScr(int x, int y)
{
	return (x >= 0) && (x < ScreenHeight) && (y >= 0) && (y < ScreenWidth);
}

Screen::Screen()
{
	memset(screen, ' ', BattleHeight * BattleWidth);
}

void Screen::clear()
{
	system("cls");
	memset(screen, ' ', BattleHeight * BattleWidth);
}

void Screen::render()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(hOut, &CursorInfo);//设置控制台光标状态

	for (int i = 0; i<ScreenHeight; i++)
	{
		for (int j = 0; j < ScreenWidth; j++)
		{
			if (screen[i][j] != ' ')
			{
				COORD consoleCursor;
				consoleCursor.X = j;
				consoleCursor.Y = i;
				SetConsoleCursorPosition(hOut, consoleCursor);
				printf("%c", screen[i][j]);
			}
		}

	}
}

void Screen::writechar(char c, int x, int y)
{
	if(isInScr(x, y))
		screen[x][y] = c;
//	else assert(0);
}

void Screen::writeplane(Plane * plane)
{
	plane->render();
}



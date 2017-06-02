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
	//memset(screen, ' ', ScreenHeight * ScreenWidth);
	memcpy(screen, ori_screen, ScreenHeight * ScreenWidth);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);	//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false;								//���ؿ���̨���  
	SetConsoleCursorInfo(hOut, &CursorInfo);	//���ÿ���̨���״̬

}

void Screen::clear()
{
	system("cls");
	memset(screen, ' ', ScreenHeight * ScreenWidth);
	//memcpy(screen, ori_screen, ScreenHeight * ScreenWidth);
	for (int i = 0; i < ScreenHeight; i++)
		screen[i][BattleWidth] = '|';
}

void Screen::render()
{
	
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
}



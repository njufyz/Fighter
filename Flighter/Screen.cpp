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
	cls();
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOut, &CursorInfo);	

	//���ؿ���̨���  
	CursorInfo.bVisible = false;				

	SetConsoleCursorInfo(hOut, &CursorInfo);	

}

void Screen::clear()
{
	system("cls");
	cls();
}

void Screen::render()
{
	//һ����д����Ļ
	COORD dwBufferSize = { ScreenWidth, ScreenHeight };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rect = { 0, 0,  ScreenWidth, ScreenHeight };
	WriteConsoleOutput(hOut, (CHAR_INFO*)screen, dwBufferSize, dwBufferCoord, &rect);
}

void Screen::writechar(CHAR_INFO c, int x, int y)
{
	if(isInScr(x, y))
		screen[x][y] = c;
}

void Screen::writeboard()
{

}


//��ջ�����
void Screen::cls()
{
	CHAR_INFO c;
	c.Attributes = FOREGROUND_INTENSITY | 0;
	c.Char.UnicodeChar = ' ';

	memset(screen, ' ', ScreenHeight * ScreenWidth);

	for (int i = 0; i < ScreenHeight; i++)
		for (int j = 0; j < ScreenWidth; j++)
			screen[i][j] = c;
	c.Char.UnicodeChar = '|';

	for (int i = 0; i < ScreenHeight; i++)
		screen[i][BattleWidth] = c;
}



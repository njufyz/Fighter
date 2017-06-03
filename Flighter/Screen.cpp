#include"Screen.h"
#include"Plane.h"
#include"common.h"
#include"Game.h"
#include<stdio.h>
#include<string>
#include<sstream>
#include<assert.h>
#include<iostream>
#include<Windows.h>
using namespace std;

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

	//隐藏控制台光标  
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
	//一次性写入屏幕
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

void Screen::writeboard(int scores, int Miss, float hp)
{
	string score, miss;
	stringstream ss;
	string str[9] = {
		"Guideline: ",
		"Move your mouse to control the flight.",
		"Click your mouse to fire. ",
		"Crashed with enemy, YOU WILL DIE!",
		"Good luck, Captain!",
		"Scores: ",
		"HP:",
		"Miss:",
		"Level:"
	};
	CHAR_INFO c;
	c.Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	int i = 0;

	ss << scores;
	ss >> score;
	ss.clear();
	ss << Miss;
	ss >> miss;

	//guideline
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i+5][81 + j] = c;
	}

	//move and click
	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i + 6][81 + j] = c;
	}
	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i + 7][81 + j] = c;
	}
	//crash

	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Attributes = FOREGROUND_RED | FOREGROUND_INTENSITY;
		c.Char.UnicodeChar = str[i][j];
		screen[i + 8][81 + j] = c;
	}

	i++;
	//good locl
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Attributes = FOREGROUND_RED | FOREGROUND_INTENSITY;
		c.Char.UnicodeChar = str[i][j];
		screen[i + 9][81 + j] = c;
	}
	
	c.Attributes = FOREGROUND_INTENSITY;
	//score
	i++;
	for (int j = 0; j < score.size(); j++)
	{
		c.Char.UnicodeChar = score[j];
		screen[i+19][89 + j] = c;
	}

	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i+19][81 + j] = c;
	}

	//hp
	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i + 20][81 + j] = c;
	}

	//c.Char.UnicodeChar = '■';
	c.Attributes = FOREGROUND_GREEN | COMMON_LVB_GRID_HORIZONTAL| COMMON_LVB_UNDERSCORE | FOREGROUND_INTENSITY;
	//c.Attributes= FOREGROUND_INTENSITY;
	for (int j = 0; j < 10; j++)
	{

		if (hp <= 3)
			c.Attributes = FOREGROUND_RED | COMMON_LVB_GRID_HORIZONTAL | COMMON_LVB_UNDERSCORE | FOREGROUND_INTENSITY;
	
		if (j == 0)
			c.Attributes |= COMMON_LVB_GRID_LVERTICAL;
		else c.Attributes &= 0xf4ff;

		if(j < 2 * hp)
			c.Char.UnicodeChar = '#';   //■
		else c.Char.UnicodeChar = ' ';

		if (j == 9)
			c.Attributes |= COMMON_LVB_GRID_RVERTICAL;
		
		screen[i+20][85 +  j] = c;
	}

	//miss
	c.Attributes = FOREGROUND_INTENSITY   |FOREGROUND_INTENSITY;
	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i + 21][81 + j] = c;
	}
	for (int j = 0; j < miss.size(); j++)
	{
		c.Char.UnicodeChar = miss[j];
		screen[i + 21][89 + j] = c;
	}

	//level
	i++;
	for (int j = 0; j < str[i].size(); j++)
	{
		c.Char.UnicodeChar = str[i][j];
		screen[i+22][81 + j] = c;
	}
	string level[2] = {
		"Elite",
		"Easy" };
	if (sleep_time != 70)
	{
		for (int j = 0; j < level[0].size(); j++)
		{
			c.Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
			c.Char.UnicodeChar = level[0][j];
			screen[i + 22][89 + j] = c;
		}
	}
	else
	{
		for (int j = 0; j < level[1].size(); j++)
		{
			c.Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			c.Char.UnicodeChar = level[1][j];
			screen[i + 22][89 + j] = c;
		}
	}

}

bool Screen::messagebox()
{
	int id = MessageBox(NULL, TEXT("Your flight was hit!!!\nPlay again, Captain?"), TEXT("SpaceWar"), MB_ICONWARNING |MB_YESNO);
	if (id == IDYES)
		return true;
	else return false;
	
}


//清空缓存区
void Screen::cls()
{
	CHAR_INFO c;
	c.Attributes = FOREGROUND_INTENSITY | 0;
	c.Char.UnicodeChar = ' ';

	for (int i = 0; i < ScreenHeight; i++)
		for (int j = 0; j < ScreenWidth; j++)
			screen[i][j] = c;

	c.Char.UnicodeChar = '|';
	for (int i = 0; i < ScreenHeight; i++)
		screen[i][BattleWidth] = c;

	c.Char.UnicodeChar = '-';
	for (int i = 0; i < BoardWidth - 1; i++)
		screen[19][i+81] = c;
}



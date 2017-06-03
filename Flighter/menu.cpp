#include"common.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;


void SetPos(int i, int j)// set cursor
{
	COORD pos = { i, j };
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)
		cout << ch;
}

void drawCol(int x, int y1, int y2, char ch)
{
	int y = y1;
	while (y < y2 + 1)
	{
		SetPos(x, y);
		cout << ch;
		y++;
	}
}

int drawMenu()
{
	system("cls");
	system("MODE con: COLS=80 LINES=40");
	SetConsoleTitle(TEXT("SpaceWar"));
	HideCursor();
	SetPos(30, 1);
	cout << "Space  War";
	drawRow(3, 0, 79, '=');
	drawRow(7, 0, 79, '=');

	SetPos(28, 5);
	cout << "↑ 和 ↓ 选择， Enter 确定";
	SetPos(25, 11);
	cout << "1. 简单模式";
	SetPos(25, 13);
	cout << "2. 冷酷模式";
	drawRow(20, 0, 79, '-');
	drawRow(22, 0, 79, '-');
	
	SetPos(25, 18);
	cout << "简单模式：";
	SetPos(38, 18);
	cout << "敌机移动速度较慢";
	
	int j = 11;
	SetPos(22, j);
	cout << ">>";
	int mood = 0;
	while (1)
	{
		if(KEYDOWN(VK_UP))
		{	
			if (j == 13)
				{
					mood = 0;
					SetPos(22, j);
					cout << "　";
					j = 11;
					SetPos(22, j);
					cout << ">>";
			
					SetPos(25, 18);
					cout << "简单模式：";
					SetPos(38, 18);
					cout << "敌机移动速度较慢";
				}
		continue;
		}
		if(KEYDOWN(VK_DOWN))
			{
				if (j == 11)
				{
					mood = 1;
					SetPos(22, j);
					cout << "　";
					j = 13;
					SetPos(22, j);
					cout << ">>";
				
					SetPos(25, 18);
					cout << "冷酷模式：";
					SetPos(38, 18);
					cout << "敌机移动速度较快";
				}
				continue;
			}
		if(KEYDOWN(VK_RETURN))
			{
			if (mood == 0)
			{
				sleep_time = 70;
				bullet_freq = 5;
				enemy_freq = 20;
			}
			else 
			{
				sleep_time = 40;
				bullet_freq = 2;
				enemy_freq = 13;
			}
			break;
			}
			
		}
	return 0;
}
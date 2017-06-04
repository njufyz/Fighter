#include"common.h"
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

void displaymessage();

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
	SetPos(34, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Space  War";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

	drawRow(3, 0, 79, '=');
	drawRow(7, 0, 79, '=');

	SetPos(25, 5);
	cout << "↑ 和 ↓ 选择， Enter 确定";
	SetPos(25, 11);
	cout << "1. 简单模式";
	SetPos(25, 13);
	cout << "2. 冷酷模式";
	drawRow(20, 0, 79, '-');
	drawRow(22, 0, 79, '-');
	
	SetPos(20, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "简单模式：";
	SetPos(30, 18);
	cout << "敌机移动速度较慢，密度小， 射速慢";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	
	int j = 11;
	SetPos(22, j);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << ">>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	int mood = 0;
	while (1)
	{
		if(KEYDOWN(VK_UP))
		{	
			if (j == 13)
				{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
					mood = 0;
					SetPos(22, j);
					cout << "　";
					j = 11;
					SetPos(22, j);
					cout << ">>";
			
					SetPos(20, 18);
					cout << "简单模式：";
					SetPos(30, 18);
					cout << "敌机移动速度较慢,，密度小，射速慢";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				}
		continue;
		}
		if(KEYDOWN(VK_DOWN))
			{
				if (j == 11)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
					mood = 1;
					SetPos(22, j);
					cout << "　";
					j = 13;
					SetPos(22, j);
					cout << ">>";
				
					SetPos(20, 18);
					cout << "冷酷模式：";
					SetPos(30, 18);
					cout << "敌机移动速度较快，密度大， 射速快";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
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
	displaymessage();
	return 0;
}

void displaymessage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED|FOREGROUND_INTENSITY);
	string message[7] = {
		"-----: Captain！ Enemies ahead!",
		"-----: Don't worry. ",
		"       We will destroy them.",
		"       Savvy?",
		"-----: Aye!",
		"Press Enter to fight!!!",
		"(鼠标操纵飞机， 左键射击, 关闭快速编辑模式以获得最佳效果)"
	};
	SetPos(22, 25);
	cout << message[0];
	Sleep(1000);

	SetPos(22, 27);
	cout << message[1];
	Sleep(1000);

	SetPos(22, 28);
	cout << message[2];
	Sleep(1000);

	SetPos(22, 29);
	cout << message[3];
	Sleep(1000);

	SetPos(22, 31);
	cout << message[4];
	Sleep(1000);

	SetPos(22, 33);
	cout << message[5];

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	SetPos(11, 35);
	cout << message[6];


	while (!KEYDOWN(VK_RETURN));
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_INTENSITY);
	return;
	
}
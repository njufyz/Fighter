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
	SetConsoleTitle(TEXT("SpaceWar"));
	HideCursor();
	SetPos(30, 1);
	cout << "Space  War";
	drawRow(3, 0, 79, '=');
	drawRow(7, 0, 79, '=');

	SetPos(28, 5);
	cout << "w �� s ѡ�� k ȷ��";
	SetPos(25, 11);
	cout << "1. �򵥵ĵ���";
	SetPos(25, 13);
	cout << "2. ���ĵ���";
	drawRow(20, 0, 79, '-');
	drawRow(22, 0, 79, '-');
	
	SetPos(25, 18);
	cout << "�򵥵ĵ��ˣ�";
	SetPos(38, 18);
	cout << "�ƶ��ٶȽ���";
	
	int j = 11;
	SetPos(22, j);
	cout << ">>";

	while (1)
	{
		if(KEYDOWN(VK_UP))
		{	
			if (j == 13)
				{
					SetPos(22, j);
					cout << "��";
					j = 11;
					SetPos(22, j);
					cout << ">>";
			
					SetPos(25, 18);
					cout << "�򵥵ĵ��ˣ�";
					SetPos(38, 18);
					cout << "�ƶ��ٶȽ���";
				}
		continue;
		}
		if(KEYDOWN(VK_DOWN))
			{
				if (j == 11)
				{
					SetPos(22, j);
					cout << "��";
					j = 13;
					SetPos(22, j);
					cout << ">>";
				
					SetPos(25, 18);
					cout << "���ĵ��ˣ�";
					SetPos(38, 18);
					cout << "�ƶ��ٶȽϿ�";
				}
				continue;
			}
		if(KEYDOWN(VK_RETURN))
			{
			if (j == 8)
				sleep_time = 70;
			else sleep_time = 35;
			break;
			}
			
		}
	return 0;
}
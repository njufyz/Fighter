#pragma once
#include <Windows.h>
#include"common.h"

class Screen
{
	char screen[ScreenHeight][ScreenWidth];
	CHAR_INFO board[ScreenHeight][BoardWidth];
	HANDLE hOut;
	
public:
	Screen();
	void clear();
	void render();
	void writechar(char c, int x, int y);
	void writeboard();

	friend class Game;
	friend class Enemy;
	friend class MyPlane;
	friend class Bullet;
};


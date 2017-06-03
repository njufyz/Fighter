#pragma once
#include <Windows.h>
#include"common.h"

class Screen
{
	CHAR_INFO screen[ScreenHeight][ScreenWidth];
	HANDLE hOut;
	
public:
	Screen();
	void clear();
	void render();
	void writechar(CHAR_INFO c, int x, int y);
	void writeboard(int scores, int miss, float hp);
	bool messagebox();
	void cls();

	friend class Game;
	friend class Enemy;
	friend class MyPlane;
	friend class Bullet;
};


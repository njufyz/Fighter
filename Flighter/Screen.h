#pragma once
#include"common.h"

class Screen
{
	char screen[ScreenHeight][ScreenWidth];

public:
	Screen();
	void clear();
	void render();
	void writechar(char c, int x, int y);
	void writeplane(Plane* plane);

	friend class Game;
	friend class Enemy;
	friend class MyPlane;
	friend class Bullet;
};


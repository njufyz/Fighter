#pragma once
#include "Plane.h"
#include "common.h"
class Enemy :
	public Plane
{
	float velocity;
	bool enable;
	char ImagePlaneEnemy[planeSizeX][planeSizeY] =
	{
		{ '#',	'#', 	'#' },
		{ ' ',	'~',	  ' ' },
	};

public:
	Enemy() {}
	Enemy(float x, float y, float hp, float v)
	{
		PosX = x;
		PosY = y;
		HP = hp;
		enable = 1;
		velocity = 1.0;
	}
	bool isout();
	bool isin();
	void move();
	void render();
	
};


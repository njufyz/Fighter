#pragma once
#include "Plane.h"
#include "common.h"
class Enemy :
	public Plane
{
	bool enable;
	char ImagePlaneEnemy[planeSizeX][planeSizeY] =
	{
		{ '#',	'#', 	'#' },
		{ ' ',	'~',	  ' ' },
	};

public:
	Enemy() {}
	Enemy(float x, float y, float hp)
	{
		PosX = x;
		PosY = y;
		HP = hp;
		enable = 1;
	}
	void render();
};


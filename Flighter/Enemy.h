#pragma once
#include "Plane.h"
#include "common.h"
class Enemy :
	public Plane
{
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
	}
	void render();
};


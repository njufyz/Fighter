#pragma once
#include "Plane.h"
#include"common.h"
class MyPlane :
	public Plane
{
	char ImagePlanePlayer[planeSizeX][planeSizeY] =
	{
		{ '.',	'|',		'.' },
		{ '^',	'^',	'^' },
	};

public:
	MyPlane() {}
	MyPlane(float x, float y, float hp)
	{
		PosX = x;
		PosY = y;
		HP = hp;
	}
	void render();
	void setPos();
};


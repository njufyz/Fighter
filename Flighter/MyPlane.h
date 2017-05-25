#pragma once
#include<Windows.h>
#include "Plane.h"
#include"common.h"
class MyPlane :
	public Plane
{
private:
	char ImagePlanePlayer[planeSizeX][planeSizeY] =
	{
		{ '.',	'|',		'.' },
		{ '^',	'^',	'^' },
	};
	HWND hWnd;
public:
	MyPlane() {}
	MyPlane(float x, float y, float hp)
	{
		hWnd = GetConsoleWindow();
		PosX = x;
		PosY = y;
		HP = hp;
	}
	void render();
	void setPos();
};


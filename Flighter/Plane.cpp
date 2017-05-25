#include<Windows.h>
#include "Plane.h"


Plane::Plane(float x, float y, float hp)
{
	PosX = x;
	PosY = y;
	HP = hp;
}

void Plane::setPos()
{
	POINT point;
	GetCursorPos(&point);
	HWND hWnd = GetConsoleWindow();
	ScreenToClient(hWnd, &point);    // 将鼠标指针位置转换为窗口坐标

	PosX = point.y >> 4;
	PosY = point.x >> 3;
}

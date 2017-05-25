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
	ScreenToClient(hWnd, &point);    // �����ָ��λ��ת��Ϊ��������

	PosX = point.y >> 4;
	PosY = point.x >> 3;
}

#pragma once
#include"common.h"
struct Bullet {
	float x;
	float y;
	float velocity;
	int type;
	Bullet(float _x, float _y, int _type)
	{
		x = _x;
		y = _y;
		type = _type;
		velocity = type * 1.0f;
	}
};
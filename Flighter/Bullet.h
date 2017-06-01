#pragma once
#include"common.h"
class Bullet {
	float x;
	float y;
	float velocity;
	int type;
	bool enable;

public:
	Bullet(float _x, float _y, int _type)
	{
		x = _x;
		y = _y;
		type = _type;
		velocity = type * 2.0f;
		enable = 1;
	}

	void render();
	void setPos();
//	void update();
	void move();
	bool isout();
};
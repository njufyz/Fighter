#pragma once

class Game;

class Plane
{
protected:
	int type;
	float PosX;
	float PosY;
	float HP;
	//char* imageAddr;
	
public:
	Plane() {}
	Plane(float x, float y, float hp);
	virtual void render() = 0;

	friend class Game;
};


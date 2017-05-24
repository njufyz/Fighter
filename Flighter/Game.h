#pragma once
#include<list>
#include"Plane.h"
#include"Screen.h"

using namespace std;

class Game
{
	Plane* myplane;
	list<Enemy*>enemy;
	Screen* screen;

public:
	Game();
	~Game();

	void Render();
	void Clear();
	void update();

	friend class Enemy;
	friend class MyPlane;
	friend class Srceen;

};

extern Game game;


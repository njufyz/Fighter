#pragma once
#include<list>
#include"Plane.h"
#include"Screen.h"
#include"Bullet.h"

using namespace std;

class Game
{
	Plane* myplane;
	list<Enemy*>enemy;
	list<Bullet*> bullet;
	Screen* screen;

public:
	Game();
	~Game();

	void Render();
	void Clear();
	void Update();

	friend class Enemy;
	friend class MyPlane;
	friend class Srceen;

};

extern Game game;


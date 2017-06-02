#pragma once

#include<list>
#include"Plane.h"
#include"Screen.h"
#include"Bullet.h"

using namespace std;

class Game
{
	MyPlane* myplane;
	list<Enemy*>enemy;
	list<Bullet*> bullet;
	Screen* screen;

	void updatebullet();
	void updatenemy();

	void render();

	void generateMYBullet();
	void generateEMBullet();
	void generateEMplane();

	void collidewithmyplane();

public:
	Game();
	~Game();

	void Render();
	void Clear();
	void Update();
	
	friend class Enemy;
	friend class MyPlane;
	friend class Screen;
	friend class Bullet;

};

extern Game game;


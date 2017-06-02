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

	void collide_with_myplane();
	void collide_with_enemy();

	int scores;
	int miss;

public:
	Game();
	~Game();

	void Render();
	void Clear();
	void Update();
	void WriteScores();
	
	friend class Enemy;
	friend class MyPlane;
	friend class Screen;
	friend class Bullet;

};

extern Game game;


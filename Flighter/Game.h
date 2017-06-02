#pragma once

#include<list>
#include<memory>
#include"Plane.h"
#include"Screen.h"
#include"Bullet.h"

using namespace std;

class Game
{
	MyPlane* myplane;
	list<shared_ptr<Enemy>>enemy;
	list<shared_ptr<Bullet>> bullet;
	Screen* screen;

	void updatebullet();
	void updatenemy();

	void render();

	void generateMYBullet();
	void generateEMBullet();
	void generateEMplane();

	void collide_with_myplane();
	void collide_with_enemy();
	void enemy_collide_with_myplane();
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

	friend void init();
};

extern Game game;


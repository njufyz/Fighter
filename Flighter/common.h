#pragma once

#define ScreenWidth 80
#define ScreenHeight 40

#define BattleWidth  80
#define  BattleHeight  40

#define planeSizeX 2
#define planeSizeY 3

#define ME -1
#define EM 1

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)


class Game;
class Screen;
class Plane;
class MyPlane;
class Enemy;
class Bullet;

extern int game_time;

enum GAME_STAT{INIT, PLAY, DIE};


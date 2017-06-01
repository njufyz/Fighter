#include"common.h"
#include"Screen.h"
#include "Game.h"
#include<Windows.h>
#include<cstdio>
#include<ctime>

Game game;
int game_time= 0;

int main()
{
	system("MODE con: COLS=80 LINES=40");
	while (1)
	{
		game.Clear();
		game.Update();
		game.Render();
		Sleep(30);
		game_time++;
	}
	
}



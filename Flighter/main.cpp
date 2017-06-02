#include"common.h"
#include"Screen.h"
#include "Game.h"
#include<Windows.h>
#include<cstdio>
#include<ctime>

Game game;
int game_time= 0;
GAME_STAT game_stat = INIT;

int main()
{
	system("MODE con: COLS=80 LINES=40");
	//system("color af");
	srand(time(0));
	game_stat = PLAY;
	while (1)
	{
		switch (game_stat) {

			case  PLAY:
				game.Clear();
				game.Update();
				game.Render();
				game_time++;
				break;

			case DIE:
				system("cls");
				game.WriteScores();
				break;
		}
		Sleep(60);
	}
	
}



#include"common.h"
#include"Screen.h"
#include "Game.h"
#include<Windows.h>
#include<cstdio>
#include<ctime>

Game game;
int game_time= 0;
GAME_STAT game_stat = INIT;
int sleep_time = 70;

int main()
{
	
	game_stat = INIT;
	srand(time(0));
//	drawMenu();

	while (1)
	{
		switch (game_stat) {

			case INIT:
				
				system("MODE con: COLS=120 LINES=40");
				game.Init();
				break;

			case  PLAY:
				game.Clear();
				game.Update();
				game.Render();
				game_time++;
				Sleep(sleep_time);
				break;

			case DIE:
				system("cls");
				game.Render();
				if (!game.Die())
					return 0;
				else 
					break;

			case REPLAY:
				game.Replay();
				break;
		}
		
	}
	
}



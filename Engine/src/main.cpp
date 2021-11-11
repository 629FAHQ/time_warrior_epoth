#include <ncurses.h>

#include "common.hpp"
#include "Game.hpp"

int main()
{
	AGame* NewGame = new class Game;
	NewGame->StartGame();
    
    SAFE_DELETE(NewGame)

	return 0;
}
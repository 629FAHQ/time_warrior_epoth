#include <ncurses.h>

#include "Common.hpp"
#include "Game.hpp"

int main()
{
	Game *NewGame = new class Game;
	NewGame->StartGame();

	SAFE_DELETE(NewGame)

	return 0;
}
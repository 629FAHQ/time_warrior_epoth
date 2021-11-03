#include "BaseGame.hpp"

int main()
{
	BaseGame* Game = new BaseGame;
	Game->StartGame();
	
	delete Game;
	Game = nullptr;
	
	return 0;
}
#include <ctime>
#include <ncurses.h>

#include "common.hpp"
#include "Game.hpp"
#include "Controller.hpp"


Game::Game()
{
    
}

Game::~Game()
{
	
}

void Game::StartGame() 
{
    controller = new Controller;
 
    InitializeNcurses();
    
    // ** AGame::StartGame() have to be called at the end of this method. **
    AGame::StartGame();
}

void Game::EndGame()
{
    SAFE_DELETE(controller)

    endwin();
    
    // ** AGame::EndGame() have to be called at the end of this method. **
	AGame::EndGame();
}

void Game::SaveGame()
{
	
}

void Game::LoadGame()
{
	
}

void Game::Tick()
{
    // ** AGame::EndGame() have to be called at the head of this method. **
    AGame::Tick();

    Controller *castedController = dynamic_cast<Controller*>(controller);
    
    int key = controller->GetPressedKey();
    if(key == ctrl('q'))
    {
        isGameHaveToBeEnded = true;
    }
    if(key != castedController->EKey::NO_INPUT)
    {
        move(0, 0);
        printw("pressed key: %2c", key);
    }

    refresh();
}


void Game::InitializeNcurses()
{
    initscr();
    raw();
    noecho();
}
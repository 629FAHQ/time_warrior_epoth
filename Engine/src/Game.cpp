#include <ctime>
#include <ncurses.h>

#include "Engine.hpp"
#include "common.hpp"
#include "Game.hpp"
#include "Controller.hpp"
#include "Screen.hpp"


Game::Game()
{
    
}

Game::~Game()
{
	
}

void Game::StartGame() 
{
    controller = new Controller;
    screen = new Screen;
 
    InitializeNcurses();
    
    // ** AGame::StartGame() have to be called at the end of this method. **
    AGame::StartGame();
}

void Game::EndGame()
{
    SAFE_DELETE(controller)
    SAFE_DELETE(screen)

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
    
    int key = controller->GetPressedKey();
    if(key == ctrl('q'))
    {
        isGameHaveToBeEnded = true;
    }
}


void Game::InitializeNcurses()
{
    initscr();
    raw();
    noecho();
}
#include <ctime>
#include <ncurses.h>

#include "Common.hpp"
#include "Game.hpp"
#include "Controller.hpp"
#include "Screen.hpp"
#include "Engine.hpp"

Game::Game()
{
    Engine::SetCurrentGame(this);

    startClock = (double)clock();
    previousClock = startClock;
    currentClock = startClock;
    deltaTime = 0.f;
    gameTimeWeight = 1.f;

    isGameHaveToBeEnded = false;
    isNewFrameHaveToBeDrawn = false;
}

Game::~Game()
{
}

void Game::StartGame()
{
    InitializeNcurses();

    controller = new Controller;
    screen = new Screen;

    controller->InitializeController();

    while (!isGameHaveToBeEnded)
    {
        Tick();
    }

    EndGame();
}

void Game::EndGame()
{
    SAFE_DELETE(controller)
    SAFE_DELETE(screen)

    endwin();
}

void Game::SaveGame()
{
}

void Game::LoadGame()
{
}

void Game::Tick()
{
    UpdateDeltaTime();

    if (isNewFrameHaveToBeDrawn)
    {
        controller->UpdateController();
        screen->Tick();
        isNewFrameHaveToBeDrawn = false;
    }

    int key = controller->GetPressedKey();
    if (key == ctrl('q'))
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

void Game::UpdateDeltaTime()
{
    currentClock = clock();
    double newDeltaTime = (double)(currentClock - previousClock) / CLOCKS_PER_SEC;

    if (newDeltaTime >= 1.f / MAX_FPS)
    {
        deltaTime = newDeltaTime;
        previousClock = currentClock;

        isNewFrameHaveToBeDrawn = true;
    }
}
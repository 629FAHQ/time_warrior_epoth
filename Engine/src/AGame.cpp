#include <ctime>

#include "Engine.hpp"
#include "AGame.hpp"
#include "AController.hpp"
#include "AScreen.hpp"


AGame::AGame()
{
    Engine::SetCurrentGame(this);

	startClock = (double) clock();
	previousClock = startClock;
	currentClock = startClock;
	deltaTime = 0.f;
	gameTimeWeight = 1.f;
	
	isGameHaveToBeEnded = false;
}

AGame::~AGame()
{
    
}

void AGame::StartGame()
{
    controller->InitializeController();

    while(!isGameHaveToBeEnded)
	{
        controller->UpdateController();
		Tick();
	}

    EndGame();
};

void AGame::EndGame()
{

};

void AGame::Tick()
{
    UpdateDeltaTime();
    screen->Tick();
};

void AGame::UpdateDeltaTime()
{
	currentClock = (double) clock();
	deltaTime = (currentClock - previousClock) / CLOCKS_PER_SEC;
	previousClock = currentClock;
}
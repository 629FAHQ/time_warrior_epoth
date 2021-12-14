#include <ctime>

#include "AEngine.hpp"
#include "common.hpp"
#include "AGame.hpp"
#include "AController.hpp"
#include "AScreen.hpp"

AGame::AGame()
{
	AEngine::SetCurrentGame(this);

	startClock = (double)clock();
	previousClock = startClock;
	currentClock = startClock;
	deltaTime = 0.f;
	gameTimeWeight = 1.f;

	isGameHaveToBeEnded = false;
	isNewFrameHaveToBeDrawn = false;
}

AGame::~AGame()
{
}

void AGame::StartGame()
{
	controller->InitializeController();

	while (!isGameHaveToBeEnded)
	{
		Tick();
	}

	EndGame();
};

void AGame::EndGame(){

};

void AGame::Tick()
{
	UpdateDeltaTime();
	if (isNewFrameHaveToBeDrawn)
	{
		controller->UpdateController();
		screen->Tick();
		isNewFrameHaveToBeDrawn = false;
	}
};

void AGame::UpdateDeltaTime()
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
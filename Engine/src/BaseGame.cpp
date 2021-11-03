#include <ctime>
#include "BaseGame.hpp"


BaseGame::BaseGame()
{
	startClock = (double) clock();
	previousClock = startClock;
	currentClock = startClock;
	deltaTime = 0.f;
	gameTimeWeight = 1.f;
	
	isGameHaveToBeEnded = false;
}

BaseGame::~BaseGame()
{
	
}

void BaseGame::StartGame()
{
	while(!isGameHaveToBeEnded)
	{
		Tick();
	}
}

void BaseGame::EndGame()
{
	
}

void BaseGame::SaveGame()
{
	
}

void BaseGame::LoadGame()
{
	
}

void BaseGame::Tick()
{
	UpdateDeltaTime();
}

void BaseGame::UpdateDeltaTime()
{
	currentClock = (double) clock();
	deltaTime = (currentClock - previousClock) / CLOCKS_PER_SEC;
	previousClock = currentClock;
}

double BaseGame::GetPlayingTime()
{
	return (currentClock - startClock) / CLOCKS_PER_SEC;
}

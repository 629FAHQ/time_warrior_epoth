#pragma once

#include <ctime>

class AController;
class AStage;
class AScreen;

class AGame
{
public:
	double gameTimeWeight;
	double deltaTime;
	clock_t startClock;
	clock_t previousClock;
	clock_t currentClock;

	bool isGameHaveToBeEnded;
	bool isNewFrameHaveToBeDrawn;

	AController *controller;
	AStage *stage;
	AScreen *screen;

public:
	AGame();
	virtual ~AGame();
	virtual void StartGame();
	virtual void EndGame();
	virtual void SaveGame() = 0;
	virtual void LoadGame() = 0;
	virtual void Tick();

	inline clock_t GetPlayedClock() { return currentClock - startClock; };
	inline double GetPlayedTime() { return (double)GetPlayedClock() / CLOCKS_PER_SEC; };
	inline double GetDeltaTime() { return deltaTime; };

private:
	void UpdateDeltaTime();
};
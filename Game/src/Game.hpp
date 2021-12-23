#pragma once

#include <ctime>

class Controller;
class Stage;
class Screen;

class Game
{
public:
	double gameTimeWeight;
	double deltaTime;
	clock_t startClock;
	clock_t previousClock;
	clock_t currentClock;

	bool isGameHaveToBeEnded;
	bool isNewFrameHaveToBeDrawn;

	Controller *controller;
	Stage *stage;
	Screen *screen;

public:
	Game();
	virtual ~Game();
	virtual void StartGame();
	virtual void EndGame();
	virtual void SaveGame();
	virtual void LoadGame();
	virtual void Tick();

	inline clock_t GetPlayedClock() { return currentClock - startClock; };
	inline double GetPlayedTime() { return (double)GetPlayedClock() / CLOCKS_PER_SEC; };
	inline double GetDeltaTime() { return deltaTime; };

private:
	void UpdateDeltaTime();
	void InitializeNcurses();
};
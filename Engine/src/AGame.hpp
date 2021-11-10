#pragma once

class AController;
class AStage;
class AScreen;

class AGame {
public:
	double gameTimeWeight;
	double deltaTime;
	double startClock;
	double previousClock;
	double currentClock;

	bool isGameHaveToBeEnded;

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

private:
	void UpdateDeltaTime();
};
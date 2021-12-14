#pragma once

#include "AGame.hpp"

class Game : public AGame
{
public:
	Game();
	virtual ~Game();
	virtual void StartGame() override;
	virtual void EndGame() override;
	virtual void SaveGame() override;
	virtual void LoadGame() override;
	virtual void Tick() override;

private:
	void InitializeNcurses();
};
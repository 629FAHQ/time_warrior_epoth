#pragma once

class Game;

class Engine
{
public:
    static Game *currentGame;

public:
    Engine();
    virtual ~Engine();

    static void SetCurrentGame(Game *game) { Engine::currentGame = game; };
    static Game *GetCurrentGame() { return Engine::currentGame; };
};
class AGame;
class AController;
class AScreen;

class Engine
{
    friend class AGame;
    friend class AController;
    friend class AScreen;

public:
    static AGame *currentGame;

public:
    static AGame *GetCurrentGame() { return Engine::currentGame; };
    static void SetCurrentGame(AGame *game) { Engine::currentGame = game; };
};
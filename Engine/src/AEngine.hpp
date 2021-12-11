class AGame;
class AController;
class AScreen;

class AEngine
{
    friend class AGame;
    friend class AController;
    friend class AScreen;

public:
    static AGame *currentGame;

public:
    AEngine();
    virtual ~AEngine();

    static AGame *GetCurrentGame() { return AEngine::currentGame; };
    static void SetCurrentGame(AGame *game) { AEngine::currentGame = game; };
};
class BaseGame {
private:
	double gameTimeWeight;
	double deltaTime;
	double startClock;
	double previousClock;
	double currentClock;
	
	bool isGameHaveToBeEnded;
public:
	BaseGame();
	virtual ~BaseGame();
	void StartGame();
	void EndGame();
	virtual void SaveGame();
	virtual void LoadGame();
	virtual void Tick();
	
	double GetPlayingTime();
private:
	void UpdateDeltaTime();
};
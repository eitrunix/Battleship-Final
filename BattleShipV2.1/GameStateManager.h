#pragma once
//GameStateManager - Tells the Game what it can do during a state
// GameMode type - SinglePlayer, Multiplayer, GameFinished
// GameState type - Player1Turn, Player2Turn, AiTurn, PlacingShips, GameDone, Loading,

class GameStateManager
{
private:

	static GameStateManager* gmInstance;
public:

	GameStateManager();
	~GameStateManager();
	static GameStateManager* Instance();
	static void Release();

	enum class GameMode 
	{
		SinglePlayerGame,
		Title,
		GameFinished
	};

	enum class GameState 
	{
		Player1Turn,
		AITurn,
		PlacingShips,
		GameDone,
		Loading,
		NoGameState,
	};

	GameState state;
	GameMode mode = GameMode::Title;

	static int numOfPlayers;
	static bool vsAI;
	bool gameFinished;

	void CleanUp();
	void InitialLoading();
	void GameStateCheck();
	void TurnStateCheck();
	void PrintGame();
	void SetUp1PGame();
};
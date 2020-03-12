#pragma once


class GameStateManager
{
	static GameStateManager* s_instance;
public:

	GameStateManager(int _players, bool _vsai);
	~GameStateManager();


	enum class GameMode {
		SinglePlayerGame,
		MultiPlayerGame,
		GameFinished
	};

	enum class GameState {
		Player1Turn,
		Player2Turn,
		AITurn,
		PlacingShips,
		GameDone,
		Loading,
	};

	GameState state; 
	GameMode mode;

	int numOfPlayers;
	bool vsAI;
	bool gameFinished;

	void CleanUp();
	void InitialLoading();
	void StateCheck();
	void StateCheckPlaying();
	void PrintGame();
	void SetUp1PGame();
	GameStateManager* instance(int _players, bool _vsai) {
		if (!s_instance)
		{
			s_instance = new GameStateManager(_players, _vsai);
			return s_instance;
		}
	}
};


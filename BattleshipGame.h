#pragma once
#include "Player.h"
#include "Scoreboard.h"
#include "Board.h"


class BattleshipGame
{
	static BattleshipGame* s_instance;
public:

	BattleshipGame(int _players, bool _vsai);
	~BattleshipGame();


	enum class GameMode {
		SinglePlayerGame,
		MultiPlayerGame
	};

	enum class GameState {
		Player1Turn,
		Player2Turn,
		AITurn,
		PlacingShips,
		CheckWinCon,
		Loading,
		Title
	};
	AI* ai;
	Player* player;
	Player* player2;
	Player* mpPlayer1;
	GameState state; 
	GameMode mode;

	int numOfPlayers;
	bool vsAI;
	bool gameFinished;
	void SetupGame();
	void StateCheck();
	BattleshipGame* instance(int _players, bool _vsai) {
		if (!s_instance)
		{
			s_instance = new BattleshipGame(_players, _vsai);
			return s_instance;
		}
	}


};

// The Game Loop for Battleship, hopefuly writing this will help me logic the thing I bult then ripped apart and rebuilt and yeah..
// TitleScreen
// Player Picks Play
// Ask for Name
// Computer Places Ships
// Player Places Ships
// Loading Screen
// Player 1 Inputs Attack
// Check Player 2 board for hit or miss
// Display Hit or Miss
// Player 2 Turn
// Player 2 Input Attack
// Check Player 1 board for Hit or Miss
// Display Hit or Miss
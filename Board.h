#include <string>
#include "Piece.h"
#include "LinkList.h"

#ifndef BOARD__H
#define BOARD__H

class Board 
{
public:
	Board();
	~Board();

	void DisplayScoreboard();
	void PrintBoards();
	void ClearBoard();
	void FakeLoadingScreeen();
	void PlayerAttackSet();
	void GameLoop();
	// Board Variables

	int playerPBhealth;
	int playerSubHealth;
	int playerCrusHealth;
	int playerACHealth;
	int playerBSHealth;

	int aiPBhealth;
	int aiSubHealth;
	int aiCrusHealth;
	int aiACHealth;
	int aiBSHealth;

};

#endif
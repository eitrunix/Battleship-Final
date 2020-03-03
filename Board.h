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

	std::string name;
	void DisplayScoreboard();
	void PrintBoards();
	void ClearBoard();
	void ClearHits();
	void FakeLoadingScreeen();
	
	// Board Variables
	int row, col;
	int atkRow, atkCol;
	int PieceOnBoard_Comp, PieceOnBoard_Player;
	int compRow, compCol;

	void CheckValidMoveAI();
	void AIHoV();
	void AISetShips();
	void AICordsToAlpha();
	void AiAttackOnBoard();
	void EnterName();
	void PlayerPlaceShips();
	void CheckCords();
	// I can breakt this up more later I just wanna get it working atm.
	void PlayerHoV();
	void RowColVals();
	void RowColAtkVals();
	void PlayerAttack();
	void CheckPlayerAttack();
	void PlayerAttackSet();
	void CheckValidCell();
	void AIAttack();

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
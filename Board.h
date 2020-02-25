#include <string>
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
	void AIInput();
	void AICoordsConvert();
	void CompAttack();
	void take_comp_input();

	void EnterName();
	void PlayerPlaceShips();
	void CheckCords();

	void PlayerHoV();
	void RowColVals();
	void RowColAtkVals();
	void PlayerSetAttack();
	void CheckPlayerAttack();
	void PlayerAttack();
	void CheckValidCell();

};

#endif
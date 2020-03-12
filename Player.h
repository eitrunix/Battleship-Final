#ifndef PLAYER__H
#define PLAYER__H

class Player
{
public:
	int row;
	int col;
	int atkRow;
	int atkCol;
	int PlayerPieceOnBoard;
	Player();
	~Player();

	bool validShipPos, validAtkCord; // For checking if the location is a a Valid attack
	int shipNumber;					// Number of ships the player has left in the game
	// Attacking Variables
	char playerShipCords[10];
	char playerAtkCords[10];
	// Placing Pieces
	char HoV[20];

	std::string name;
	
	void EnterName();

	void RowColAtkVals();
	void RowColVals();
	void CheckCords();
	void PlayerPlaceShips();
	void PlayerHoV();
	void CheckValidCell();
	void PlayerAttack();
	void CheckPlayerAttack();
	void ClearHits();
	void PlayerAttackSet();
};
#endif // !PLAYER__H

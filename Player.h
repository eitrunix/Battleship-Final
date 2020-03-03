#ifndef PLAYER__H
#define PLAYER__H

class Player
{
public:

	Player();
	~Player();
	bool validShipPos, validAtkCord; // For checking if the location is a a Valid attack
	int shipNumber;					// Number of ships the player has left in the game
	// Attacking Variables
	char playerShipCords[10];
	char playerAtkCords[10];
	// Placing Pieces
	char HoV[20];	

	void Setup();

};
#endif // !PLAYER__H

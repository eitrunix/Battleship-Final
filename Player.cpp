#include "Player.h"
#include <iostream>
#include <iomanip>
#include "Piece.h"


Piece* Pieces;
Player::Player()
{	
	validShipPos;
	validAtkCord;					// For checking if the location is a a Valid attack
	shipNumber = 0;					// Number of ships the player has left in the game

	// Attacking Variables
	playerShipCords[10];
	playerAtkCords[10];
	// Placing Pieces
	HoV[20];
}

void Player::Setup()
{   

}
Player::~Player()
{
}

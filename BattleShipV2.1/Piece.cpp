#include "Piece.h"

#include <iomanip>
#include <iostream>

using namespace SDLFramework;


PatrolBoat::PatrolBoat()
{
	health = 2;
	hit = false;
	ID = 1;
	PiecePlaceText = "Enter The Coordinate For Your Patrol Boat(2 spots) : ";
	BoatImage = new Texture("PatrolBoat.png");

	name = "PatrolBoat";

}

PatrolBoat::~PatrolBoat()
{

}

Submarine::Submarine()
{
	health = 3;
	hit = false;
	ID = 2;

	PiecePlaceText = "Enter The Coordinate For Your Submarine (3 spots): ";
	BoatImage = new Texture("Submarine.png");

	name = "Submarine";

}

Submarine::~Submarine()
{

}

Cruiser::Cruiser()
{
	health = 3;
	hit = false;
	ID = 3;

	PiecePlaceText = "Enter The Coordinate For Your Crusier (3 spots): ";
	BoatImage = new Texture("Cruiser.png");

	name = "Cruiser";

}

Cruiser::~Cruiser()
{

}


AircraftCarrier::AircraftCarrier()
{
	health = 4;
	hit = false;
	ID = 4;

	PiecePlaceText = "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
	BoatImage = new Texture("AircraftCarrier.png");

	name = "AircraftCarrier";

}

AircraftCarrier::~AircraftCarrier()
{

}



Battleship::Battleship()
{
	health = 5;
	hit = false;
	ID = 5;

	PiecePlaceText = "Enter The Coordinate For Your Battleship (5 spots): ";
	BoatImage = new Texture("BattleShip.png");

	name = "Battleship";

}

Battleship::~Battleship()
{
}

int Piece::GetHealth()
{
	return health;
}

void Piece::OnHit()
{
	health -= 1;
	if (health <= 0)
	{
		health = 0;
	}


}
void Piece::AssignTile()
{
	// Check the Tile its placed on, then tell the tile its occupied by x ship piece

}

Piece::Piece()
{
	health = 0;

}

Piece::~Piece()
{

}

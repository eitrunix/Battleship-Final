#include "Piece.h"

#include <iomanip>
#include <iostream>

using namespace SDLFramework;

//// !!!!!!!!!!! Sprites/Images are not set up, I dont have the asset yet, right now each hitpoint texture is an entire sprite sheet for placeholder stuff !!!!!!!!!!!


PatrolBoat::PatrolBoat()
{
	health = 2;
	hit = false;

	PiecePlaceText = "Enter The Coordinate For Your Patrol Boat(2 spots) : ";
	PatrolBoatImage = new Texture("PatrolBoat.png");

	name = "PatrolBoat";

}

PatrolBoat::~PatrolBoat()
{

}

void PatrolBoat::OnHit()
{
	health -= 1;
}

Submarine::Submarine()
{
	health = 3;
	hit = false;

	PiecePlaceText = "Enter The Coordinate For Your Submarine (3 spots): ";
	SubmarineImage = new Texture("Submarine.png");

	name = "Submarine";

}

Submarine::~Submarine()
{

}

void Submarine::OnHit()
{
	health -= 1;
}

Cruiser::Cruiser()
{
	health = 3;
	hit = false;

	PiecePlaceText = "Enter The Coordinate For Your Crusier (3 spots): ";
	CruiserImage = new Texture("Cruiser.png");

	name = "Cruiser";

}

Cruiser::~Cruiser()
{

}

void Cruiser::OnHit()
{
	health -= 1;

}

AircraftCarrier::AircraftCarrier()
{
	health = 4;
	hit = false;

	PiecePlaceText = "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
	CarrierImage = new Texture("AircraftCarrier.png");

	name = "AircraftCarrier";

}

AircraftCarrier::~AircraftCarrier()
{

}

void AircraftCarrier::OnHit()
{
	health -= 1;

}

Battleship::Battleship()
{
	health = 5;
	hit = false;

	PiecePlaceText = "Enter The Coordinate For Your Battleship (5 spots): ";
	BattleshipImage = new Texture("BattleShip.png");

	name = "Battleship";

}

Battleship::~Battleship()
{
}

void Battleship::OnHit()
{
	health -= 1;
}


void Piece::OnHit()
{

}

Piece::Piece()
{
	health = 0;

}

Piece::~Piece()
{

}

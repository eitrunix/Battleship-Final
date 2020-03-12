#include "Piece.h"

#include <iomanip>
#include <iostream>

PatrolBoat::PatrolBoat()
{
	ID = 1;
	health = 2;
	hit = false;
	name = "PatrolBoat";
	icon = "P";
	PiecePlaceText = "Enter The Coordinate For Your Patrol Boat(2 spots) : ";
	scoreBoardMargin = 7;
}

void PatrolBoat::OnHit()
{
	health -= 1;
}

Submarine::Submarine()
{
	ID = 2;
	health = 3;
	hit = false;
	name = "Submarine";
	icon = "S";
	PiecePlaceText = "Enter The Coordinate For Your Submarine (3 spots): ";
	scoreBoardMargin = 9;
}

void Submarine::OnHit()
{
	health -= 1;
}

Cruiser::Cruiser()
{
	ID = 3;
	health = 3;
	hit = false;
	icon = "C";
	PiecePlaceText = "Enter The Coordinate For Your Crusier (3 spots): ";
	name = "Cruiser";

}

void Cruiser::OnHit()
{
	health -= 1;

}

AircraftCarrier::AircraftCarrier()
{
	ID = 4;
	health = 4;
	hit = false;
	icon = "A";
	PiecePlaceText = "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
	name = "AircraftCarrier";

}

void AircraftCarrier::OnHit()
{
	health -= 1;

}

Battleship::Battleship()
{
	ID = 5;
	health = 5;
	hit = false;
	icon = "B";
	PiecePlaceText = "Enter The Coordinate For Your Battleship (5 spots): ";
	name = "Battleship";
	scoreBoardMargin = 8;

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

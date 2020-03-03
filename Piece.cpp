#include "Piece.h"

PatrolBoat::PatrolBoat()
{
	health = 2;
	hit = false;
	name = "PatrolBoat";
	scoreBoardMargin = 7;
}

void PatrolBoat::OnHit()
{
	health -= 1;
}

Submarine::Submarine()
{
	health = 3;
	hit = false;
	name = "Submarine";
	scoreBoardMargin = 9;
}

void Submarine::OnHit()
{
	health -= 1;
}

Cruiser::Cruiser()
{
	health = 3;
	hit = false;
	name = "Cruiser";

}

void Cruiser::OnHit()
{
	health -= 1;

}

AircraftCarrier::AircraftCarrier()
{
	health = 4;
	hit = false;
	name = "AircraftCarrier";

}

void AircraftCarrier::OnHit()
{
	health -= 1;

}

Battleship::Battleship()
{
	health = 5;
	hit = false;
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
}

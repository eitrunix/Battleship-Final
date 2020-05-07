#include "Piece.h"

#include <iomanip>
#include <iostream>

using namespace SDLFramework;


PatrolBoat::PatrolBoat()
{
	health = 2;
	hit = false;
	ID = 0;
	PiecePlaceText = "Enter The Coordinate For Your Patrol Boat(2 spots) : ";
	StartPiece = new Texture("PBStart.png");
	EndPiece = new Texture("PBPart2.png");
	name = "PatrolBoat";
	parts.push_back(StartPiece);
	parts.push_back(EndPiece);
	parts.begin();

}

PatrolBoat::~PatrolBoat()
{

}

Submarine::Submarine()
{
	health = 3;
	hit = false;
	ID = 1;

	PiecePlaceText = "Enter The Coordinate For Your Submarine (3 spots): ";
	StartPiece = new Texture("SubStart.png");
	Part2 = new Texture("SubPart2.png");
	EndPiece = new Texture("SubPart3.png");
	parts.push_back(StartPiece);
	parts.push_back(Part2);
	parts.push_back(EndPiece);

	name = "Submarine";
	parts.begin();

}

Submarine::~Submarine()
{

}

Cruiser::Cruiser()
{
	health = 3;
	hit = false;
	ID = 2;

	PiecePlaceText = "Enter The Coordinate For Your Crusier (3 spots): ";
	StartPiece = new Texture("CruStart.png");
	Part2 = new Texture("CruPart2.png");
	EndPiece = new Texture("CruPart3.png");
	parts.push_back(StartPiece);
	parts.push_back(Part2);
	parts.push_back(EndPiece);

	name = "Cruiser";
	parts.begin();

}

Cruiser::~Cruiser()
{

}


AircraftCarrier::AircraftCarrier()
{
	health = 4;
	hit = false;
	ID = 3;

	PiecePlaceText = "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
	StartPiece = new Texture("ACStart.png");
	Part2 = new Texture("ACPart2.png");
	Part3 = new Texture("ACPart3.png");
	EndPiece = new Texture("ACPart4.png");
	parts.push_back(StartPiece);
	parts.push_back(Part2);
	parts.push_back(Part3);
	parts.push_back(EndPiece);

	name = "AircraftCarrier";
	parts.begin();

}

AircraftCarrier::~AircraftCarrier()
{

}



Battleship::Battleship()
{
	health = 5;
	hit = false;
	ID = 4;

	PiecePlaceText = "Enter The Coordinate For Your Battleship (5 spots): ";
	StartPiece = new Texture("BSStart.png");
	Part2 = new Texture("BSPart2.png");
	Part3 = new Texture("BSPart3.png");
	Part4 = new Texture("BSPart4.png");
	EndPiece = new Texture("BSPart5.png");
	parts.push_back(StartPiece);
	parts.push_back(Part2);
	parts.push_back(Part3);
	parts.push_back(Part4);
	parts.push_back(EndPiece);

	name = "Battleship";
	parts.begin();
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
	std::cout << health << std::endl;

}
void Piece::AssignTile(int x, int y)
{
	xPos = x;
	yPos = y;

}

int Piece::getTileXPos()
{
	return xPos;
}

int Piece::getTileYPos()
{
	return yPos;
}

Piece::Piece()
{
}

Piece::~Piece()
{

}

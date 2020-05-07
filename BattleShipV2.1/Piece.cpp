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
	hParts.push_back(StartPiece);
	hParts.push_back(EndPiece);
	hParts.begin();

	vStartPiece = new Texture("vPBStart.png");
	vEndPiece = new Texture("vPBPart2.png");
	vParts.push_back(vStartPiece);
	vParts.push_back(vEndPiece);
	vParts.begin();
	name = "PatrolBoat";

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
	hParts.push_back(StartPiece);
	hParts.push_back(Part2);
	hParts.push_back(EndPiece);

	hParts.begin();

	vStartPiece = new Texture("vSubStart.png");
	vPart2 = new Texture("vSubPart2.png");
	vEndPiece = new Texture("vSubPart3.png");
	vParts.push_back(vStartPiece);
	vParts.push_back(vPart2);
	vParts.push_back(vEndPiece);

	vParts.begin();
	name = "Submarine";

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
	hParts.push_back(StartPiece);
	hParts.push_back(Part2);
	hParts.push_back(EndPiece);

	hParts.begin();

	vStartPiece = new Texture("vCruStart.png");
	vPart2 = new Texture("vCruPart2.png");
	vEndPiece = new Texture("vCruPart3.png");
	vParts.push_back(vStartPiece);
	vParts.push_back(vPart2);
	vParts.push_back(vEndPiece);

	hParts.begin();
	name = "Cruiser";

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

	hParts.push_back(StartPiece);
	hParts.push_back(Part2);
	hParts.push_back(Part3);
	hParts.push_back(EndPiece);

	hParts.begin();

	vStartPiece = new Texture("vACStart.png");
	vPart2 = new Texture("vACPart2.png");
	vPart3 = new Texture("vACPart3.png");
	vEndPiece = new Texture("vACPart4.png");
 
	vParts.push_back(vStartPiece);
	vParts.push_back(vPart2);
	vParts.push_back(vPart3);
	vParts.push_back(vEndPiece);

	vParts.begin();
	name = "AircraftCarrier";

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
	hParts.push_back(StartPiece);
	hParts.push_back(Part2);
	hParts.push_back(Part3);
	hParts.push_back(Part4);
	hParts.push_back(EndPiece);

	hParts.begin();

	vStartPiece = new Texture("vBSStart.png");
	vPart2 = new Texture("vBSPart2.png");
	vPart3 = new Texture("vBSPart3.png");
	vPart4 = new Texture("vBSPart4.png");
	vEndPiece = new Texture("vBSPart5.png");

	vParts.push_back(vStartPiece);
	vParts.push_back(vPart2);
	vParts.push_back(vPart3);
	vParts.push_back(vPart4);
	vParts.push_back(vEndPiece);

	vParts.begin();

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

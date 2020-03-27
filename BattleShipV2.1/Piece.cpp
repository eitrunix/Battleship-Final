#include "Piece.h"
#include "AnimatedTexture.h"

#include <iomanip>
#include <iostream>

using namespace SDLFramework;

//// !!!!!!!!!!! Sprites/Images are not set up, I dont have the asset yet, right now each hitpoint texture is an entire sprite sheet for placeholder stuff !!!!!!!!!!!
PatrolBoat::PatrolBoat()
{
	health = 2;
	hit = false;

	
	hp1Texture = new Texture("SpriteSheet.png");
	hp2Texture = new Texture("SpriteSheet.png");

	PiecePlaceText = "Enter The Coordinate For Your Patrol Boat(2 spots) : ";

	name = "PatrolBoat";

}

PatrolBoat::~PatrolBoat()
{
	hp1Texture = nullptr;
	delete hp1Texture;
	hp2Texture = nullptr;
	delete hp2Texture;

}

void PatrolBoat::OnHit()
{
	health -= 1;
}

Submarine::Submarine()
{
	health = 3;
	hit = false;

	hp1Texture = new Texture("SpriteSheet.png");
	hp2Texture = new Texture("SpriteSheet.png");
	hp3Texture = new Texture("SpriteSheet.png");

	PiecePlaceText = "Enter The Coordinate For Your Submarine (3 spots): ";

	name = "Submarine";

}

Submarine::~Submarine()
{
	hp1Texture = nullptr;
	delete hp1Texture;
	hp2Texture = nullptr;
	delete hp2Texture;
	hp3Texture = nullptr;
	delete hp3Texture;

}

void Submarine::OnHit()
{
	health -= 1;
}

Cruiser::Cruiser()
{
	health = 3;
	hit = false;

	hp1Texture = new Texture("SpriteSheet.png");
	hp2Texture = new Texture("SpriteSheet.png");
	hp3Texture = new Texture("SpriteSheet.png");

	PiecePlaceText = "Enter The Coordinate For Your Crusier (3 spots): ";

	name = "Cruiser";

}

Cruiser::~Cruiser()
{
	hp1Texture = nullptr;
	delete hp1Texture;	
	hp2Texture = nullptr;
	delete hp2Texture;
	hp3Texture = nullptr;
	delete hp3Texture;

}

void Cruiser::OnHit()
{
	health -= 1;

}

AircraftCarrier::AircraftCarrier()
{
	health = 4;
	hit = false;

	hp1Texture = new Texture("SpriteSheet.png");
	hp2Texture = new Texture("SpriteSheet.png");
	hp3Texture = new Texture("SpriteSheet.png");
	hp4Texture = new Texture("SpriteSheet.png");

	PiecePlaceText = "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";

	name = "AircraftCarrier";

}

AircraftCarrier::~AircraftCarrier()
{
	hp1Texture = nullptr;
	delete hp1Texture;
	hp2Texture = nullptr;
	delete hp2Texture;
	hp3Texture = nullptr;
	delete hp3Texture;
	hp4Texture = nullptr;
	delete hp4Texture;

}

void AircraftCarrier::OnHit()
{
	health -= 1;

}

Battleship::Battleship()
{
	health = 5;
	hit = false;

	hp1Texture = new Texture("SpriteSheet.png");
	hp2Texture = new Texture("SpriteSheet.png");
	hp3Texture = new Texture("SpriteSheet.png");
	hp4Texture = new Texture("SpriteSheet.png");
	hp5Texture = new Texture("SpriteSheet.png");

	PiecePlaceText = "Enter The Coordinate For Your Battleship (5 spots): ";

	name = "Battleship";

}

Battleship::~Battleship()
{
	hp1Texture = nullptr;
	delete hp1Texture;
	hp2Texture = nullptr;
	delete hp2Texture;
	hp3Texture = nullptr;
	delete hp3Texture;
	hp4Texture = nullptr;
	delete hp4Texture;
	hp5Texture = nullptr;
	delete hp5Texture;
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

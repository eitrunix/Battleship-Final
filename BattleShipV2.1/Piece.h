#pragma once
#include <string>
#include "AnimatedTexture.h"
using namespace SDLFramework;

class Piece : GameEntity
{
public:
	Piece();
	~Piece();
	int health = 0;
	bool hit = false;
	int ID = 0;
	std::string name;
	std::string PiecePlaceText;
	std::string PieceHitText;

	int GetHealth();
	void OnHit();
	void AssignTile();
};

class PatrolBoat : public Piece
{
public:
	PatrolBoat();
	~PatrolBoat();
	Texture* BoatImage;


};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	Texture* BoatImage;


};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	Texture* BoatImage;


};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	Texture* BoatImage;


};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	Texture* BoatImage;


};


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

	std::string name;
	std::string PiecePlaceText;
	std::string PieceHitText;

	virtual void OnHit();
};

class PatrolBoat : public Piece
{
public:
	PatrolBoat();
	~PatrolBoat();
	void OnHit() override;	
	Texture* BoatImage;

};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	void OnHit() override;
	Texture* BoatImage;
};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	void OnHit() override;
	Texture* BoatImage;
};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	void OnHit() override;
	Texture* BoatImage;
};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	void OnHit() override;
	Texture* BoatImage;
};


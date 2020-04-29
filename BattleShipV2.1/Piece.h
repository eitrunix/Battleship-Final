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

	virtual void OnHit();
	virtual void AssignTile();
};

class PatrolBoat : public Piece
{
public:
	PatrolBoat();
	~PatrolBoat();
	void OnHit() override;	
	void AssignTile() override;
	Texture* BoatImage;


};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	void OnHit() override;
	void AssignTile() override;
	Texture* BoatImage;


};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	void OnHit() override;
	void AssignTile() override;
	Texture* BoatImage;


};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	void OnHit() override;
	void AssignTile() override;
	Texture* BoatImage;


};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	void OnHit() override;
	void AssignTile() override;
	Texture* BoatImage;


};


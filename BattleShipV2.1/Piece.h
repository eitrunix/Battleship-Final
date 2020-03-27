#pragma once
#include <string>
#include "AnimatedTexture.h"

AnimatedTexture* HitAnimm;


class Piece
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

	Texture* PatrolBoatImage;
	Texture* SubmarineImage;
	Texture* CruiserImage;
	Texture* CarrierImage;
	Texture* BattleshipImage;

	AnimatedTexture* HitAnimm;

};

class PatrolBoat : public Piece
{
public:
	PatrolBoat();
	~PatrolBoat();
	void OnHit() override;

};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	void OnHit() override;

};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	void OnHit() override;

};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	void OnHit() override;

};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	void OnHit() override;

};


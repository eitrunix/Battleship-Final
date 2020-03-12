#pragma once
#include <string>

class Piece
{
public:

	int health;
	int ID;
	bool hit = false;
	int scoreBoardMargin = 11;
	std::string name;
	std::string icon;
	std::string PiecePlaceText;
	std::string PieceHitText;
	virtual void OnHit();

	Piece();
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


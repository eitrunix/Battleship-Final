#pragma once
#include <string>

class Piece
{
public:

	int health = 0;
	int ID = 0;
	bool hit = false;
	int scoreBoardMargin = 11;
	std::string name;

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
	Texture* hp1Texture;
	Texture* hp2Texture;

};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	void OnHit() override;
	Texture* hp1Texture;
	Texture* hp2Texture;
	Texture* hp3Texture;
};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	void OnHit() override;
	Texture* hp1Texture;
	Texture* hp2Texture;
	Texture* hp3Texture;
};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	void OnHit() override;
	Texture* hp1Texture;
	Texture* hp2Texture;
	Texture* hp3Texture;
	Texture* hp4Texture;
};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	void OnHit() override;
	Texture* hp1Texture;
	Texture* hp2Texture;
	Texture* hp3Texture;
	Texture* hp4Texture;
	Texture* hp5Texture;
};


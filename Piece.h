#pragma once
#include <string>

//struct stPiece
//{
//	int	PatrolBoatHealth = 2;
//	int	SubmarineHealth = 3;
//	int	CruiserHealth = 3;
//	int AircraftCarrierHealth = 4;
//	int BattleshipHealth = 5;
//
//	bool PatrolBoatHit = false;
//	bool SubmarineHit = false;
//	bool CruiserHit = false;
//	bool AircraftCarrierHit = false;
//	bool BattleshipHit = false;
//}PlayerPiece, AiPiece;

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


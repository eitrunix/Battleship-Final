#pragma once
#include <string>
#include "AnimatedTexture.h"
using namespace SDLFramework;

class Piece : GameEntity
{
public:
	Piece();
	~Piece();
	int health;
	bool hit = false;
	bool placed = false;
	bool shipQueued = false;
	int ID;
	std::string name;
	std::string PiecePlaceText;
	std::string PieceHitText;
	DataStructuresAndAI::LinkList<Texture*> hParts;
	DataStructuresAndAI::LinkList<Texture*> vParts;
	int xPos;
	int yPos;
	int GetHealth();
	void OnHit();
	void AssignTile(int x, int y);
	int getTileXPos();
	int getTileYPos();
};

class PatrolBoat : public Piece
{
public:
	PatrolBoat();
	~PatrolBoat();
	Texture* StartPiece;
	Texture* EndPiece;

	Texture* vStartPiece;
	Texture* vEndPiece;
};

class Submarine : public Piece
{
public:
	Submarine();
	~Submarine();
	Texture* StartPiece;
	Texture* Part2;
	Texture* EndPiece;

	Texture* vStartPiece;
	Texture* vPart2;
	Texture* vEndPiece;
};

class Cruiser : public Piece
{
public:
	Cruiser();
	~Cruiser();
	Texture* StartPiece;
	Texture* Part2;
	Texture* EndPiece;

	Texture* vStartPiece;
	Texture* vPart2;
	Texture* vEndPiece;
};

class AircraftCarrier : public Piece
{
public:
	AircraftCarrier();
	~AircraftCarrier();
	Texture* StartPiece;
	Texture* Part2;
	Texture* Part3;
	Texture* EndPiece;

	Texture* vStartPiece;
	Texture* vPart2;
	Texture* vPart3;
	Texture* vEndPiece;
};

class Battleship : public Piece
{
public:
	Battleship();
	~Battleship();
	Texture* StartPiece;
	Texture* Part2;
	Texture* Part3;
	Texture* Part4;
	Texture* EndPiece;

	Texture* vStartPiece;
	Texture* vPart2;
	Texture* vPart3;
	Texture* vPart4;
	Texture* vEndPiece;
};


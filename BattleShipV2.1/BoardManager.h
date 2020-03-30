#pragma once
#include "Piece.h"
using namespace SDLFramework;


enum class TileType
{
	Water,
	Hit,
	Miss,
	Ship,
};

class BoardManager
{
private:
	static BoardManager* bmInstance;
	BoardManager* mBoardManager;

public:
	BoardManager();
	~BoardManager();


	static BoardManager* Instance();

	void Update();
	void LateUpdate();
	void Render();
	static void Release();

	int playerRadarRow;
	int playerRadarCol;
	int compRow;
	int compCol;

};

class Board
{
private:

public:
	Board();
	~Board();

	static void Release();
	int Row;
	int Col;
	Texture* boardTex;
};

class Tile
{
private:
	Board* Player;

public:
	
	Texture* TileTex;
	TileType type = TileType::Water;
	bool isOccupied = false;

	int tileRow = 0;
	int tileCol = 0;

	TileType SetTileType(TileType tiletype);
	void SetRow(int i);
	void SetCol(int i);
	
};


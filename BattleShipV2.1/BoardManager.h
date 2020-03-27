#pragma once
#include <SDL.h>
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
public:
	BoardManager();
	~BoardManager();
	static BoardManager* Instance();
	void Update();
	void LateUpdate();
	void Render();
	static void ClearBoard();



private:
	static BoardManager* bmInstance;

};

class Board
{
private:

public:
	void SetTileType(TileType tiletype);
	AnimatedTexture* defTileTex;
	void UpdateTile(Board board[10][10]);

	TileType type;
	bool isOccupied;
	
	int tileRow = 0;
	int tileCol = 0;
};


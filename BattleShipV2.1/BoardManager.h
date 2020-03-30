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

	AnimatedTexture* waterTileTex;
	AnimatedTexture* hitTileTex;
	AnimatedTexture* missTileTex;

	Texture* PlayerBoardTex;
	Texture* RadarBoardTex;
	Texture* AiBoardTex;

};

class Board
{
private:

public:
	void SetTileType(TileType tiletype);
	void UpdateTile(Board board[10][10]);
	
	AnimatedTexture* TileTex;

	TileType type;
	bool isOccupied;
	
	int tileRow = 0;
	int tileCol = 0;

};


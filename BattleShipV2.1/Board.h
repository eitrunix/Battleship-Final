#pragma once
#include "Tile.h"
#include "Piece.h"

class Board : GameEntity
{
private:

public:
	Board() {};
	~Board();

	void Update() override;
	void Render() override;

	static void Release();
	int Row;
	int Col;

	Texture* boardTex;
	Tile* board[10][10];
};
	

//Row = sizeof board / sizeof board[0];
//Col = sizeof board[0] / sizeof board[0][0];

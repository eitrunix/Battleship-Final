#pragma once
#include <random>
#include "Tile.h"
#ifndef __BATTLESHIPBOARD_H 
#define __BATTLESHIPBOARD_H
#define BOARDWIDTH 10
#define BOARDHEIGHT 10
#define TILEOFFSET 43
#define BOARDSIZE 10


class BattleshipBoard : public GameEntity
{
private:

public:
	BattleshipBoard();
	~BattleshipBoard();

	float x;
	float y;
	void SetTileOccupied(int x, int y, bool occupied);
	bool GetIsOccupied(int x, int y);

	void Update() override;
	void Render() override;
	Tile* gameBoard[BOARDWIDTH][BOARDHEIGHT];
	Vector2 BoardPos;
	TileType ReturnTileType(int x, int y);

	void ChangeTile(int _x, int _y, TileType type);
	void BoardPosSet(float _y, float _x);
};
#endif // __BATTLESHIPBOARD_H

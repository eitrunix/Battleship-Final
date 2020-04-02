#pragma once
#include "Tile.h"
#include <random>
#ifndef __BATTLESHIPBOARD_H 
#define __BATTLESHIPBOARD_H
#define BOARDWIDTH 10
#define BOARDHEIGHT 10
#define TILEOFFSET 43


class BattleshipBoard : public GameEntity
{
private:

public:
	BattleshipBoard();
	~BattleshipBoard();

	float x;
	float y;

	void Update() override;
	void Render() override;
	Tile* gameBoard[BOARDWIDTH][BOARDHEIGHT];
	Vector2 BoardPos;

	void BoardPosSet(float _y, float _x);
};
#endif // __BATTLESHIPBOARD_H

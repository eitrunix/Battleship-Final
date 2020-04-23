#pragma once
#include <random>
//#include "MouseControl.h"
#include "Tile.h"
#ifndef __BATTLESHIPBOARD_H 
#define __BATTLESHIPBOARD_H
#define BOARDWIDTH 10
#define BOARDHEIGHT 10
#define TILEOFFSET 43
#define BOARDSIZE 10;


class BattleshipBoard : public GameEntity
{
private:

public:
	BattleshipBoard();
	~BattleshipBoard();

	float x;
	float y;

	//void SetTileType(TileType tiletype);
	//AnimatedTexture* defTileTex;
	//void UpdateTile(BattleshipBoard board[10][10]);


	void Update() override;
	void Render() override;
	Tile* gameBoard[BOARDWIDTH][BOARDHEIGHT];
	Vector2 BoardPos;

	void ChangeTile(int _x, int _y, bool _hit);
	void BoardPosSet(float _y, float _x);
};
#endif // __BATTLESHIPBOARD_H

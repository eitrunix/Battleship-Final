#include "Board.h"

BattleshipBoard::BattleshipBoard()
{
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			gameBoard[tRow][tCol] = new Tile(tRow, tCol, TileType::Water);
			gameBoard[tRow][tCol]->TileRow = tRow;
			gameBoard[tRow][tCol]->TileCol = tCol;
		}

	}
}

BattleshipBoard::~BattleshipBoard()
{
	delete gameBoard[BOARDWIDTH][BOARDHEIGHT];
	gameBoard[BOARDWIDTH][BOARDHEIGHT] = nullptr;
}

void BattleshipBoard::Update()
{

}

void BattleshipBoard::Render()
{
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			gameBoard[tRow][tCol]->Render();
			
			gameBoard[tRow][tCol]->TileTex->Position(x + (tRow * TILEOFFSET), y +(tCol * TILEOFFSET));
			gameBoard[tRow][tCol]->Position(x + (tRow * TILEOFFSET), y + (tCol * TILEOFFSET));

		}

	}
}

TileType BattleshipBoard::ReturnTileType(int x, int y)
{
	return gameBoard[x][y]->mType;
}

void BattleshipBoard::ChangeTile(int _x, int _y, TileType type)
{
	gameBoard[_x][_y]->TileTex->Update();

	gameBoard[_x][_y]->mType = type;

}

void BattleshipBoard::BoardPosSet(float _y, float _x)
{
	x = _x;
	y = _y;
}

void BattleshipBoard::SetTileOccupied(int x, int y, bool occupied)
{
	gameBoard[x][y]->TileTex->Update();

	gameBoard[x][y]->isOccupied = occupied;

}

bool BattleshipBoard::GetIsOccupied(int x, int y)
{
	int tRow;
	int tCol;

	for (tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			if (gameBoard[tRow][tCol] == gameBoard[x][y])
			{
				return gameBoard[tRow][tCol]->isOccupied;
			}
		}
	}
}

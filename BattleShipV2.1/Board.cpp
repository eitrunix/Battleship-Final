#include "Board.h"

BattleshipBoard::BattleshipBoard()
{
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			gameBoard[tRow][tCol] = new Tile(tRow, tCol, Tile::TileType::Water);;
			gameBoard[tRow][tCol]->TileRow = tRow;
			gameBoard[tRow][tCol]->TileCol = tCol;

			std::cout << " " << std::endl;
			std::cout << gameBoard[tRow][tCol]->TileRow;
			std::cout << gameBoard[tRow][tCol]->TileCol;
			gameBoard[5][7]->ChangeType(Tile::TileType::Hit);
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
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			if (gameBoard[tRow][tCol]->mType == Tile::TileType::Hit)
			{
				gameBoard[tRow][tCol]->TileTex = gameBoard[tRow][tCol]->Hittex;
			}
			else if (gameBoard[tRow][tCol]->mType == Tile::TileType::Miss)
			{
				gameBoard[tRow][tCol]->TileTex = gameBoard[tRow][tCol]->MissTex;
			}
			else
			{
				gameBoard[tRow][tCol]->TileTex = gameBoard[tRow][tCol]->TileTex;
			}
		}

	}

}

void BattleshipBoard::Render()
{
	int random = rand() % 5;
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			gameBoard[tRow][tCol]->TileTex->Render();
			gameBoard[tRow][tCol]->TileTex->Position(x + (tRow * TILEOFFSET), y +(tCol * TILEOFFSET));
		}

	}
}

void BattleshipBoard::BoardPosSet(float _y, float _x)
{
	x = _x;
	y = _y;
}


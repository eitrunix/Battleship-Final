#include "Board.h"

BattleshipBoard::BattleshipBoard()
{
	for (int tRow = 0; tRow < BOARDWIDTH; tRow++)
	{
		for (int tCol = 0; tCol < BOARDHEIGHT; tCol++)
		{
			gameBoard[tRow][tCol] = new Tile(tRow, tCol, Tile::TileType::Water);;
			gameBoard[tRow][tCol]->TileTex = new Texture("Water.png");
			std::cout << tRow << std::endl;
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
				gameBoard[tRow][tCol]->TileTex = new Texture("Hit.png");
			}
			else if (gameBoard[tRow][tCol]->mType == Tile::TileType::Miss)
			{
				gameBoard[tRow][tCol]->TileTex = new Texture("Miss.png");
			}
			else
			{
				gameBoard[tRow][tCol]->TileTex = new Texture("Water.png");
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
			if (random == 1) 
			{
				gameBoard[tRow][tCol]->TileTex = new Texture("Water.png");

			}
			else if (random == 3)
			{
				gameBoard[tRow][tCol]->TileTex = new Texture("Miss.png");

			}
			else
			{
				gameBoard[tRow][tCol]->TileTex = new Texture("Hit.png");

			}
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


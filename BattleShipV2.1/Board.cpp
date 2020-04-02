#include "Board.h"

Board::Board()
{
	boardTex = new Texture("BShipGrid.jpg");
	board[10][10] = new Tile();
}

Board::~Board()
{
	delete boardTex;
	delete board[10][10];

	board[10][10] = nullptr;
	boardTex = nullptr;
}

void Board::Update()
{
}

void Board::Render()
{
	Row = sizeof board / sizeof board[0];
	Col = sizeof board[0] / sizeof board[0][0];	

	for (int row = 0; row > Row; row++)
	{
		for (int col = 0; col < Col; col++)
		{
			board[row][col]->Render();
		}
	}
}

void Board::Release()
{
}

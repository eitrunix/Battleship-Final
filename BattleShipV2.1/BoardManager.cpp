#include "BoardManager.h"
#include <iostream>

Board* Player;
Board* AI;
Board* Radar;
Tile* board[10][10];

BoardManager* BoardManager::bmInstance = nullptr;

BoardManager* BoardManager::Instance()
{
	if (bmInstance == nullptr)
	{
		bmInstance = new BoardManager();
	}
	return bmInstance;
}

BoardManager::BoardManager()
{

	Player = new Board();
	AI = new Board();
	Radar = new Board();

	Player->boardTex->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

}

BoardManager::~BoardManager()
{

}

void BoardManager::Update()
{
	
}

void BoardManager::LateUpdate()
{
}

void BoardManager::Render()
{

}

void BoardManager::Release()
{
	delete bmInstance;
	bmInstance = nullptr;
}

Board::Board()
{
	board[10][10] = new Tile;
	boardTex = new Texture("BShipGrid.jpg");

	Row = sizeof board / sizeof board[0];
	Col = sizeof board[0] / sizeof board[0][0];

	//PlayerBoard
	for (int row = 0; row < Row; row++)
	{
		for (int col = 0; col < Col; col++)
		{

			//board[row][col]->SetTileType(TileType::Water);
			//board[row][col]->SetRow(row);
		}
		for (int row = 0; row < Row; row++)
		{
			for (int col = 0; col < Col; col++)
			{
				//board[row][col]->SetCol(col);;
			}
		}
	}
}


void Tile::SetRow(int i)
{
	i = tileRow;
}

void Tile::SetCol(int i)
{
	i = tileCol;
}


Board::~Board()
{

}

void Board::Release()
{
	
}

TileType Tile::SetTileType(TileType tiletype)
{
	type = tiletype;
	return type;
}

//
//Row = sizeof board / sizeof board[0];
//Col = sizeof board[0] / sizeof board[0][0];
//
//for (int row = 0; row < Row; row++)
//{
//	for (int col = 0; col < Col; col++)
//	{
//		SetRow(board[row][col], Row);
//		SetCol(board[row][col], Col);
//		SetTileType(TileType::Water);
//	}
//}

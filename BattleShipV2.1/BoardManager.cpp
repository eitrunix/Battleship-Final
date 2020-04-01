#include "BoardManager.h"
#include "Tile.h"
#include <iostream>

Board* Player;
Board* AI;
Board* Radar;

Tile* PlayerBoard[10][10];
Tile* AiBoard[10][10];

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
	PlayerBoard[10][10]->Render();
}

void BoardManager::Release()
{
	delete bmInstance;
	bmInstance = nullptr;
}

Board::Board()
{
	PlayerBoard[10][10] = new Tile;
	AiBoard[10][10] = new Tile;
	boardTex = new Texture("BShipGrid.jpg");

	Row = sizeof PlayerBoard / sizeof PlayerBoard[0];
	Col = sizeof PlayerBoard[0] / sizeof PlayerBoard[0][0];

	//PlayerBoard

	//for (int row = 0; row < Row; row++)
	//{
	//	for (int col = 0; col < Col; col++)
	//	{
	//	}
	//	for (int row = 0; row < Row; row++)
	//	{
	//		for (int col = 0; col < Col; col++)
	//		{

	//		}
	//	}
	//}

	Row = sizeof AiBoard / sizeof AiBoard[0];
	Col = sizeof AiBoard[0] / sizeof AiBoard[0][0];

	//AIBoard

	//for (int row = 0; row < Row; row++)
	//{
	//	for (int col = 0; col < Col; col++)
	//	{
	//	}
	//	for (int row = 0; row < Row; row++)
	//	{
	//		for (int col = 0; col < Col; col++)
	//		{

	//		}
	//	}
	//}
}





Board::~Board()
{

}

void Board::Release()
{
	
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

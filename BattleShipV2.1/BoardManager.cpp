#include "BoardManager.h"
#include <iostream>

BoardManager* BoardManager::bmInstance = nullptr;

BoardManager* BoardManager::Instance()
{
	if (bmInstance == nullptr)
	{
		bmInstance = new BoardManager();
	}
	return bmInstance;
}

Board PlayerBoard[10][10];
Board PlayerRadar[10][10];
Board CompBoard[10][10];

int playerRow = sizeof PlayerBoard / sizeof PlayerBoard[0];
int playerCol = sizeof PlayerBoard[0] / sizeof PlayerBoard[0][0];

int playerRadarRow = sizeof PlayerRadar / sizeof PlayerRadar[0];
int playerRadarCol = sizeof PlayerRadar[0] / sizeof PlayerRadar[0][0];

int compRow = sizeof CompBoard / sizeof CompBoard[0];
int compCol = sizeof CompBoard[0] / sizeof CompBoard[0][0];



void BoardManager::LateUpdate()
{
}

void BoardManager::Render()
{

}

BoardManager::BoardManager()
{


	//PlayerBoard
	for (int row = 0; row < playerRow; row++)
	{
		for (int col = 0; col < playerCol; col++)
		{
			PlayerBoard[row][col].SetTileType(TileType::Water);
			PlayerBoard[row][col].tileRow = row;
		}
		for (int row = 0; row < playerRow; row++)
		{
			for (int col = 0; col < playerCol; col++)
			{
				PlayerBoard[row][col].tileCol = col;
			}
		}
	}

	//PlayerRadar
	for (int row = 0; row < playerRadarRow; row++)
	{
		for (int col = 0; col < playerRadarCol; col++)
		{
			PlayerRadar[row][col].SetTileType(TileType::Water);
			PlayerRadar[row][col].tileRow = row;
		}
		for (int row = 0; row < playerRadarRow; row++)
		{
			for (int col = 0; col < playerRadarCol; col++)
			{
				PlayerRadar[row][col].tileCol = col;
			}
		}
	}
	//CompBoard
	for (int row = 0; row < compRow; row++)
	{
		for (int col = 0; col < compCol; col++)
		{
			CompBoard[row][col].SetTileType(TileType::Water);
			CompBoard[row][col].tileRow = row;
		}
		for (int row = 0; row < compRow; row++)
		{
			for (int col = 0; col < compCol; col++)
			{
				CompBoard[row][col].tileCol = col;
			}
		}
	}

}

BoardManager::~BoardManager()
{

}


void BoardManager::Release()
{
	delete bmInstance;
	bmInstance = nullptr;
}


void Board::SetTileType(TileType tiletype)
{
	type = tiletype;
}

void BoardManager::Update()
{
	
}

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

AnimatedTexture* waterTileTex;
AnimatedTexture* hitTileTex;
AnimatedTexture* missTileTex;


void BoardManager::LateUpdate()
{
}

void BoardManager::Render()
{

}

BoardManager::BoardManager()
{
	//Texture Setup
	waterTileTex = new AnimatedTexture("SpriteSheet.png", 204, 45, 40, 38, 4, 0.5f, AnimatedTexture::Horizontal);
	hitTileTex = new AnimatedTexture("SpriteSheet.png", 204, 45, 40, 38, 4, 0.5f, AnimatedTexture::Horizontal);
	missTileTex = new AnimatedTexture("SpriteSheet.png", 204, 45, 40, 38, 4, 0.5f, AnimatedTexture::Horizontal);

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
	//std::cout << "Done" << std::endl;
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

void Board::UpdateTile(Board board[10][10])
{
	int tempRow = sizeof board / sizeof board[0];
	int tempCol = sizeof board[0] / sizeof board[0][0];

	for (int row = 0; row < tempRow; row++)
	{
		for (int col = 0; col < tempCol; col++)
		{
			if (board[row][col].type == TileType::Water)
			{
				board[row][col].defTileTex = waterTileTex;
			}
			if (board[row][col].type == TileType::Hit)
			{
				board[row][col].defTileTex = hitTileTex;

			}
			if (board[row][col].type == TileType::Miss)
			{
				board[row][col].defTileTex = missTileTex;

			}
			if (board[row][col].type == TileType::Ship)
			{
				//If ship, find the Piece that triggered the TileType to switch to Ship, get that pieces texture for that space, and apply it instead.
			}


		}
	}


}
void BoardManager::Update()
{
	
}

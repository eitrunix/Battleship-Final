#include "GameScreen.h"

GameScreen::GameScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();
	mScoreBoard = new ScoreBoard();
	pBoard = new BattleshipBoard();
	pRadar = new BattleshipBoard();
	mPlayerManager = PlayerManager::Instance();

	/// Play Area ///
	mPlayerOneArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);
	mPlayerTwoArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);
	mInputArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.8);
	Board = new Texture("BShipGrid.jpg");
	Radar = new Texture("BShipGrid.jpg");
	defaultText = new Texture(" ", "ARCADE.ttf", 32, { 200, 0, 0 });
	invalidAttack = new Texture("Attack Again in a Valid Location", "ARCADE.ttf", 32, { 200, 0, 0 });
	invalidPlacement = new Texture("Place in a Valid Location", "ARCADE.ttf", 32, { 200, 0, 0 });

	validAttack = false;
	allShipsPlaced = false;

	// Player Boards
	mPlayerOneArea->Parent(this);
	mPlayerTwoArea->Parent(this);
	mInputArea->Parent(this);

	Board->Parent(mPlayerOneArea);
	Radar->Parent(mPlayerTwoArea);
	invalidAttack->Parent(mInputArea);
	invalidPlacement->Parent(mInputArea);

	pRadar->BoardPosSet(cBoatdYOffset, cBoardXOffset);
	pBoard->BoardPosSet(pBoatdYOffset, pBoardXOffset);

	// Positions 
	Board->Position(boardYPosOffset, boardXPosOffset);
	Radar->Position(radarYPosOffset, boardXPosOffset);
	invalidAttack->Position(0.0f, 20.0f);
	invalidPlacement->Position(0.0f, 20.0f);
	ChangeBoardState(BoardState::PlaceShips);



}

void GameScreen::Update()
{
	if (playerShips == 5)
	{
		allShipsPlaced = true;
	}

	switch (bState)
	{
		//case BoardState::Title:
		//	break;
	case BoardState::PlaceShips:

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{
			MousePos(pOffsetX);
			if (xIndex <= 9 && yIndex <= 9 && xIndex >= 0 && yIndex >= 0)
			{
				PlayerPlaceShips(xIndex, yIndex);
			}

		}
		if (allShipsPlaced)
		{
			ChangeBoardState(BoardState::MakeAttack);
			allShipsPlaced = false;
		}

		break;
	case BoardState::MakeAttack:

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{
			MousePos(rOffsetX);
			if (xIndex <= 9 && yIndex <= 9 && xIndex >= 0 && yIndex >= 0)
			{
				if (bState == BoardState::MakeAttack)
				{
					bool tempOccu;
					tempOccu = pRadar->GetIsOccupied(xIndex, yIndex);
					if (tempOccu)
					{
						pRadar->ChangeTile(xIndex, yIndex, TileType::Hit);
					}
					else
					{
						pRadar->ChangeTile(xIndex, yIndex, TileType::Miss);
					}
					validAttack = true;
				}
			}
			else
			{
				defaultText = invalidAttack;
				std::cout << "Attack Again in a Valid Location" << std::endl;
			}
		}
		if (validAttack == true)
		{
			ChangeBoardState(BoardState::AIAttack);
			validAttack = false;

		}
		break;

	case BoardState::AIAttack:
		std::cout << "AI Attacked randomly" << std::endl; 
		ChangeBoardState(BoardState::MakeAttack);
		break;

	}

}

void GameScreen::PlayerPlaceShips(int x, int y)
{
	if (Itr == nullptr)
		Itr = mPlayerManager->pieces.begin();
	Piece* p = *Itr;
		if (p->ID == playerShips && playerShips < 5)
		{
			if (TexItr == nullptr)
				TexItr = p->parts.begin();

			if (bState == BoardState::PlaceShips && !pBoard->GetIsOccupied(xIndex, yIndex))
			{
				int pieceHealth = p->health;
				if (!horizontal)
				{

					for (int i = 0; i < pieceHealth; i++)
					{
						pBoard->SetTileOccupied(xIndex, yIndex, true);
						pBoard->ChangeTile(xIndex, yIndex, TileType::Ship);
						pBoard->gameBoard[xIndex][yIndex]->ShipTex = *TexItr;
						xIndex++;
						TexItr++;
					}
				}
				else
				{
					for (int i = 0; i < pieceHealth; i++)
					{
						pBoard->SetTileOccupied(xIndex, yIndex, true);
						pBoard->ChangeTile(xIndex, yIndex, TileType::Ship);
						pBoard->gameBoard[xIndex][yIndex]->ShipTex = *TexItr; 
						yIndex++;
						TexItr++;
					}

				}
				//Itr++;

				//p->placed = true;
				std::cout << "Number of Player Ships, I check this vs the Ships ID, if they are the same thats the ship that is placed." << std::endl;
				std::cout << "shipNumber = " + std::to_string(playerShips) << std::endl;
				std::cout << "Ship ID = " + std::to_string(p->ID) << std::endl;
			}
			else if (bState != BoardState::PlaceShips && mousePos.x < (Graphics::SCREEN_WIDTH * 0.5))
			{
				defaultText = invalidPlacement;
				std::cout << "Cant Place that there" << std::endl;
			}
			Itr++;
			playerShips++;

		}
		//Itr++;
		//playerShips++;
	//}

}

void GameScreen::ChangeBoardState(BoardState newState)
{
	bState = newState;
}

void GameScreen::MousePos(int offset)
{
	mousePos = mInputManager->MousePosition() * (boardSize);
	int xOffset = offset;
	int yOffset = pOffsetY;

	float newPosX = ((mousePos.x / gridWidth) * gridWidth) - xOffset;
	float newPosY = ((mousePos.y / gridHeight) * gridHeight) - yOffset;

	xIndex = (newPosX / (gridWidth * cols)) * cols;
	yIndex = (newPosY / (gridHeight * rows)) * rows;

	//std::cout << xIndex << " = X " << std::endl;
	//std::cout << yIndex << " = Y " << std::endl;

}

void GameScreen::Render()
{
	mScoreBoard->Render();
	pBoard->Render();
	pRadar->Render();
	defaultText->Render();
}

GameScreen::~GameScreen()
{

	delete mPlayerOneArea;
	delete mPlayerTwoArea;
	delete Board;
	delete Radar;
	delete mScoreBoard;
	delete pBoard;
	delete pRadar;

	mScoreBoard = nullptr;
	mPlayerOneArea = nullptr;
	mPlayerTwoArea = nullptr;
	Board = nullptr;
	Radar = nullptr;
	pBoard = nullptr;
	pRadar = nullptr;
}

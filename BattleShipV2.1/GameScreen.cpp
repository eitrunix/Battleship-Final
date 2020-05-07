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
	blankText = new Texture(" ", "ARCADE.ttf", 32, { 200, 0, 0 });
	invalidAttack = new Texture("Attack Again in a Valid Location", "ARCADE.ttf", 32, { 200, 0, 0 });
	invalidPlacement = new Texture("Place in a Valid Location", "ARCADE.ttf", 32, { 200, 0, 0 });
	Horizontal = new Texture("Horizontal", "ARCADE.ttf", 32, { 200, 0, 0 });
	Vertical = new Texture("Vertical", "ARCADE.ttf", 32, { 200, 0, 0 });

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
	blankText->Parent(mInputArea);
	Horizontal->Parent(mInputArea);
	Vertical->Parent(mInputArea);

	pRadar->BoardPosSet(cBoatdYOffset, cBoardXOffset);
	pBoard->BoardPosSet(pBoatdYOffset, pBoardXOffset);

	// Positions 
	Board->Position(boardYPosOffset, boardXPosOffset);
	Radar->Position(radarYPosOffset, boardXPosOffset);
	invalidAttack->Position(0.0f, 20.0f);
	invalidPlacement->Position(0.0f, 20.0f);
	Horizontal->Position(0.0f, 20.0f);
	Vertical->Position(0.0f, 20.0f);
	blankText->Position(0.0f, 20.0f);


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
	case BoardState::PlaceShips:
		//std::cout << "PlaceShips" << std::endl;
		if (mInputManager->KeyPressed(SDL_SCANCODE_TAB) && !horizontal)
		{
			horizontal = true;
			defaultText = Horizontal;

		}
		else if (mInputManager->KeyPressed(SDL_SCANCODE_TAB) && horizontal)
		{
			horizontal = false;
			defaultText = Vertical;
		}

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{
			MousePos(pOffsetX);
			if (xIndex <= 9 && yIndex <= 9 && xIndex >= 0 && yIndex >= 0)
			{
				defaultText = blankText;
				PlayerPlaceShips();
			}
			else
			{
				defaultText = invalidPlacement;
				std::cout << "Place Again in a Valid Location" << std::endl;
			}

		}
		if (allShipsPlaced)
		{
			ChangeBoardState(BoardState::AIPlaceShips);
			allShipsPlaced = false;
		}

		break;
	case BoardState::MakeAttack:
		//std::cout << "MakeAttack" << std::endl;

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{
			PlayerAttack();
		}
		if (validAttack == true)
		{
			ChangeBoardState(BoardState::AIAttack);
			validAttack = false;

		}
		break;

	case BoardState::AIAttack:
		//std::cout << "AIAttack" << std::endl;

		//std::cout << "AI Attacked randomly" << std::endl; 
		AIAttack();

		if (validAttack)
		{
			ChangeBoardState(BoardState::MakeAttack);
			validAttack = false;
		}
		break;
	case BoardState::AIPlaceShips:
		//std::cout << "AIPlaceShips" << std::endl;

		AIPlaceShips();
		if (aiShips >= 5)
		{
			ChangeBoardState(BoardState::MakeAttack);
		}
		break;
	}

}

void GameScreen::PlayerPlaceShips()
{
	if (Itr == nullptr)
		Itr = mPlayerManager->pieces.begin();
	Piece* p = *Itr;
		if (p->ID == playerShips && playerShips <= 5)
		{

			if (bState == BoardState::PlaceShips && !pBoard->GetIsOccupied(xIndex, yIndex))
			{
				int pieceHealth = p->health;
				if (!horizontal)
				{
					if (TexItr == nullptr)
						TexItr = p->hParts.begin();
					for (int i = 0; i < pieceHealth; i++)
					{
						pBoard->SetTileOccupied(xIndex, yIndex, true);
						pBoard->ChangeTile(xIndex, yIndex, TileType::Ship);

						pBoard->gameBoard[xIndex][yIndex]->ShipTex = *TexItr;

						if (pBoard->gameBoard[xIndex][yIndex]->ShipTex != nullptr)
						{
							p->xPos = xIndex;
							p->yPos = yIndex;
							xIndex++;
							TexItr++;
							validPlace = true;
							//std::cout << p->xPos << std::endl;
							//std::cout << p->yPos << std::endl;

						}
						else
						{
							defaultText = invalidPlacement;
							validPlace = false;
							pBoard->gameBoard[xIndex][yIndex]->isOccupied = false;
							pBoard->ChangeTile(xIndex, yIndex, TileType::Water);
						}
					}
				}
				else
				{
					if (TexItr == nullptr)
						TexItr = p->vParts.begin();

					for (int i = 0; i < pieceHealth; i++)
					{
						pBoard->SetTileOccupied(xIndex, yIndex, true);
						pBoard->ChangeTile(xIndex, yIndex, TileType::Ship);

						pBoard->gameBoard[xIndex][yIndex]->ShipTex = *TexItr;

						if (pBoard->gameBoard[xIndex][yIndex]->ShipTex != nullptr)
						{
							p->xPos = xIndex;
							p->yPos = yIndex;
							yIndex++;
							TexItr++;
							validPlace = true;
							//std::cout << p->xPos << std::endl;
							//std::cout << p->yPos << std::endl;

						}
						else
						{
							defaultText = invalidPlacement;
							validPlace = false;							
							pBoard->gameBoard[xIndex][yIndex]->isOccupied = false;
							pBoard->ChangeTile(xIndex, yIndex, TileType::Water);
						}
					}
				}
			}
			if (validPlace && playerShips <=5)
			{
			Itr++;
			playerShips++;
			}
		}
}

void GameScreen::AIPlaceShips()
{	
	int x = (rand() % 10) + 1;
	int y = (rand() % 10) + 1;  
	
	if (Itr == nullptr)
		Itr = mPlayerManager->Aipieces.begin();
	Piece* p = *Itr;
	if (p->ID == aiShips && aiShips < 5)
	{
		if (TexItr == nullptr)
			TexItr = p->hParts.begin();

		if (bState == BoardState::AIPlaceShips && !pRadar->GetIsOccupied(x, y) && !pRadar->GetIsOccupied(x + p->health, y + p->health))
		{
			int pieceHealth = p->health;
			if (!horizontal)
			{

				for (int i = 0; i < pieceHealth; i++)
				{
					if (x + p->health <= 9)
					{
						x - p->health;
						pRadar->SetTileOccupied(x, y, true);
						p->xPos = x;
						p->yPos = y;
						x++;
						validPlace = true;
						std::cout << p->xPos << std::endl;
						std::cout << p->yPos << std::endl;
					}
					else
					{
						defaultText = invalidPlacement;
						validPlace = false;
						pRadar->gameBoard[xIndex][yIndex]->isOccupied = false;
						pRadar->ChangeTile(xIndex, yIndex, TileType::Water);
					}
				}
			}
			else
			{
				for (int i = 0; i < pieceHealth; i++)
				{
					if (y + p->health <= 9)
					{
						y - p->health;
						pRadar->SetTileOccupied(x, y, true);
						p->xPos = x;
						p->yPos = y;
						y++;
						validPlace = true;
						std::cout << p->xPos << std::endl;
						std::cout << p->yPos << std::endl;

					}
					else
					{
						defaultText = invalidPlacement;
						validPlace = false;
						pRadar->gameBoard[xIndex][yIndex]->isOccupied = false;
					}

				}

			}

		}
		if (validPlace)
		{
			Itr++;
			aiShips++;
		}

	}
}

void GameScreen::AIAttack()
{

	int x = rand() % 10;
	int y = rand() % 10;
	xIndex = x;
	yIndex = y;
	bool tempOccu;
	tempOccu = pBoard->GetIsOccupied(xIndex, yIndex);
	if (pBoard->gameBoard[x][y]->ReturnTileType() != TileType::Hit || pBoard->gameBoard[x][y]->ReturnTileType() != TileType::Miss)
	{
		if (tempOccu)
		{
			if (Itr == nullptr)
				Itr = mPlayerManager->pieces.begin();
			Piece* p = *Itr;
			pBoard->ChangeTile(xIndex, yIndex, TileType::Hit);

			for (Itr; Itr != nullptr; Itr++)
			{
				if (xIndex == p->getTileXPos() && yIndex == p->getTileYPos())
				{
					p->health - 1;
				}
			}
		}
		else
		{
			pBoard->ChangeTile(xIndex, yIndex, TileType::Miss);
		}
		validAttack = true;
		mScoreBoard->SetHealth();
	}
	else
	{
		std::cout << "Invalid AI Attack" << std::endl;
		validAttack = false;
	}
}

void GameScreen::PlayerAttack()
{
	if (Itr == nullptr)
		Itr = mPlayerManager->Aipieces.begin();
	Piece* p = *Itr;

	MousePos(rOffsetX);
	defaultText = blankText;
	if (xIndex <= 9 && yIndex <= 9 && xIndex >= 0 && yIndex >= 0)
	{
		if (bState == BoardState::MakeAttack)
		{
			bool tempOccu;
			tempOccu = pRadar->GetIsOccupied(xIndex, yIndex);
			if (tempOccu)
			{
				for (Itr; Itr != nullptr; Itr++)
				{
					if (xIndex == p->xPos && yIndex == p->yPos)
					{
						pRadar->ChangeTile(xIndex, yIndex, TileType::Hit);
						p->OnHit();
					}

				}

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
	mScoreBoard->SetHealth();

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

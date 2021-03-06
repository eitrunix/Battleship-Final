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
	playerHealth = 0;
	aiHealth = 0;

	ChangeBoardState(BoardState::PlaceShips);

	std::cout << "Player: " + std::to_string(playerHealth) << std::endl;
	std::cout << "AI : " + std::to_string(aiHealth) << std::endl;

}

void GameScreen::Update()
{
	if (!sGameOver)
	{
		if (mInputManager->KeyPressed(SDL_SCANCODE_B))
		{
			aiHealth -= 1;
			std::cout << aiHealth << std::endl;
		}
		if (playerShips == 5)
		{
			allShipsPlaced = true;
		}
		CheckWinCon();

		switch (bState)
		{
		case BoardState::PlaceShips:
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
			AIAttack();

			if (validAttack)
			{
				ChangeBoardState(BoardState::MakeAttack);
				validAttack = false;
			}
			break;
		case BoardState::AIPlaceShips:

			AIPlaceShips();
			if (aiShips >= 5)
			{
				aiShipsPlaced = true;
				ChangeBoardState(BoardState::MakeAttack);
			}
			break;
		case BoardState::GameOver:
			sGameOver = true;
			active = false;
			break;
		}
	}
}

void GameScreen::PlayerPlaceShips()
{
	if (Itr == nullptr)
	{
		Itr = mPlayerManager->pieces.begin();
	}

	Piece* p = *Itr;

	if (p->ID == playerShips && playerShips <= 5)
	{
		if (bState == BoardState::PlaceShips && !pBoard->GetIsOccupied(xIndex, yIndex))
		{
			int pieceHealth = p->health;
			if (horizontal)
			{
				if (xIndex + p->health <= 10)
				{
					for (int i = 0; i < pieceHealth; i++)
					{
						if (TexItr == nullptr)
						{
							TexItr = p->hParts.begin();
						}
						pBoard->SetTileOccupied(xIndex, yIndex, true);
						pBoard->ChangeTile(xIndex, yIndex, TileType::Ship);

						pBoard->gameBoard[xIndex][yIndex]->ShipTex = *TexItr;

						if (pBoard->gameBoard[xIndex][yIndex]->ShipTex != nullptr)
						{
							p->xPos = xIndex;
							p->yPos = yIndex;
							xIndex++;
							TexItr++;
							playerHealth++;
							validPlace = true;
						}
					}
				}
				else
				{
					defaultText = invalidPlacement;
					validPlace = false;
					pBoard->gameBoard[xIndex][yIndex]->isOccupied = false;
					pBoard->ChangeTile(xIndex, yIndex, TileType::Water);
				}
			}
			else if (!horizontal)
			{
				if (TexItr == nullptr)
				{
					TexItr = p->vParts.begin();
				}
				if (yIndex + p->health <= 10)
				{

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
							playerHealth++;
							validPlace = true;
						}
					}
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
		if (validPlace && playerShips <= 5)
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

		if (bState == BoardState::AIPlaceShips && !pRadar->GetIsOccupied(x, y))
		{
			int pieceHealth = p->health;
			if (horizontal)
			{
				if (x + p->health <= 9)
				{
					for (int i = 0; i < pieceHealth; i++)
					{
						pRadar->SetTileOccupied(x, y, true);
						p->xPos = x;
						p->yPos = y;
						x++;							
						aiHealth++;
						validPlace = true;
					}
				}
				else
				{
					defaultText = invalidPlacement;
					validPlace = false;
					pRadar->gameBoard[xIndex][yIndex]->isOccupied = false;
					pRadar->ChangeTile(xIndex, yIndex, TileType::Water);
				}
			}
			else if (!horizontal)
			{
				if (y + p->health <= 9)
				{
					for (int i = 0; i < pieceHealth; i++)
					{
						pRadar->SetTileOccupied(x, y, true);
						p->xPos = x;
						p->yPos = y;
						y++;
						aiHealth++;
						validPlace = true;
					}
				}
				else
				{
					defaultText = invalidPlacement;
					validPlace = false;
					pRadar->gameBoard[xIndex][yIndex]->isOccupied = false;
				}
			}
			if (validPlace)
			{
				Itr++;
				aiShips++;
			}
		}
	}
}

void GameScreen::AIAttack()
{
	int x = rand() % 10;
	int y = rand() % 10;
	bool tempOccu;
	tempOccu = pBoard->GetIsOccupied(x, y);
	if (pBoard->ReturnTileType(x,y) == TileType::Water || pBoard->ReturnTileType(x,y) == TileType::Ship)
	{
		if (tempOccu)
		{
			pBoard->ChangeTile(x, y, TileType::Hit);
			playerHealth -= 1;
			std::cout << "Player Health : " + std::to_string(playerHealth) << std::endl;
		}
		else
		{
			pBoard->ChangeTile(x, y, TileType::Miss);
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
			if (pRadar->ReturnTileType(xIndex, yIndex) == TileType::Water || pRadar->ReturnTileType(xIndex, yIndex) == TileType::Ship)
			{

				tempOccu = pRadar->GetIsOccupied(xIndex, yIndex);
				if (tempOccu)
				{
					pRadar->ChangeTile(xIndex, yIndex, TileType::Hit);				
					aiHealth -= 1;
					std::cout << "Ai Health : " + std::to_string(aiHealth) << std::endl;
				}
				else
				{
					pRadar->ChangeTile(xIndex, yIndex, TileType::Miss);
				}
				validAttack = true;
				//mScoreBoard->SetHealth();

			}
			else
			{
				validAttack = false;
				defaultText = invalidAttack;
				std::cout << "Attack Again in a Valid Location" << std::endl;
			}
		}
	}
	else
	{
		validAttack = false;
		defaultText = invalidAttack;
		std::cout << "Attack Again in a Valid Location" << std::endl;
	}
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
}

void GameScreen::CheckWinCon()
{
	if (playerHealth == 0 && allShipsPlaced && aiShipsPlaced)
	{
		aiWin = true;
		ChangeBoardState(BoardState::GameOver);
	}
	else if (aiHealth == 0 && allShipsPlaced && aiShipsPlaced)
	{
		playerWin = true;
		ChangeBoardState(BoardState::GameOver);
	}
}

void GameScreen::Render()
{
	if (active)
	{
		mScoreBoard->Render();
		pBoard->Render();
		pRadar->Render();
		defaultText->Render();
	}
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

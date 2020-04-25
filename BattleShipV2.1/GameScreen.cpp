#include "GameScreen.h"

GameScreen::GameScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();
	mScoreBoard = ScoreBoard::Instance();
	pBoard = new BattleshipBoard();
	pRadar = new BattleshipBoard();

	/// Play Area ///
	mPlayerOneArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);
	mPlayerTwoArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);
	Board = new Texture("BShipGrid.jpg");
	Radar = new Texture("BShipGrid.jpg");

	// Player Boards
	mPlayerOneArea->Parent(this);
	mPlayerTwoArea->Parent(this);
	Board->Parent(mPlayerOneArea);
	Radar->Parent(mPlayerTwoArea);

	pRadar->BoardPosSet(cBoatdYOffset, cBoardXOffset);
	pBoard->BoardPosSet(pBoatdYOffset, pBoardXOffset);

	// Positions 
	Board->Position(-230.0f, 40.0f);
	Radar->Position(230.0f, 40.0f);

	bState = BoardState::PlaceShips;
}


void GameScreen::changeBoardState(BoardState newState)
{
	bState = newState;
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

void GameScreen::Update()
{
	switch (bState)
	{
	//case BoardState::Title:
	//	break;
	case BoardState::PlaceShips:

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{

			mousePos = mInputManager->MousePosition() * (boardSize);
			if (mousePos.x < (Graphics::SCREEN_WIDTH * 0.5));
			{
			int xOffset = pOffsetX;
			int yOffset = pOffsetY;

			float newPosX = ((mousePos.x / gridWidth) * gridWidth) - xOffset;
			float newPosY = ((mousePos.y / gridHeight) * gridHeight) - yOffset;

			int xIndex = (newPosX / (gridWidth * cols)) * cols;
			int yIndex = (newPosY / (gridHeight * rows)) * rows;

			std::cout << xIndex << " = X " << std::endl;
			std::cout << yIndex << " = Y " << std::endl;
			if (bState == BoardState::PlaceShips)

			{
				pBoard->ChangeTile(xIndex, yIndex, true);

			}
			else
			{
				std::cout << "Cant attack that" << std::endl;
			}

			bState = BoardState::MakeAttack;
			}
		}
	case BoardState::MakeAttack:

		if (mInputManager->MouseButtonPressed(mInputManager->Left))
		{
			mousePos = mInputManager->MousePosition() * (boardSize);
			if (mousePos.x > ((Graphics::SCREEN_WIDTH * 0.6) + gridWidth));
			{
				int xOffset = rOffsetX;
				int yOffset = pOffsetY;

				float newPosX = ((mousePos.x / gridWidth) * gridWidth) - xOffset;
				float newPosY = ((mousePos.y / gridHeight) * gridHeight) - yOffset;

				int xIndex = (newPosX / (gridWidth * cols)) * cols;
				int yIndex = (newPosY / (gridHeight * rows)) * rows;

				std::cout << xIndex << " = X " << std::endl;
				std::cout << yIndex << " = Y " << std::endl;
				if (bState == BoardState::MakeAttack)
				{
					pRadar->ChangeTile(xIndex, yIndex, true);
				}
			}
		}

	}
}

void GameScreen::Render()
{
	mScoreBoard->Render();
	pBoard->Render();
	pRadar->Render();

}

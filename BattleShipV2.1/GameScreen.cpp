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
	if (mInputManager->MouseButtonPressed(mInputManager->Left))
	{
		mousePos = mInputManager->MousePosition() * (boardSize);

		int xOffset = pOffsetX;
		int yOffset = pOffsetY;
		
		int widthScreen = Graphics::SCREEN_WIDTH;
		if (mousePos.x > 5100)
		{
			xOffset = rOffsetX;
		}

		float newPosX = ((mousePos.x / gridWidth) * gridWidth) - xOffset;
		float newPosY = ((mousePos.y / gridHeight) * gridHeight) - yOffset;

		int xIndex = (newPosX / (gridWidth * cols)) * cols;
		int yIndex = (newPosY / (gridHeight * rows)) * rows;

		std::cout << xIndex << " = X " << std::endl;
		std::cout << yIndex << " = Y " << std::endl;

		pBoard->ChangeTile(xIndex, yIndex, true);
	}
	if (mInputManager->KeyPressed(SDL_SCANCODE_A))
	{
		pBoard->ChangeTile(2, 2, true);
		pBoard->ChangeTile(3, 2, true);
		pBoard->ChangeTile(4, 2, true);
		pBoard->ChangeTile(6, 2, true);
		pBoard->ChangeTile(7, 2, true);
		pBoard->ChangeTile(8, 2, true);
		pBoard->ChangeTile(9, 2, true);
	}
}

void GameScreen::Render()
{
	mScoreBoard->Render();
	pBoard->Render();
	pRadar->Render();

}

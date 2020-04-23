#include "GameScreen.h"

GameScreen::GameScreen()
{
	mTimer = Timer::Instance();
	//mMouse = MouseControl::Instance();
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

	pRadar->BoardPosSet(297.0f, 550.0f);
	pBoard->BoardPosSet(297.0f, 91.5f);

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
		mousePos = mInputManager->MousePosition();
		std::cout << mousePos.x << " = X " << std::endl;
		std::cout << mousePos.y << " = Y" << std::endl;
	}
	if (mInputManager->KeyPressed(SDL_SCANCODE_A))
	{
		pBoard->ChangeTile(2, 2, true);
	}
}

void GameScreen::Render()
{
	mScoreBoard->Render();
	pBoard->Render();
	pRadar->Render();

}

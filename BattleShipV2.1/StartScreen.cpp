#include "StartScreen.h"

StartScreen::StartScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTitleArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 80.0f);
	tTitle = new Texture("BattleShip", "ARCADE.ttf", 32, {200, 0, 0});

	mTitleArea->Parent(this);
	tTitle->Parent(mTitleArea);

	tTitle->Position(-30.0f, 0.0f);
}

StartScreen::~StartScreen()
{
	delete mTitleArea;
	delete tTitle;
	
	mTitleArea = nullptr;
	tTitle = nullptr;

	mTimer = nullptr;
	mInputManager = nullptr;
}

void StartScreen::Update()
{
}

void StartScreen::Render()
{
	mTitleArea->Render();
	tTitle->Render();
}

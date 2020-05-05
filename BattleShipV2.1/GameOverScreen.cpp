#include "GameOverScreen.h"


GameOverScreen::GameOverScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();
	winLoss = new Texture("You Win/Lose, I dunno yet", "ARCADE.ttf", 32, { 200, 0,0 });
	backToStart = new Texture("Press ESC to go back to start", "ARCADE.ttf", 32, { 200, 0,0 });
	gameScreen = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);

	gameScreen->Parent(this);
	gameScreen->Position(0, 0);
	
	winLoss->Parent(gameScreen);
	backToStart->Parent(gameScreen);

	winLoss->Position(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.35);
	backToStart->Position(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * .4);

}

GameOverScreen::~GameOverScreen()
{
	winLoss = nullptr;
	backToStart = nullptr;
	gameScreen = nullptr;

	delete winLoss;
	delete backToStart;
	delete gameScreen;

}

void GameOverScreen::Update()
{
	if (mInputManager->KeyPressed(SDL_SCANCODE_ESCAPE))
	{
		sTitle = true;
	}
}

void GameOverScreen::Render()
{
	winLoss->Render();
	backToStart->Render();
	gameScreen->Render();
}


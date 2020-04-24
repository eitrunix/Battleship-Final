#include "StartScreen.h"

StartScreen::StartScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTitleArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 80.0f);
	mBoatsArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 200.0f);
	tTitle = new Texture("BattleShip", "ARCADE.ttf", 64, {200, 0, 0});

	tStart = new Texture("Start", "ARCADE.ttf", 32, { 200, 0, 0 });
	tInstructs = new Texture("Instructions", "ARCADE.ttf", 32, { 200, 0, 0 });
	tQuit = new Texture("Quit", "ARCADE.ttf", 32, { 200, 0, 0 });

	//aBoat1 = new AnimatedTexture("AircraftCarrier.png", 0, 0, 100, 43, 1, 1, 0);   // <----- This a bitch

	aBoat1 = new Texture("AircraftCarrier.png");
	aBoat2 = new Texture("Cruiser.png");
	aBoat3 = new Texture("BattleShip.png");
	aBoat4 = new Texture("Submarine.png");
	aBoat5 = new Texture("PatrolBoat.png");

	mTitleArea->Parent(this);
	mBoatsArea->Parent(this);

	aBoat1->Parent(mBoatsArea);
	aBoat2->Parent(mBoatsArea);
	aBoat3->Parent(mBoatsArea);
	aBoat4->Parent(mBoatsArea);
	aBoat5->Parent(mBoatsArea);

	tTitle->Parent(mTitleArea);
	tStart->Parent(mTitleArea);
	tInstructs->Parent(mTitleArea);
	tQuit->Parent(mTitleArea);

	aBoat1->Position(0.0f, 0.0f);
	aBoat2->Position(0.0f, 30.0f);
	aBoat3->Position(0.0f, 60.0f);
	aBoat4->Position(0.0f, 90.0f);
	aBoat5->Position(0.0f, 120.0f);

	tTitle->Position(0.0f, 0.0f);
	tStart->Position(0.0f, 710.0f);
	tInstructs->Position(0.0f, 730.0f);
	tQuit->Position(0.0f, 750.0f);
}

StartScreen::~StartScreen()
{
	delete mTitleArea;
	delete tTitle;
	delete tStart;
	delete tInstructs;
	delete tQuit;

	delete aBoat1;
	delete aBoat2;
	delete aBoat3;
	delete aBoat4;
	delete aBoat5;

	mTitleArea = nullptr;
	tTitle = nullptr;
	tStart = nullptr;
	tInstructs = nullptr;
	tQuit = nullptr;

	aBoat1 = nullptr;
	aBoat2 = nullptr;
	aBoat3 = nullptr;
	aBoat4 = nullptr;
	aBoat5 = nullptr;

	mTimer = nullptr;
	mInputManager = nullptr;
}

void StartScreen::Update()
{
	if (mInputManager->KeyPressed(SDL_SCANCODE_A))
	{
		PlayGame = true;
	}
}

void StartScreen::Render()
{
	mTitleArea->Render();
	tTitle->Render();
	tStart->Render();
	tInstructs->Render();
	tQuit->Render();
	aBoat1->Render();
	aBoat2->Render();
	aBoat3->Render();
	aBoat4->Render();
	aBoat5->Render();

}

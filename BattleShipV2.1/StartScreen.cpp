#include "StartScreen.h"

StartScreen::StartScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	mTitleArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 80.0f);
	mBoatsArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 200.0f);
	mInstructsArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 80.0f);

	tTitle = new Texture("BattleShip", "ARCADE.ttf", TITLE_TEXT_SIZE, {200, 0, 0});

	tStart = new Texture("Press ENTER to Start", "ARCADE.ttf", TEXT_SIZE, { 200, 0, 0 });
	tInstructs = new Texture("Press I for Instructions", "ARCADE.ttf", TEXT_SIZE, { 200, 0, 0 });
	tQuit = new Texture("Quit", "ARCADE.ttf", TEXT_SIZE, { 200, 0, 0 });

	aBoat1 = new Texture("AircraftCarrier.png");
	aBoat2 = new Texture("Cruiser.png");
	aBoat3 = new Texture("BattleShip.png");
	aBoat4 = new Texture("Submarine.png");
	aBoat5 = new Texture("PatrolBoat.png");

	tInstructions1 = new Texture("Welcome to Battleship", "ARCADE.ttf", TITLE_TEXT_SIZE, { 200, 0 , 0 });
	tInstructions2 = new Texture("The Goal of the game is to sink your opponents 5 ships,", "ARCADE.ttf", INST_TEXT_SIZE, { 200, 0 , 0 });
	tInstructions3 = new Texture("while hiding your own ships to protect them!", "ARCADE.ttf", INST_TEXT_SIZE, { 200, 0 , 0 });
	tInstructions4 = new Texture("Use the Keyboard to inpt a Letter and Number cooresponding to the grid position", "ARCADE.ttf", INST_TEXT_SIZE, { 200, 0 , 0 });
	tInstructions5 = new Texture("You will be prompted on each phase on the actions you can take, Good Luck!", "ARCADE.ttf", INST_TEXT_SIZE, { 200, 0 , 0 });
	tInstructions6 = new Texture("Press Escape to go back to the menu", "ARCADE.ttf", INST_TEXT_SIZE, { 200, 0 , 0 });


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
	aBoat2->Position(0.0f, 40.0f);
	aBoat3->Position(0.0f, 80.0f);
	aBoat4->Position(0.0f, 120.0f);
	aBoat5->Position(0.0f, 160.0f);

	tTitle->Position(0.0f, 0.0f);
	tStart->Position(0.0f, 710.0f);
	tInstructs->Position(0.0f, 730.0f);

	mInstructsArea->Parent(this);
	tInstructions1->Parent(mInstructsArea);
	tInstructions2->Parent(mInstructsArea);
	tInstructions3->Parent(mInstructsArea);
	tInstructions4->Parent(mInstructsArea);
	tInstructions5->Parent(mInstructsArea);
	tInstructions6->Parent(mInstructsArea);

	tInstructions1->Position(0.0f, 0.0f);
	tInstructions2->Position(0.0f, 60.0f);
	tInstructions3->Position(0.0f, 80.0f);
	tInstructions4->Position(0.0f, 100.0f);
	tInstructions5->Position(0.0f, 120.0f);
	tInstructions6->Position(0.0f, 240.0f);

	tQuit->Position(0.0f, 750.0f);
}

StartScreen::~StartScreen()
{
	delete mTitleArea;
	delete tTitle;
	delete tStart;
	delete tInstructs;
	delete tQuit;
	delete mInstructsArea;
	delete mBoatsArea;
	delete tInstructions1;
	delete tInstructions2;
	delete tInstructions3;
	delete tInstructions4;
	delete tInstructions5;
	delete tInstructions6;

	delete aBoat1;
	delete aBoat2;
	delete aBoat3;
	delete aBoat4;
	delete aBoat5;

	mTitleArea = nullptr;
	mBoatsArea = nullptr;
	mInstructsArea = nullptr;
	tInstructions1 = nullptr;
	tInstructions2 = nullptr;
	tInstructions3 = nullptr;
	tInstructions4 = nullptr;
	tInstructions5 = nullptr;
	tInstructions6 = nullptr;

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
	if (mInputManager->KeyPressed(SDL_SCANCODE_RETURN) && displayInstructions == false)
	{
		PlayGame = true;
	}
	if (mInputManager->KeyPressed(SDL_SCANCODE_I))
	{
		displayInstructions = true;
	}
	if (mInputManager->KeyPressed(SDL_SCANCODE_ESCAPE))
	{
		displayInstructions = false;
	}
}

void StartScreen::Render()
{
	if (!displayInstructions)
	{
		aBoat1->Render();
		aBoat2->Render();
		aBoat3->Render();
		aBoat4->Render();
		aBoat5->Render();

		mTitleArea->Render();
		tTitle->Render();
		tStart->Render();
		tInstructs->Render();
		tQuit->Render();
	}

	if (displayInstructions)
	{
	tInstructions1->Render();
	tInstructions2->Render();
	tInstructions3->Render();
	tInstructions4->Render();
	tInstructions5->Render();
	tInstructions6->Render();

	}

}

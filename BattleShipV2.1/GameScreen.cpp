#include "GameScreen.h"

GameScreen::GameScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

	/// Play Area ///
	mPlayerOneArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.2, Graphics::SCREEN_HEIGHT * 0.5);
	mPlayerTwoArea = new GameEntity(Graphics::SCREEN_WIDTH * 0.8, Graphics::SCREEN_HEIGHT * 0.5);
	Board = new Texture("BShipGrid.jpg");
	Radar = new Texture("BShipGrid.jpg");

	mPlayerOneArea->Parent(this);
	mPlayerTwoArea->Parent(this);
	Board->Parent(mPlayerOneArea);
	Radar->Parent(mPlayerTwoArea);

	/// Scoreboard ///

	mScoreBoard = new GameEntity(Graphics::SCREEN_WIDTH * 0.8, 80.0f);
	mP1Score = new GameEntity(Graphics::SCREEN_WIDTH * 0.2, Graphics::SCREEN_HEIGHT * 0.5);
	mP2Score = new GameEntity(Graphics::SCREEN_WIDTH * 0.8, Graphics::SCREEN_HEIGHT * 0.5);

	sbPatrolBoat = new Texture("PatrolBoat.png");
	sbCruiser = new Texture("Cruiser.png");
	sbSubmarine = new Texture("Submarine.png");
	sbACCarrier = new Texture("AircraftCarrier.png");
	sbBattleShip = new Texture("BattleShip.png");

	sbP2PatrolBoat = new Texture("PatrolBoat.png");
	sbP2Cruiser = new Texture("Cruiser.png");
	sbP2Submarine = new Texture("Submarine.png");
	sbP2ACCarrier = new Texture("AircraftCarrier.png");
	sbP2BattleShip = new Texture("BattleShip.png");

	tPatrolBoathealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tSubhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tCruiserhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tACCarrierhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tBattleshiphealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });

	tP2PatrolBoathealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tP2Subhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tP2Cruiserhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tP2ACCarrierhealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });
	tP2Battleshiphealth = new Texture("0", "ARCADE.ttf", 32, { 200, 0, 0 });

	mScoreBoard->Parent(this);

	mP1Score->Parent(mScoreBoard);
	mP2Score->Parent(mScoreBoard);

	sbPatrolBoat->Parent(mP1Score);
	sbCruiser->Parent(mP1Score);
	sbSubmarine->Parent(mP1Score);
	sbACCarrier->Parent(mP1Score);
	sbBattleShip->Parent(mP1Score);

	sbPatrolBoat->Position(0, 0);
	sbCruiser->Position(0, 10);
	sbSubmarine->Position(0, 20);
	sbACCarrier->Position(0, 30);
	sbBattleShip->Position(0, 40);

	sbP2PatrolBoat->Parent(mP2Score);
	sbP2Cruiser->Parent(mP2Score);
	sbP2Submarine->Parent(mP2Score);
	sbP2ACCarrier->Parent(mP2Score);
	sbP2BattleShip->Parent(mP2Score);

	sbP2PatrolBoat->Position(0, 0);
	sbP2Cruiser->Position(0, 10);
	sbP2Submarine->Position(0, 20);
	sbP2ACCarrier->Position(0, 30);
	sbP2BattleShip->Position(0, 40);

	tPatrolBoathealth->Parent(mP1Score);
	tSubhealth->Parent(mP1Score);
	tCruiserhealth->Parent(mP1Score);
	tACCarrierhealth->Parent(mP1Score);
	tBattleshiphealth->Parent(mP1Score);

	tPatrolBoathealth->Position(10, 0);
	tSubhealth->Position(10, 10);
	tCruiserhealth->Position(10, 20);
	tACCarrierhealth->Position(10, 30);
	tBattleshiphealth->Position(10, 40);

	tP2PatrolBoathealth->Parent(mP2Score);
	tP2Subhealth->Parent(mP2Score);
	tP2Cruiserhealth->Parent(mP2Score);
	tP2ACCarrierhealth->Parent(mP2Score);
	tP2Battleshiphealth->Parent(mP2Score);
	
	tP2PatrolBoathealth->Position(10, 0);
	tP2Subhealth->Position(10, 10);
	tP2Cruiserhealth->Position(10, 20);
	tP2ACCarrierhealth->Position(10, 30);
	tP2Battleshiphealth->Position(10, 40);

}

GameScreen::~GameScreen()
{

	delete mPlayerOneArea;
	delete mPlayerTwoArea;
	delete Board;
	delete Radar;

	delete mScoreBoard;
	delete mP1Score;
	delete mP2Score;

	delete sbPatrolBoat;
	delete sbCruiser;
	delete sbSubmarine;
	delete sbACCarrier;
	delete sbBattleShip;

	delete sbP2PatrolBoat;
	delete sbP2Cruiser;
	delete sbP2Submarine;
	delete sbP2ACCarrier;
	delete sbP2BattleShip;

	delete tPatrolBoathealth;
	delete tSubhealth;
	delete tCruiserhealth;
	delete tACCarrierhealth;
	delete tBattleshiphealth;

	delete tP2PatrolBoathealth;
	delete tP2Subhealth;
	delete tP2Cruiserhealth;
	delete tP2ACCarrierhealth;
	delete tP2Battleshiphealth;


	mPlayerOneArea = nullptr;
	mPlayerTwoArea = nullptr;
	Board = nullptr;
	Radar = nullptr;

	mScoreBoard = nullptr;
	mP1Score = nullptr;
	mP2Score = nullptr;

	sbPatrolBoat = nullptr;
	sbCruiser = nullptr;
	sbSubmarine = nullptr;
	sbACCarrier = nullptr;
	sbBattleShip = nullptr;

	sbP2PatrolBoat = nullptr;
	sbP2Cruiser = nullptr;
	sbP2Submarine = nullptr;
	sbP2ACCarrier = nullptr;
	sbP2BattleShip = nullptr;

	tPatrolBoathealth = nullptr;
	tSubhealth = nullptr;
	tCruiserhealth = nullptr;
	tACCarrierhealth = nullptr;
	tBattleshiphealth = nullptr;

	tP2PatrolBoathealth = nullptr;
	tP2Subhealth = nullptr;
	tP2Cruiserhealth = nullptr;
	tP2ACCarrierhealth = nullptr;
	tP2Battleshiphealth = nullptr;
}

void GameScreen::Update()
{
}

void GameScreen::Render()
{
	mPlayerOneArea->Render();
	mPlayerTwoArea->Render();
	Board->Render();
	Radar->Render();

	mScoreBoard->Render();
	mP1Score->Render();
	mP2Score->Render();

	sbPatrolBoat->Render();
	sbCruiser->Render();
	sbSubmarine->Render();
	sbACCarrier->Render();
	sbBattleShip->Render();

	sbP2PatrolBoat->Render();
	sbP2Cruiser->Render();
	sbP2Submarine->Render();
	sbP2ACCarrier->Render();
	sbP2BattleShip->Render();

	tPatrolBoathealth->Render();
	tSubhealth->Render();
	tCruiserhealth->Render();
	tACCarrierhealth->Render();
	tBattleshiphealth->Render();

	tP2PatrolBoathealth->Render();
	tP2Subhealth->Render();
	tP2Cruiserhealth->Render();
	tP2ACCarrierhealth->Render();
	tP2Battleshiphealth->Render();


}

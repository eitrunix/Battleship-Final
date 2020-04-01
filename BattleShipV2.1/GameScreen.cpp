#include "GameScreen.h"

GameScreen::GameScreen()
{
	mTimer = Timer::Instance();
	mInputManager = InputManager::Instance();

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

	// Positions 

	Board->Position(-230.0f, 40.0f);
	Radar->Position(230.0f, 40.0f);

	/// Scoreboard ///

	mScoreBoard = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, 80.0f);
	mP1Score = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);
	mP2Score = new GameEntity(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);

	P1Name = new Texture("Player 1", "ARCADE.ttf", 32, { 200, 0, 0 });
	P2Name = new Texture("AI", "ARCADE.ttf", 32, { 200, 0, 0 });

	//scBackground = new Texture("");

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

	P1Name->Parent(mP1Score);
	P2Name->Parent(mP2Score);

	sbPatrolBoat->Parent(mP1Score);
	sbCruiser->Parent(mP1Score);
	sbSubmarine->Parent(mP1Score);
	sbACCarrier->Parent(mP1Score);
	sbBattleShip->Parent(mP1Score);

	sbP2PatrolBoat->Parent(mP2Score);
	sbP2Cruiser->Parent(mP2Score);
	sbP2Submarine->Parent(mP2Score);
	sbP2ACCarrier->Parent(mP2Score);
	sbP2BattleShip->Parent(mP2Score);

	tPatrolBoathealth->Parent(sbPatrolBoat);
	tSubhealth->Parent(sbSubmarine);
	tCruiserhealth->Parent(sbCruiser);
	tACCarrierhealth->Parent(sbACCarrier);
	tBattleshiphealth->Parent(sbBattleShip);

	tP2PatrolBoathealth->Parent(sbP2PatrolBoat);
	tP2Subhealth->Parent(sbP2Submarine); 
	tP2Cruiserhealth->Parent(sbP2Cruiser);
	tP2ACCarrierhealth->Parent(sbP2ACCarrier);
	tP2Battleshiphealth->Parent(sbP2BattleShip);

	//Scoreboard Section Positions
	mScoreBoard->Position(200.0f, 20.0f);
	mP1Score->Position(60.0f, 30.0f);
	mP2Score->Position(570.0f, 30.0f);

	P1Name->Position(10.0f, -30.0f);
	P2Name->Position(0.0f, -30.0f);

	// Scoreboard Parts Positioning (Width, Height) Relative to Parent
	//// Images 
	sbPatrolBoat->Position(-48.7f, 0.0f);
	sbSubmarine->Position(-34.0f, 40);
	sbCruiser->Position(-34.0f, 80);
	sbACCarrier->Position(-0.5f, 120);
	sbBattleShip->Position(-16.6f, 160);

	sbP2PatrolBoat->Position(48.7f, 0.0f);
	sbP2Submarine->Position(34.0f, 40);
	sbP2Cruiser->Position(34.0f, 80);
	sbP2ACCarrier->Position(0.5f, 120);
	sbP2BattleShip->Position(16.6f, 160);

	// Score Text 
	tPatrolBoathealth->Position(199.0f, 5);
	tSubhealth->Position(184.0f, 5);
	tCruiserhealth->Position(184.0f, 5);
	tACCarrierhealth->Position(150.0f, 5);
	tBattleshiphealth->Position(167.0f, 5);

	tP2PatrolBoathealth->Position(-199.0f, 5);
	tP2Subhealth->Position(-184.0f, 5);
	tP2Cruiserhealth->Position(-184.0f, 5);
	tP2ACCarrierhealth->Position(-150.0f, 5);
	tP2Battleshiphealth->Position(-167.0f, 5);

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

	delete P1Name;
	delete P2Name;

	P1Name = nullptr;
	P2Name = nullptr;

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
	P1Name->Render();
	P2Name->Render();
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

#include "ScoreBoard.h"
ScoreBoard* ScoreBoard::sInstance = nullptr;

ScoreBoard* ScoreBoard::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new ScoreBoard();
	}
	return sInstance;
}

ScoreBoard::ScoreBoard()
{

	/// Scoreboard ///
	mPlayerManager = PlayerManager::Instance();

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

	tPatrolBoathealth = new Health();
	tSubhealth = new Health();
	tCruiserhealth = new Health();
	tACCarrierhealth = new Health();
	tBattleshiphealth = new Health();

	tP2PatrolBoathealth = new Health();
	tP2Subhealth = new Health();
	tP2Cruiserhealth = new Health();
	tP2ACCarrierhealth = new Health();
	tP2Battleshiphealth = new Health();

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
	sbPatrolBoat->Position(0.0f, 0.0f);
	sbSubmarine->Position(0.0f, 40);
	sbCruiser->Position(0.0f, 80);
	sbACCarrier->Position(0.0f, 120);
	sbBattleShip->Position(0.0f, 160);

	sbP2PatrolBoat->Position(0.0f, 0.0f);
	sbP2Submarine->Position(0.0f, 40);
	sbP2Cruiser->Position(0.0f, 80);
	sbP2ACCarrier->Position(0.0f, 120);
	sbP2BattleShip->Position(0.0f, 160);

	// Score Text 
	tPatrolBoathealth->Position(150.0f, 5);
	tSubhealth->Position(150.0f, 5);
	tCruiserhealth->Position(150.0f, 5);
	tACCarrierhealth->Position(150.0f, 5);
	tBattleshiphealth->Position(150.0f, 5);

	tP2PatrolBoathealth->Position(-150.0f, 5);
	tP2Subhealth->Position(-150.0f, 5);
	tP2Cruiserhealth->Position(-150.0f, 5);
	tP2ACCarrierhealth->Position(-150.0f, 5);
	tP2Battleshiphealth->Position(-150.0f, 5);
	UpdateHealth();
}

void ScoreBoard::UpdateHealth()
{
	p1PBH = mPlayerManager->patrolBoat->GetHealth();
	p1SubH = mPlayerManager->submarine->GetHealth();
	p1CruH = mPlayerManager->cruiser->GetHealth();
	p1ACH = mPlayerManager->aircraftCarrier->GetHealth();
	p1BSH = mPlayerManager->battleship->GetHealth();

	p2PBH = mPlayerManager->aipatrolBoat->GetHealth();
	p2SubH = mPlayerManager->aisubmarine->GetHealth();
	p2CruH = mPlayerManager->aicruiser->GetHealth();
	p2ACH = mPlayerManager->aiaircraftCarrier->GetHealth();
	p2BSH = mPlayerManager->aibattleship->GetHealth();

	tPatrolBoathealth->SetHealth(p1PBH);
	tSubhealth->SetHealth(p1SubH);
	tCruiserhealth->SetHealth(p1CruH);
	tACCarrierhealth->SetHealth(p1ACH);
	tBattleshiphealth->SetHealth(p1BSH);

	tP2PatrolBoathealth->SetHealth(p2PBH);
	tP2Subhealth->SetHealth(p2SubH);
	tP2Cruiserhealth->SetHealth(p2CruH);
	tP2ACCarrierhealth->SetHealth(p2ACH);
	tP2Battleshiphealth->SetHealth(p2BSH);
}
ScoreBoard::~ScoreBoard()
{
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
	delete mPlayerManager;

	mPlayerManager = nullptr;

	P1Name = nullptr;
	P2Name = nullptr;
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

void ScoreBoard::Update()
{
}

void ScoreBoard::Render()
{
	P1Name->Render();
	P2Name->Render();
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


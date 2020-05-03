#pragma once
#ifndef __SCOREBOARD_H 
#define __SCOREBOARD_H

#include "AnimatedTexture.h" 
#include "Health.h"
#include "PlayerManager.h"
using namespace SDLFramework;

class ScoreBoard : public GameEntity
{
private:
	static ScoreBoard* sInstance;


	GameEntity* mScoreBoard;

	GameEntity* mP1Score;
	GameEntity* mP2Score;

	Texture* scBackground;

	//Text Names
	Texture* P1Name;
	Texture* P2Name;

	// Images Player Boats
	Texture* sbPatrolBoat;
	Texture* sbCruiser;
	Texture* sbSubmarine;
	Texture* sbACCarrier;
	Texture* sbBattleShip;

	// Images AI Boats
	Texture* sbP2PatrolBoat;
	Texture* sbP2Cruiser;
	Texture* sbP2Submarine;
	Texture* sbP2ACCarrier;
	Texture* sbP2BattleShip;

	// Text Player Boats Health
	Health* tPatrolBoathealth;
	Health* tSubhealth;
	Health* tCruiserhealth;
	Health* tACCarrierhealth;
	Health* tBattleshiphealth;

	// Text AI Boats Health
	Health* tP2PatrolBoathealth;
	Health* tP2Subhealth;
	Health* tP2Cruiserhealth;
	Health* tP2ACCarrierhealth;
	Health* tP2Battleshiphealth;

	int p1PBH, p2PBH;
	int p1SubH, p2SubH;
	int p1CruH, p2CruH;
	int p1ACH, p2ACH;
	int p1BSH, p2BSH;
public:
	PlayerManager* mPlayerManager;

	ScoreBoard();
	~ScoreBoard();

	void Update() override;
	void Render() override;
	void SetHealth();
	void UpdateHealth();
	static ScoreBoard* Instance();
	static void Release();

};

#endif // __SCOREBOARD_H
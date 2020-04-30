#pragma once
#ifndef __SCOREBOARD_H 
#define __SCOREBOARD_H

#include "AnimatedTexture.h" 
#include "PlayerManager.h"

using namespace SDLFramework;

class ScoreBoard : public GameEntity
{
private:
	static ScoreBoard* sInstance;

	PlayerManager* mPlayerManager;

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
	Texture* tPatrolBoathealth;
	Texture* tSubhealth;
	Texture* tCruiserhealth;
	Texture* tACCarrierhealth;
	Texture* tBattleshiphealth;

	// Text AI Boats Health
	Texture* tP2PatrolBoathealth;
	Texture* tP2Subhealth;
	Texture* tP2Cruiserhealth;
	Texture* tP2ACCarrierhealth;
	Texture* tP2Battleshiphealth;

	int p1PBH, p2PBH;
	int p1SubH, p2SubH;
	int p1CruH, p2CruH;
	int p1ACH, p2ACH;
	int p1BSH, p2BSH;
public:

	std::string p1PBText;
	std::string p1SubText;
	std::string p1CruText;
	std::string p1ACText;
	std::string p1BSText;

	std::string p2PBText;
	std::string p2SubText;
	std::string p2CruText;
	std::string p2ACText;
	std::string p2BSText;
		

	ScoreBoard();
	~ScoreBoard();

	void Update() override;
	void Render() override;
	void UpdateHealth();
	static ScoreBoard* Instance();
	static void Release();

};

#endif // __SCOREBOARD_H
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

	int p1PBH = 00, p2PBH = 00;
	int p1SubH = 00, p2SubH = 00;
	int p1CruH = 00, p2CruH = 00;
	int p1ACH = 00, p2ACH = 00;
	int p1BSH = 00, p2BSH = 00;
public:

	std::string p1PBText = std::to_string(p1PBH);
	std::string p1SubText = std::to_string(p1SubH);
	std::string p1CruText = std::to_string(p1CruH);
	std::string p1ACText = std::to_string(p1ACH);
	std::string p1BSText = std::to_string(p1BSH);

	std::string p2PBText = std::to_string(p2PBH);
	std::string p2SubText = std::to_string(p2SubH);
	std::string p2CruText = std::to_string(p2CruH);
	std::string p2ACText = std::to_string(p2ACH);
	std::string p2BSText = std::to_string(p2BSH);



	ScoreBoard();
	~ScoreBoard();

	void Update() override;
	void Render() override;
	void UpdateHealth();
	static ScoreBoard* Instance();
	static void Release();

};

#endif // __SCOREBOARD_H
#pragma once
#ifndef __SCOREBOARD_H 
#define __SCOREBOARD_H

#include "AnimatedTexture.h" 

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

public:
	ScoreBoard();
	~ScoreBoard();

	void Update() override;
	void Render() override;

	static ScoreBoard* Instance();
	static void Release();

};

#endif // __SCOREBOARD_H
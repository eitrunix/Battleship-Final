#pragma once
#ifndef __GAMESCREEN_H 
#define __GAMESCREEN_H
#include "AnimatedTexture.h" 
#include "InputManager.h"
using namespace SDLFramework;

class GameScreen : public GameEntity
{
private:
	Timer* mTimer;
	InputManager* mInputManager;

	GameEntity* mPlayerOneArea;
	GameEntity* mPlayerTwoArea;
	Texture* Board;
	Texture* Radar;
	
	GameEntity* mScoreBoard;
	GameEntity* mP1Score;
	GameEntity* mP2Score;

	Texture* sbPatrolBoat;
	Texture* sbCruiser;
	Texture* sbSubmarine;
	Texture* sbACCarrier;
	Texture* sbBattleShip;	

	Texture* sbP2PatrolBoat;
	Texture* sbP2Cruiser;
	Texture* sbP2Submarine;
	Texture* sbP2ACCarrier;
	Texture* sbP2BattleShip;

	Texture* tPatrolBoathealth;
	Texture* tSubhealth;
	Texture* tCruiserhealth;
	Texture* tACCarrierhealth;
	Texture* tBattleshiphealth;	

	Texture* tP2PatrolBoathealth;
	Texture* tP2Subhealth;
	Texture* tP2Cruiserhealth;
	Texture* tP2ACCarrierhealth;
	Texture* tP2Battleshiphealth;
public:
	GameScreen();
	~GameScreen();

	void Update() override;
	void Render() override;

};

#endif // __GAMESCREEN_H
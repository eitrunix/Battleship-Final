#pragma once
#include "Piece.h"
#include "Player.h"
#include "AI.h"
#include "LinkList.h"

using namespace DataStructuresAndAI;
// HealthManager - Gets Health Values and sets them for the game, then use this to change values in game
 // Knows the total number of ships pieces to check for the win con, as well as if pieces are destroyed or not
 // keeps track of the current health of each ship a player has 


class HealthManager
{
private:
	static HealthManager* sInstance;

public:
	HealthManager(Player player1, AI player2);
	~HealthManager();

	static HealthManager* Instance();
	static void Release();

	int P2PiecesAmt;
	int P1PiecesAmt;
	bool GameOver;
	bool CheckWinCon();
	void GetHealth();

	int aiPBhealth;
	int aiSubHealth;
	int aiCrusHealth;
	int aiACHealth;
	int aiBSHealth;

	int playerPBhealth;
	int playerSubHealth;
	int playerCrusHealth;
	int playerACHealth;
	int playerBSHealth;


	void ResetItr_Player();
	void ResetItr_AI();
	int TakeHit(int _value, int _target);
};


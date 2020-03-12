#pragma once

class HealthManager
{
public:
	HealthManager(Player player1, AI player2);
	~HealthManager();

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

	LinkList<Piece*> pieces;
	LinkList<Piece*>::Iterator itr;

	LinkList<Piece*> Aipieces;

	void ResetItr_Player();
	void ResetItr_AI();
	int TakeHit(int _value, int _target);
};


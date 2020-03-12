#pragma once
#include <string>

using namespace DataStructuresAndAI;

class Scoreboard
{
	public:

	Scoreboard(LinkList<Piece* > &p1ll, LinkList<Piece*> &p2ll);
	~Scoreboard();

	LinkList<Piece* >* player1ll;
	LinkList<Piece* >* player2ll;

	void PrintBoard();
	void GetScore();
	std::string playerName;

	int playerPBhealth;
	int playerSubHealth;
	int playerCrusHealth;
	int playerACHealth;
	int playerBSHealth;

	int aiPBhealth;
	int aiSubHealth;
	int aiCrusHealth;
	int aiACHealth;
	int aiBSHealth;


	void resetIter();

};


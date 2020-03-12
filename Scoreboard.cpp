#include "Scoreboard.h"

#include <stdlib.h>
#include <iostream>
#include <iomanip>

LinkList<Piece*>::Iterator scoreboardItr1;
LinkList<Piece*>::Iterator scoreboardItr2;
LinkList<Piece*>::Iterator scoreboardItr3;
LinkList<Piece*>::Iterator scoreboardItr4;

Scoreboard::Scoreboard(LinkList<Piece* > &p1ll, LinkList<Piece* > &p2ll)
{
	player1ll = &p1ll;
	player2ll = &p2ll;
	resetIter();
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::PrintBoard()
{
	system("CLS");
	std::cout << std::setw(80) << playerName << "'s Ship Status" << (char)179 << std::setw(2) << " " << "Computer's Ship Status " << std::endl;
	std::cout << std::setw(60) << (char)201;
	for (int i = 0; i < 40; i++)
	{
		std::cout << (char)205;			// Create a top line to box in the Status "screen"
	}
	// X_size is the number of hits on each ship, so it should print out "| Patrol Boat: 2      |        Patrol Boat: 2 |" for each ship and line respectively
	std::cout << (char)187 << std::endl;

	std::cout << std::setw(60) << (char)186 << "Patrol Boat: " << playerPBhealth << std::setw(7) << (char)179 << std::setw(18) << "Patrol Boat: " << aiPBhealth << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Submarine: " << playerSubHealth << std::setw(9) << (char)179 << std::setw(18) << "Submarine: " << aiSubHealth << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Cruiser: " << playerCrusHealth << std::setw(11) << (char)179 << std::setw(18) << "Crusier: " << aiCrusHealth << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Carrier: " << playerACHealth << std::setw(11) << (char)179 << std::setw(18) << "Carrier: " << aiACHealth << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Battleship: " << playerBSHealth << std::setw(8) << (char)179 << std::setw(18) << "Battleship: " << aiBSHealth << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)200;
	for (int i = 0; i < 40; i++) {
		std::cout << (char)205;			// Bottom line, looping so I dont need to hit (char)205 40 times.
	}
	std::cout << (char)188 << std::endl;

}

void Scoreboard::GetScore()
{
	resetIter();

	for (scoreboardItr1; scoreboardItr1 != nullptr; scoreboardItr1++)
	{
		Piece* p = *scoreboardItr1;
		if (p->name == "PatrolBoat")
		{
			playerPBhealth = p->health;
		}
		if (p->name == "Submarine")
		{
			playerSubHealth = p->health;
		}
		if (p->name == "Cruiser")
		{
			playerCrusHealth = p->health;
		}
		if (p->name == "AircraftCarrier")
		{
			playerACHealth = p->health;
		}
		if (p->name == "Battleship")
		{
			playerBSHealth = p->health;
		}

	}
	for (scoreboardItr2; scoreboardItr2 != nullptr; scoreboardItr2++)
	{
		Piece* p = *scoreboardItr2;
		if (p->name == "PatrolBoat")
		{
			aiPBhealth = p->health;
		}
		if (p->name == "Submarine")
		{
			aiSubHealth = p->health;
		}
		if (p->name == "Cruiser")
		{
			aiCrusHealth = p->health;
		}
		if (p->name == "AircraftCarrier")
		{
			aiACHealth = p->health;
		}
		if (p->name == "Battleship")
		{
			aiBSHealth = p->health;
		}
	}

}

void Scoreboard::resetIter()
{
	scoreboardItr1 = player1ll->begin();
	scoreboardItr2 = player2ll->begin();
}

#include "HealthManager.h"

#include <iostream>
#include <Windows.h>
#include <iomanip>

Battleship* battleship = new Battleship();
AircraftCarrier* aircraftCarrier = new AircraftCarrier();
Cruiser* cruiser = new Cruiser();
Submarine* submarine = new Submarine();
PatrolBoat* patrolBoat = new PatrolBoat();
Battleship* aibattleship = new Battleship();
AircraftCarrier* aiaircraftCarrier = new AircraftCarrier();
Cruiser* aicruiser = new Cruiser();
Submarine* aisubmarine = new Submarine();
PatrolBoat* aipatrolBoat = new PatrolBoat();

//LinkList<Piece*> pieces;
//LinkList<Piece*> Aipieces;
//LinkList<Piece*>::Iterator itr;


HealthManager::HealthManager(Player player1, AI player2)
{
	GameOver = false;
	//pieces.begin();
	//
	//pieces.push_back(battleship);
	//pieces.push_back(aircraftCarrier);
	//pieces.push_back(cruiser);
	//pieces.push_back(submarine);
	//pieces.push_back(patrolBoat);

	//Aipieces.begin();
	//ResetItr_AI();
	//Aipieces.push_back(aibattleship);
	//Aipieces.push_back(aiaircraftCarrier);
	//Aipieces.push_back(aicruiser);
	//Aipieces.push_back(aisubmarine);
	//Aipieces.push_back(aipatrolBoat);

}

HealthManager::~HealthManager()
{

}
void HealthManager::GetHealth()
{
	//ResetItr_Player();
	//Piece* p = *itr;
	//for (itr; itr != nullptr; itr++)
	//{
	//	if (p->ID == 1) 
	//	{
	//		playerPBhealth = p->health;
	//	}
	//	else if (p->ID == 2) 
	//	{
	//		playerSubHealth = p->health;
	//	}
	//	else if (p->ID == 3) 
	//	{
	//		playerCrusHealth = p->health;
	//	}
	//	else if (p->ID == 41) 
	//	{
	//		playerACHealth = p->health;
	//	}
	//	else if (p->ID == 5) 
	//	{
	//		playerBSHealth = p->health;
	//	}
	//	std::cout << " PB: " << playerPBhealth << "  Sub: " << playerSubHealth << "  Crus: " << playerCrusHealth << "  AC: " << playerACHealth << "   BS: " << playerBSHealth << std::endl;
	/*}

	ResetItr_AI();
	Piece* p2 = *itr;
	for (itr; itr != nullptr; itr++)
	{
		if (p2->ID == 1)
		{
			aiPBhealth = p2->health;
		}
		else if (p2->ID == 2)
		{
			aiSubHealth = p2->health;
		}
		else if (p2->ID == 3)
		{
			aiCrusHealth = p2->health;
		}
		else if (p2->ID == 41)
		{
			aiACHealth = p2->health;
		}
		else if (p2->ID == 5)
		{
			aiBSHealth = p2->health;
		}
		std::cout << " PB: " << aiPBhealth << "  Sub: " << aiSubHealth << "  Crus: " << aiCrusHealth << "  AC: " << aiACHealth << "   BS: " << aiBSHealth << std::endl;

	}*/

}
int HealthManager::TakeHit(int _value, int _target)
{
	return 0;
}
void HealthManager::ResetItr_Player()
{
	//itr = pieces.begin();
}
void HealthManager::ResetItr_AI()
{
	//itr = Aipieces.begin();
}
bool HealthManager::CheckWinCon()
{		// For the WinConCheck

	if (P2PiecesAmt == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			Sleep(500);
			std::cout << std::setw(60) << "Player 1, You Won!!!" << std::endl;
			Sleep(500);
			GameOver = true;
		}
	}
	if (P1PiecesAmt == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			Sleep(500);
			std::cout << std::setw(60) << " Player 2, You Won!!!" << std::endl;
			Sleep(500);
			GameOver = true;
		}
	}
	return GameOver;
}

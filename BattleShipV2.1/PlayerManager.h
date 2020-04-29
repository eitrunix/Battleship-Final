#pragma once
#include <string>
#include "Piece.h"
using namespace SDLFramework;
using namespace DataStructuresAndAI;



class PlayerManager : public GameEntity
{
private:
	static PlayerManager* sInstance;

public:

	PlayerManager();
	~PlayerManager();

	LinkList<Piece*> pieces;
	LinkList<Piece*> Aipieces;
	LinkList<Piece*>::Iterator itr;

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

	void Update() override;
	void Render() override;
	void ResetItr_Player();
	void ResetItr_AI();
	static PlayerManager* Instance();
	static void Release();
};


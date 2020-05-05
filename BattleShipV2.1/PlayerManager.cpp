#include "PlayerManager.h"
PlayerManager* PlayerManager::sInstance = nullptr;

PlayerManager::PlayerManager()
{
	pieces.begin();
	pieces.push_back(battleship);
	pieces.push_back(aircraftCarrier);
	pieces.push_back(cruiser);
	pieces.push_back(submarine);
	pieces.push_back(patrolBoat);

	Aipieces.begin();
	Aipieces.push_back(aibattleship);
	Aipieces.push_back(aiaircraftCarrier);
	Aipieces.push_back(aicruiser);
	Aipieces.push_back(aisubmarine);
	Aipieces.push_back(aipatrolBoat);

}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::Update()
{
}

void PlayerManager::Render()
{
}

PlayerManager* PlayerManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new PlayerManager();
	}
	return sInstance;

}

void PlayerManager::Release()
{

}

void PlayerManager::ResetItr_Player()
{
	itr = pieces.begin();
}
void PlayerManager::ResetItr_AI()
{
	itr = Aipieces.begin();
}

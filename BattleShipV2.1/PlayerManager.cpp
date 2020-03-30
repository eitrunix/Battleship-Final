#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
}
PlayerManager* PlayerManager::sInstance = nullptr;

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
	delete sInstance;
	sInstance = nullptr;

}

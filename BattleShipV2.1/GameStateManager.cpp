#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

GameStateManager* GameStateManager::sInstance = nullptr;
GameStateManager* GameStateManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new GameStateManager();
	}
	return sInstance;
}
void GameStateManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}




void GameStateManager::CleanUp()
{

}

void GameStateManager::InitialLoading()
{

}

void GameStateManager::GameStateCheck()
{

}

void GameStateManager::TurnStateCheck()
{

}

void GameStateManager::PrintGame()
{

}

void GameStateManager::SetUp1PGame()
{

}

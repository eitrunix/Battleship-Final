#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

GameStateManager* GameStateManager::Instance()
{
	if (gmInstance == nullptr)
	{
		gmInstance = new GameStateManager();
	}
	return gmInstance;
}

void GameStateManager::Release()
{
	delete gmInstance;
	gmInstance = nullptr;
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

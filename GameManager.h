#pragma once
#include "BoardManager.h"
#include "PlayableManager.h"
// GameManager
// Tells the GameStateManager what stat to change toand when
// Generally this should "Run" the game


class GameManager
{
public:
	BoardManager* boards;
	PlayableManager* players;

	GameManager();
	~GameManager();
};


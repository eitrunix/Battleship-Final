#pragma once
#include "HealthManager.h"
// PlayerManager - Sets up Players for the game to use
//  Sets up a Player with their Shipsand a Name


class PlayableManager
{
public:
	PlayableManager();
	~PlayableManager();

	Player* m_Player;
	AI* m_Ai;

};


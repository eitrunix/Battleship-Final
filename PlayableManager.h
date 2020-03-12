#pragma once
#include "AI.h"
#include "Player.h"

class PlayableManager
{
public:
	PlayableManager();
	~PlayableManager();

	Player* m_Player;
	AI* m_Ai;

};


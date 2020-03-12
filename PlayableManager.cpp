#include "PlayableManager.h"
#include "AI.h"

PlayableManager::PlayableManager()
{
	m_Player = new Player();
	m_Ai = new AI();
}
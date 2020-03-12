#include "GameManager.h"

GameManager::GameManager()
{
	boards = new BoardManager();
	players = new PlayableManager();

}

GameManager::~GameManager()
{
}

#include "GameStateManager.h"

#include <iostream>
#include <Windows.h>
#include <iomanip>



GameStateManager::GameStateManager(int _players, bool _vsAI)
{
	
	numOfPlayers = _players;
	vsAI = _vsAI;
	GameMode::Title;
	//InitialLoading();
	//StateCheck();
	do
	{
		StateCheckPlaying();

	} while (!gameFinished);
	std::cout << "Game Done, Resetting?" << std::endl;
}

GameStateManager* GameStateManager::Instance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = new GameStateManager(numOfPlayers, vsAI);
	}
	return s_Instance;
}
GameStateManager::~GameStateManager()
{
}

void GameStateManager::StateCheckPlaying()
{
	switch (state)
	{
	case GameState::NoGameState:
		break;
	case GameState::Player1Turn:

		// For the WinConCheck
		// Player 1 Turn Start -> Print Board -> Player Attack -> Check Attack -> Place Attack On Board -> Check Win or not -> Next Players Turn;
		PrintGame();
		//players->m_Player->PlayerAttack();

		if (mode == GameMode::SinglePlayerGame)
		{
			GameState::AITurn;
		}
		if (mode == GameMode::MultiPlayerGame)
		{
			GameState::Player2Turn;
		}
		break;

	case GameState::Player2Turn:

		// For the WinConCheck

		//nextState = GameState::Player1Turn;
		//tempState = GameState::Player2Turn;
		//CheckWinCon();
		break;

	case GameState::AITurn:


		PrintGame();
		//players->m_Ai->AIAttack();
		break;

	case GameState::PlacingShips:

		PrintGame();
		//players->m_Player->PlayerPlaceShips();
		//gM->boards->FakeLoadingScreeen();
		//players->m_Ai->AISetShips();
		state = GameState::Player1Turn;
		break;

	case GameState::Loading:

		//gM->boards->FakeLoadingScreeen();
		state = GameState::PlacingShips;
		break;

	case GameState::GameDone:

		mode = GameMode::GameFinished;

	default:

		break;
	}

}
void GameStateManager::StateCheck() 
{
	//gM->boards->PrintBoards();

	
	switch (mode)
	{
	case GameMode::SinglePlayerGame:

		SetUp1PGame();
		StateCheck();

		break;

	case GameMode::MultiPlayerGame:

		break;

	case GameMode::Title:
		
	case GameMode::GameFinished:
		gameFinished = true;
		CleanUp();
		break;

	default:

		break;
	}
}
void GameStateManager::PrintGame()
{
	//sb->PrintBoard();
	//gM->boards->PrintBoards();

}
void GameStateManager::InitialLoading()
{
	if (numOfPlayers == 1)
	{
		mode = GameMode::SinglePlayerGame;
	}
	else if (numOfPlayers == 2)
	{
		mode = GameMode::MultiPlayerGame;
	}
}

void GameStateManager::CleanUp()
{
	////delete  gM->players->m_Player;
	//gM->players->m_Player = NULL;
	//delete gM->players->m_Ai;
	//gM->players->m_Ai = NULL;
	//delete gM->boards;
	//gM->boards = NULL;

}

void GameStateManager::SetUp1PGame()
{

}


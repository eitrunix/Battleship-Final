#include "GameStateManager.h"

#include <iostream>
#include <Windows.h>
#include <iomanip>

Board* board = new Board();
PlayableManager* players = new PlayableManager();

GameStateManager::GameStateManager(int _players, bool _vsAI)
{
	numOfPlayers = _players;
	vsAI = _vsAI;
	InitialLoading();
	StateCheck();
	do
	{
		StateCheckPlaying();

	} while (!gameFinished);
	std::cout << "Game Done, Resetting?" << std::endl;
}
GameStateManager::~GameStateManager()
{
}

void GameStateManager::StateCheckPlaying()
{
	switch (state)
	{
	case GameState::Player1Turn:

		// For the WinConCheck
		// Player 1 Turn Start -> Print Board -> Player Attack -> Check Attack -> Place Attack On Board -> Check Win or not -> Next Players Turn;
		PrintGame();
		players->m_Player->PlayerAttack();

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
		players->m_Ai->AIAttack();
		break;

	case GameState::PlacingShips:

		PrintGame();
		players->m_Player->PlayerPlaceShips();
		board->FakeLoadingScreeen();
		players->m_Ai->AISetShips();
		state = GameState::Player1Turn;
		break;

	case GameState::Loading:

		board->FakeLoadingScreeen();
		state = GameState::PlacingShips;
		break;

	case GameState::GameDone:

		mode = GameMode::GameFinished;

	default:

		break;
	}

}
void GameStateManager::StateCheck() 
{		board->PrintBoards(players->m_Player);

	
	switch (mode)
	{
	case GameMode::SinglePlayerGame:

		SetUp1PGame();
		StateCheck();

		break;

	case GameMode::MultiPlayerGame:

		break;

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
	board->PrintBoards(players->m_Player);

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
	delete  players->m_Player;
	players->m_Player = NULL;
	delete players->m_Ai;
	players->m_Ai = NULL;
	delete board;
	board = NULL;

}

void GameStateManager::SetUp1PGame()
{

}


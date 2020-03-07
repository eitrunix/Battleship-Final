#include "BattleshipGame.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
Board* board = new Board();
Scoreboard* sb;
Scoreboard* sb2Player;

BattleshipGame::BattleshipGame(int _players, bool _vsAI)
{
	numOfPlayers = _players;
	vsAI = _vsAI;
	SetupGame();
	do
	{
		StateCheck();
	} while (!gameFinished);
	std::cout << "Game Done, Resetting?" << std::endl;

	P1PiecesAmt = player->PlayerPieceOnBoard;
	P2PiecesAmt = ai->CompPiecesOnBoard;
}
BattleshipGame::~BattleshipGame()
{
}
void BattleshipGame::StateCheck() 
{		board->PrintBoards(player);

	switch (state)
	{
	case GameState::Player1Turn:

		// For the WinConCheck
		// Player 1 Turn Start -> Print Board -> Player Attack -> Check Attack -> Place Attack On Board -> Check Win or not -> Next Players Turn;
		PrintGame();
		player->PlayerAttack();
		CheckWinCon();
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
		ai->AIAttack();
		CheckWinCon();
		break;

	case GameState::PlacingShips:	

		PrintGame();
		player->PlayerPlaceShips();
		board->FakeLoadingScreeen();
		ai->AISetShips();
		state = GameState::Player1Turn;
		break;

	case GameState::Loading:

		board->FakeLoadingScreeen();
		state = GameState::PlacingShips;
		break;

	case GameState::GameDone:

		mode = GameMode::Finished;

	default:

		break;
	}
}
void BattleshipGame::PrintGame()
{
	sb->PrintBoard();
	board->PrintBoards(player);

}
void BattleshipGame::SetupGame()
{
	if (numOfPlayers == 1)
	{
		mode = GameMode::SinglePlayerGame;
	}
	else if (numOfPlayers == 2)
	{
		mode = GameMode::MultiPlayerGame;
	}
	switch (mode)
	{
	case GameMode::SinglePlayerGame:
		player = new Player();
		ai = new AI(*player);
		sb = new Scoreboard(player->pieces, ai->Aipieces);
		state = GameState::Loading;
		StateCheck();
		break;

	case GameMode::MultiPlayerGame:
		mpPlayer1 = new Player();
		player2 = new Player();
		sb2Player = new Scoreboard(mpPlayer1->pieces, player2->pieces);
		break;

	case GameMode::Finished:
		gameFinished = true;

		delete player;
		player = NULL;
		delete ai;
		ai = NULL;
		delete sb;
		sb = NULL;
		delete mpPlayer1;
		mpPlayer1 = NULL;
		delete player2;
		player2 = NULL;
		delete sb2Player;
		sb2Player = NULL;
		delete board;
		board = NULL;

		break;

	default:

		break;
	}


}

void BattleshipGame::CheckWinCon()
{		// For the WinConCheck
	PrintGame();

	if (P2PiecesAmt == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			Sleep(500);
			std::cout << std::setw(60) << "Player 1, " << player->name << ", You Won!!!" << std::endl;
			Sleep(500);
			state = GameState::GameDone;
		}
	}
	if (P1PiecesAmt == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			Sleep(500);
			std::cout << std::setw(60) << " Player 2, " << player2->name << ", You Won!!!" << std::endl;
			Sleep(500);
			state = GameState::GameDone;

		}
	}
}

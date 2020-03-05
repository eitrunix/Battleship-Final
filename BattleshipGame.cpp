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

}

BattleshipGame::~BattleshipGame()
{
}

void BattleshipGame::StateCheck() 
{
	switch (state)
	{
	case GameState::Player1Turn:
		board->PrintBoards(player);
		player->PlayerAttack();

		break;
	case GameState::Player2Turn:
		board->PrintBoards(player2);

		break;
	case GameState::AITurn:
		board->PrintBoards(player);

		break;
	case GameState::PlacingShips:
		board->PrintBoards(player);
		player->PlayerPlaceShips();
		board->FakeLoadingScreeen();
		ai->AISetShips();
		state = GameState::Player1Turn;
		break;
	case GameState::Loading:
		board->FakeLoadingScreeen();
		state = GameState::PlacingShips;
		break;
	case GameState::CheckWinCon:

		if (player->PieceOnBoard_Comp == 0)
		{
			for (int i = 0; i < 6; i++)
			{
				system("CLS");
				for (int i = 0; i < 19; i++)
				{
					std::cout << std::endl;
				}
				Sleep(500);
				std::cout << std::setw(60) << player->name << " ,You Won!!!" << std::endl;
				Sleep(500);
			}
		}
	case GameState::Title:
		break;
	default:
		break;
	}
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
	default:
		break;
	}


}
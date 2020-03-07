#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Scoreboard.h"

using namespace DataStructuresAndAI;

Board::Board()
{
	
}
Board::~Board()
{
}
// Board Stuff
void Board::PrintBoards(Player *player)
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;					// Spacing between board and the Ship Status
	}
	std::cout << std::setw(70) << "0   1   2   3   4   5   6   7   8   9" << std::setw(59) << "0   1   2   3   4   5   6   7   8   9" << std::endl;
	std::cout << std::setw(32) << (char)218 << (char)196 << (char)196 << (char)196;					// sets where the Top line will start to print
	for (int j = 0; j < 9; j++)
	{
		std::cout << (char)194 << (char)196 << (char)196 << (char)196;						// First boards Top line
	}
	std::cout << (char)191 << std::setw(20) << (char)218 << (char)196 << (char)196 << (char)196;		// sets spacing between the top of the boards

	for (int n = 0; n < 9; n++)
	{
		std::cout << (char)194 << (char)196 << (char)196 << (char)196;						// Top line of second board
	}
	std::cout << (char)191 << std::endl;

	for (int k = 0; k < 19; k++)
	{
		std::cout << std::setw(30);		// sets the spacing for the board, where it will start to print. changing the number in setw will break everything on the board
		for (int l = 0; l < 23; l++)
		{	// if theres a character set on a board, we will change it to an ASCII Character
			if (player->player_board[k][l] == '*') { std::cout << (char)247 << " "; }
			else if (player->player_board[k][l] == '#') { std::cout << (char)179 << " "; }
			else if (player->player_board[k][l] == '@') { std::cout << (char)195; }
			else if (player->player_board[k][l] == '_') { std::cout << (char)32; }
			else if (player->player_board[k][l] == '-') { std::cout << (char)196 << (char)196 << (char)196; }
			else if (player->player_board[k][l] == '^') { std::cout << (char)197; }
			else if (player->player_board[k][l] == '$') { std::cout << (char)180 << " "; }
			else if (player->player_board[k][l] == 'P') { std::cout << (char)80 << " "; }
			else if (player->player_board[k][l] == 'S') { std::cout << (char)83 << " "; }
			else if (player->player_board[k][l] == 'C') { std::cout << (char)67 << " "; }
			else if (player->player_board[k][l] == 'B') { std::cout << (char)66 << " "; }
			else if (player->player_board[k][l] == 'A') { std::cout << (char)65 << " "; }
			else if (player->player_board[k][l] == '!') { std::cout << (char)33 << " "; }
			else if (player->player_board[k][l] == '$') { std::cout << (char)237 << " "; }
			else if (player->player_board[k][l] == 'a') { std::cout << (char)65; }
			else if (player->player_board[k][l] == 'b') { std::cout << (char)66; }
			else if (player->player_board[k][l] == 'c') { std::cout << (char)67; }
			else if (player->player_board[k][l] == 'd') { std::cout << (char)68; }
			else if (player->player_board[k][l] == 'e') { std::cout << (char)69; }
			else if (player->player_board[k][l] == 'f') { std::cout << (char)70; }
			else if (player->player_board[k][l] == 'g') { std::cout << (char)71; }
			else if (player->player_board[k][l] == 'h') { std::cout << (char)72; }
			else if (player->player_board[k][l] == 'i') { std::cout << (char)73; }
			else if (player->player_board[k][l] == 'j') { std::cout << (char)74; }
		}
		std::cout << std::setw(17); // Adds spaces betweeen the boards
		for (int m = 0; m < 23; m++) {
			if (player->player_atk_radar[k][m] == '*') { std::cout << (char)247 << " "; }
			else if (player->player_atk_radar[k][m] == '#') { std::cout << (char)179 << " "; }
			else if (player->player_atk_radar[k][m] == '@') { std::cout << (char)195; }
			else if (player->player_atk_radar[k][m] == '-') { std::cout << (char)196 << (char)196 << (char)196; }
			else if (player->player_atk_radar[k][m] == '^') { std::cout << (char)197; }
			else if (player->player_atk_radar[k][m] == '$') { std::cout << (char)180 << " "; }
			else if (player->player_atk_radar[k][m] == '!') { std::cout << (char)33 << " "; }
			else if (player->player_atk_radar[k][m] == 'X') { std::cout << (char)237 << " "; }
			else if (player->player_atk_radar[k][m] == '_') { std::cout << (char)32; }
			else if (player->player_atk_radar[k][m] == 'a') { std::cout << (char)65; }
			else if (player->player_atk_radar[k][m] == 'b') { std::cout << (char)66; }
			else if (player->player_atk_radar[k][m] == 'c') { std::cout << (char)67; }
			else if (player->player_atk_radar[k][m] == 'd') { std::cout << (char)68; }
			else if (player->player_atk_radar[k][m] == 'e') { std::cout << (char)69; }
			else if (player->player_atk_radar[k][m] == 'f') { std::cout << (char)70; }
			else if (player->player_atk_radar[k][m] == 'g') { std::cout << (char)71; }
			else if (player->player_atk_radar[k][m] == 'h') { std::cout << (char)72; }
			else if (player->player_atk_radar[k][m] == 'i') { std::cout << (char)73; }
			else if (player->player_atk_radar[k][m] == 'j') { std::cout << (char)74; }
		}
		std::cout << std::endl;
	}

	// Bottom Line for both boards. 
	std::cout << std::setw(32) << (char)192 << (char)196 << (char)196 << (char)196;
	for (int o = 0; o < 9; o++)
	{
		std::cout << (char)193 << (char)196 << (char)196 << (char)196;
	}
	std::cout << (char)217 << std::setw(20) << (char)192 << (char)196 << (char)196 << (char)196;
	for (int p = 0; p < 9; p++)
	{
		std::cout << (char)193 << (char)196 << (char)196 << (char)196;
	}
	std::cout << (char)217 << std::endl << std::endl;
}
void Board::ClearBoard(Player *player)
{
	for (int i = 0; i < 39; i++)
	{
		for (int j = 0; j < 39; j++)
		{		// checks for all symbols used on the map, to change them back to '*'
			if (player->player_board[i][j] == 'P' || player->Comp_board[i][j] == 'P' ||
				player->player_board[i][j] == 'S' || player->Comp_board[i][j] == 'S' ||
				player->player_board[i][j] == 'C' || player->Comp_board[i][j] == 'C' ||
				player->player_board[i][j] == 'A' || player->Comp_board[i][j] == 'A' ||
				player->player_board[i][j] == 'B' || player->Comp_board[i][j] == 'B' ||
				player->player_board[i][j] == '!' || player->player_atk_radar[i][j] == '!' ||
				player->player_board[i][j] == '$' || player->player_atk_radar[i][j] == '$')
			{
				player->player_board[i][j] = '*';
				player->Comp_board[i][j] = '*';
				player->player_atk_radar[i][j] = '*';
			}
		}
	}
	//reset variables to origional numbers
	player->ResetBoard();
}
void Board::FakeLoadingScreeen()
{
	for (int i = 0; i < 4; i++)
	{
		system("CLS");
		system("Color 0C");
		for (int i = 0; i < 18; i++)
		{
			std::cout << std::endl;
		}

		Sleep(500);
		std::cout << std::setw(74) << "Get Ready For Battle....";
		Sleep(500);
		system("Color 08");
	}
}



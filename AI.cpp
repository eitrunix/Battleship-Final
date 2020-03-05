#include "AI.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

Battleship* aibattleship = new Battleship();
AircraftCarrier* aiaircraftCarrier = new AircraftCarrier();
Cruiser* aicruiser = new Cruiser();
Submarine* aisubmarine = new Submarine();
PatrolBoat* aipatrolBoat = new PatrolBoat();


AI::AI(Player Player)
{
	player = &Player;

	comp_atk_row, comp_atk_col;

	valid_comp_ship_pos;	// same as above but for computer
	valid_comp_atk_cord;	// same but for computer
	//AI Attacking
	comp_hv;				// computer ships hoz or vert

	aplha_comp_atk;		// to check the first part of the computers "firing" cords, used to change the number we generate to a letter...its not working wtf???

	Aipieces.push_back(aibattleship);
	Aipieces.push_back(aiaircraftCarrier);
	Aipieces.push_back(aicruiser);
	Aipieces.push_back(aisubmarine);
	Aipieces.push_back(aipatrolBoat);

	Aiitr = Aipieces.begin();

}

AI::~AI()
{
}

void AI::ClearHits()
{
	for (Aiitr; Aiitr != Aipieces.end(); Aiitr++)
	{
		Piece* p = *Aiitr;
		p->health = 0;
		p->hit = false;
	}
}

void AI::AIAttack()
{

	Piece* p = *Aiitr;
	Aiitr = player->pieces.begin();
	{
		// Sets valid_comp_atk_cord to true
		valid_comp_atk_cord = true;
		comp_atk_row = (rand() % 10) * 2;		// Generates a Random even number between 0-8
		comp_atk_col = ((rand() % 10) * 2) + 1;  // Generates a Random ODD number between 1-9
		for (player->itr; player->itr != player->pieces.end(); player->itr++)
		{

			// If the location targeted is P, S, C, A or B. The we know it hit a ship and can move to changing the board
			if (p->name == "PatrolBoat" && p->hit == true)
			{
				if (player->player_board[comp_atk_row][comp_atk_col] == 'P') { AiAttackOnBoard(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (p->name == "Submarine" && p->hit == true)
			{
				if (player->player_board[comp_atk_row][comp_atk_col] == 'S') { AiAttackOnBoard(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (p->name == "Cruiser" && p->hit == true)
			{
				if (player->player_board[comp_atk_row][comp_atk_col] == 'C') { AiAttackOnBoard(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (p->name == "AircraftCarrier" && p->hit == true)
			{
				if (player->player_board[comp_atk_row][comp_atk_col] == 'A') { AiAttackOnBoard(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (p->name == "Battleship" && p->hit == true)
			{
				if (player->player_board[comp_atk_row][comp_atk_col] == 'B') { AiAttackOnBoard(); }
				else { valid_comp_atk_cord = false; }
			}
			if ((p->name == "Battleship" && p->hit == false) && (p->name == "AircraftCarrier" && p->hit == false) && (p->name == "Cruiser" && p->hit == false) && (p->name == "Submarine" && p->hit == false) && (p->name == "PatrolBoat" && p->hit == false))
			{
				AiAttackOnBoard();
			}
		}
	} while (!valid_comp_atk_cord || player->PieceOnBoard_Player > 0);
}

void AI::CheckValidMoveAI()
{
	// checks the array for an empty space '*' to place ships in, its empty we can place the current ships character at the position, this is for the cvomputer so we dont see this
	if (player->Comp_board[compRow][compCol] == '*')
	{
		if (player->comp_ship == 0)
		{
			player->Comp_board[compRow][compCol] = 'P';
		}
		else if (player->comp_ship == 1)
		{
			player->Comp_board[compRow][compCol] = 'S';
		}
		else if (player->comp_ship == 2)
		{
			player->Comp_board[compRow][compCol] = 'C';
		}
		else if (player->comp_ship == 3)
		{
			player->Comp_board[compRow][compCol] = 'A';
		}
		else if (player->comp_ship == 4)
		{
			player->Comp_board[compRow][compCol] = 'B';
		}
		AIHoV(); // same a player. let them place horizontally or vertically
	}
	else {
		valid_comp_ship_pos = false; // if the space isnt empty, try again
	}
}

void AI::AICordsToAlpha()
{
	if (comp_atk_row == 0) { compRow = 'a'; }
	else if (comp_atk_row == 2) { compRow = 'b'; }
	else if (comp_atk_row == 4) { compRow = 'c'; }
	else if (comp_atk_row == 6) { compRow = 'd'; }
	else if (comp_atk_row == 8) { compRow = 'e'; }
	else if (comp_atk_row == 10) { compRow = 'f'; }
	else if (comp_atk_row == 12) { compRow = 'g'; }
	else if (comp_atk_row == 14) { compRow = 'h'; }
	else if (comp_atk_row == 16) { compRow = 'i'; }
	else if (comp_atk_row == 18) { compRow = 'j'; }
}

void AI::AISetShips()
{

	do {
		bool success = true;
		// clear the screen, makes it look like a 'loading screen' a bit... Probably shouldnt do it this way tbh but it works
		system("CLS");
		for (int i = 0; i < 19; i++)
		{
			std::cout << std::endl;
		}
		std::cout << std::setw(90) << "Waiting For Computer To Set Ships On It's Board.......";

		valid_comp_ship_pos = true;			// sets to true at start, in is_comp_move_valid we may change it back to run this again but the numbers generated suck
		srand(time(0));
		if (success)
		{
			compRow = 2 * rand() % 11;			// gets a Random even number
			compCol = 1 + (2 * rand()) % 11;	// gets a Random Odd number
		}
		CheckValidMoveAI();				// checks if the space is a *, a * is a valid space to place a ship
		if (valid_comp_ship_pos == true) {
			player->comp_ship++;
		}
		else
		{
			success = false;
			compCol++;
			if (compCol >= 23 || compRow >= 19)
			{
				success = true;
			}
		}
	} while (player->comp_ship < 5 || !valid_comp_ship_pos);

	// Tell the player the computer is done and ready, and its their turn to place ships
	system("CLS");
	for (int i = 0; i < 19; i++) {
		std::cout << std::endl;
	}
	std::cout << std::setw(90) << "The Computer Has Set It's Ships. Now It's Your Turn.";
	Sleep(3000);
	system("CLS");

}
void AI::AIHoV()
{
	comp_hv = rand() % 2 + 1; // Computer will randomly choose hori or vert
	if (comp_hv == 1)
	{		// this is the same as the players h_or_v but for the Compter.
		if (player->comp_ship == 0 && player->Comp_board[compRow][compCol + 2] == '*')
		{
			player->Comp_board[compRow][compCol + 2] = 'P';
		}
		else if (player->comp_ship == 1 && player->Comp_board[compRow][compCol + 2] == '*' && player->Comp_board[compRow][compCol + 4] == '*')
		{
			player->Comp_board[compRow][compCol + 2] = 'S';
			player->Comp_board[compRow][compCol + 4] = 'S';
		}
		else if (player->comp_ship == 2 && player->Comp_board[compRow][compCol + 2] == '*' && player->Comp_board[compRow][compCol + 4] == '*')
		{
			player->Comp_board[compRow][compCol + 2] = 'C';
			player->Comp_board[compRow][compCol + 4] = 'C';
		}
		else if (player->comp_ship == 3 && player->Comp_board[compRow][compCol + 2] == '*' && player->Comp_board[compRow][compCol + 4] == '*' && player->Comp_board[compRow][compCol + 6] == '*')
		{
			player->Comp_board[compRow][compCol + 2] = 'A';
			player->Comp_board[compRow][compCol + 4] = 'A';
			player->Comp_board[compRow][compCol + 6] = 'A';
		}
		else if (player->comp_ship == 4 && player->Comp_board[compRow][compCol + 2] == '*' && player->Comp_board[compRow][compCol + 4] == '*' && player->Comp_board[compRow][compCol + 6] == '*' && player->Comp_board[compRow][compCol + 8] == '*')
		{
			player->Comp_board[compRow][compCol = 2] = 'B';
			player->Comp_board[compRow][compCol + 4] = 'B';
			player->Comp_board[compRow][compCol + 6] = 'B';
			player->Comp_board[compRow][compCol + 8] = 'B';
		}
		else
		{
			player->Comp_board[compRow][compCol] = '*';
			valid_comp_ship_pos = false;
		}
	}
	else if (comp_hv == 2)
	{
		if (player->comp_ship == 0 && player->Comp_board[compRow + 1][compCol] == '*')
		{
			player->Comp_board[compRow + 1][compCol] = 'P';
		}
		else if (player->comp_ship == 1 && player->Comp_board[compRow + 1][compCol] == '*' && player->Comp_board[compRow + 3][compCol] == '*')
		{
			player->Comp_board[compRow + 1][compCol] = 'S';
			player->Comp_board[compRow + 3][compCol] = 'S';
		}
		else if (player->comp_ship == 2 && player->Comp_board[compRow + 1][compCol] == '*' && player->Comp_board[compRow + 3][compCol] == '*')
		{
			player->Comp_board[compRow + 1][compCol] = 'C';
			player->Comp_board[compRow + 3][compCol] = 'C';
		}
		else if (player->comp_ship == 3 && player->Comp_board[compRow + 1][compCol] == '*' && player->Comp_board[compRow + 3][compCol] == '*' && player->Comp_board[compRow + 5][compCol] == '*')
		{
			player->Comp_board[compRow + 1][compCol] = 'A';
			player->Comp_board[compRow + 3][compCol] = 'A';
			player->Comp_board[compRow + 5][compCol] = 'A';

		}
		else if (player->comp_ship == 4 && player->Comp_board[compRow + 1][compCol] == '*' && player->Comp_board[compRow + 3][compCol] == '*' && player->Comp_board[compRow + 5][compCol] == '*' && player->Comp_board[compRow + 7][compCol] == '*')
		{
			player->Comp_board[compRow + 1][compCol] = 'B';
			player->Comp_board[compRow + 3][compCol] = 'B';
			player->Comp_board[compRow + 5][compCol] = 'B';
			player->Comp_board[compRow + 7][compCol] = 'B';

		}
		else {
			player->Comp_board[compRow][compCol] = '*';
			valid_comp_ship_pos = false;
		}
	}
	system("CLS");
}
void AI::AiAttackOnBoard()
{
	player->itr = player->pieces.begin();
	Piece* p = *player->itr;

	AICordsToAlpha();
	if (player->player_board[comp_atk_row][comp_atk_col] == 'P')
	{
		for (player->itr; player->itr != player->pieces.end(); player->itr++) {
			if (p->name == "PatrolBoat")
			{
				std::cout << std::setw(82) << "The Computer Has Hit Your Patrol Boat: " << aplha_comp_atk << (comp_atk_col / 2) << std::endl << std::endl;

				p->hit = true;
				player->player_board[comp_atk_row][comp_atk_col] = '!';
				player->PieceOnBoard_Player--;
				p->health--;
			}


			else if (player->player_board[comp_atk_row][comp_atk_col] == 'S')
			{

				if (p->name == "Submarine")
				{
					std::cout << std::setw(81) << "The Computer Has Hit Your Submarine: " << aplha_comp_atk << (comp_atk_col / 2) << std::endl << std::endl;
					p->hit = true;
					player->player_board[comp_atk_row][comp_atk_col] = '!';
					player->PieceOnBoard_Player--;
					p->health--;
				}

			}
			else if (player->player_board[comp_atk_row][comp_atk_col] == 'C')
			{

				if (p->name == "Cruiser")
				{
					std::cout << std::setw(81) << "The Computer Has Hit Your Cruiser: " << aplha_comp_atk << (comp_atk_col / 2) << std::endl << std::endl;
					p->hit = true;
					player->player_board[comp_atk_row][comp_atk_col] = '!';
					player->PieceOnBoard_Player--;
					p->health--;
				}

			}
			else if (player->player_board[comp_atk_row][comp_atk_col] == 'A')
			{

				if (p->name == "AircraftCarrier")
				{
					std::cout << std::setw(81) << "The Computer Has Hit Your Aircraft Carrier: " << aplha_comp_atk << (comp_atk_col / 2) << std::endl << std::endl;
					p->hit = true;
					player->player_board[comp_atk_row][comp_atk_col] = '!';
					player->PieceOnBoard_Player--;
					p->health--;
				}

			}
			else if (player->player_board[comp_atk_row][comp_atk_col] == 'B')
			{

				if (p->name == "AircraftCarrier")
				{

					std::cout << std::setw(81) << "The Computer Has Hit Your Battleship: " << aplha_comp_atk << (comp_atk_col / 2) << std::endl << std::endl;
					p->hit = true;
					player->player_board[comp_atk_row][comp_atk_col] = '!';
					player->PieceOnBoard_Player--;
					p->health--;
				}

			}
		}
	}

	else if (player->player_board[comp_atk_row][comp_atk_col] == '*')
	{
		std::cout << std::setw(73) << "The Computer Missed: " << aplha_comp_atk << (comp_atk_row / 2) << std::endl << std::endl;
		player->player_board[comp_atk_row][comp_atk_col] = '$';
	}
	else
	{
		valid_comp_atk_cord = false;
	}

	player->ClearHits();
	ClearHits();

	if (player->PieceOnBoard_Player == 0)
	{
		for (int i = 0; i < 6; i++) {
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			Sleep(500);
			std::cout << std::setw(72) << "The Computer Wins!!!" << std::endl;
			Sleep(500);
		}
		//print_computer_board();
	}
	else if (valid_comp_atk_cord == true)
	{
		Sleep(3000);
		player->PlayerAttack();
	}

}

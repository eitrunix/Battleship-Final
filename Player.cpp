#include "Player.h"
#include "Board.h"
#include "Piece.h"
#include "TitleSceen.h"
#include "AI.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>



void Player::player_place_ships()
{
	do
	{
		// we will go through the 'list' of ships to place, 0-4 (5 ships total) and checks if the placement is okay, 'places' the ship on the board, increments ship_number by 1, then checks the next statement
		// we leave the loop if ship_number is 5 of greater
		valid_ship_pos = true;
		if (ship_number == 0)
		{		// do... do I need to comment these?
			std::cout << std::setw(109) << "Enter The Coordinate For Your Patrol Boat (2 spots): ";
		}
		else if (ship_number == 1)
		{
			std::cout << std::setw(109) << "Enter The Coordinate For Your Submarine (3 spots): ";
		}
		else if (ship_number == 2)
		{
			std::cout << std::setw(108) << "Enter The Coordinate For Your Crusier (4 spots): ";
		}
		else if (ship_number == 3)
		{
			std::cout << std::setw(107) << "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
		}
		else if (ship_number == 4)
		{
			std::cout << std::setw(100) << "Enter the Coordinate For Your Battleship (5 spots): ";
		}
		std::cin.getline(player_ship_cords, 11, '\n');  // Ask for the players input in cords,
		std::cout << std::endl << std::endl;
		check_cords();									// Check if its a valid placement
		Board::print_player_board_and_attack_radar();			// Reprint the new board with the new piece on it.
		if (valid_ship_pos == true)
		{
			ship_number++;								// If we did place a ship, we add to the ship number, so we dont end up placing more ships than we need (0-4)
		}
	} while (!valid_ship_pos || ship_number < 5); //do this while valid_ship_pos is false and the ship number is less than 5
}
void Player::check_cords()
{
	// function to check if the player entered in the correct information or not. should only let letter+number combo eg "A4. While 6A" or "2435234vkj", should come back with please enter valid input
	if (player_ship_cords[0] < 'a' || player_ship_cords[0] > 'j' || player_ship_cords[1] < '0' || player_ship_cords[1] > '9')
	{
		valid_ship_pos = false;					// sets vaild position to false
		Board::print_player_board_and_attack_radar();    // reprint the board
		std::cout << std::setw(97) << "You entered incorrect Coordinates" << std::endl;
		std::cout << std::setw(122) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. Eg = a3" << std::endl;
		Sleep(1000);
	}
	else {
		// Check the values of the rows and colums to match with the input.
		values_of_row_col();
		// check if the position specified is empty or not
		check_for_valid_cell();
	}
}
// Check if the cell or cord entered is the * char in the array, if it is then the space is "empty" and we can place a ship, it will then replace the * char with the cooresponding Letter.
// Placing the Ships Horizontally or Vertically

// The code below is formatted as such so I can read the damn thing easier
// Assign the vales of the colums to the letters, so the computer knows what cords are where

// assigns the values of the players inputs to code so the program can 'check' that space when called 
void Player::player_sets_atk()
{
	do
	{
		valid_atk_cord = true;
		Board::print_player_board_and_attack_radar();
		std::cout << std::setw(76) << "Enter Attack Coordinates: ";
		std::cin.getline(player_atk_cords, 11, '\n');

		check_correct_atk_cords();
		if (Board::comp_piece_on_board == 0)
		{
			for (int i = 0; i < 6; i++)
			{
				system("CLS");
				for (int i = 0; i < 19; i++)
				{
					std::cout << std::endl;
				}
				Sleep(500);
				std::cout << std::setw(60) << TitleScreen::name << " ,You Won!!!" << std::endl;
				Sleep(500);
			}
		}
		else if (valid_atk_cord == true)
		{
			Sleep(3000);
			Board::print_player_board_and_attack_radar();
			AI::comp_sets_atk();
		}
	} while (!valid_atk_cord || Board::comp_piece_on_board > 0);
}
void Player::check_correct_atk_cords()
{
	if (player_atk_cords[0] < 'a' || player_atk_cords[0] > 'j' || player_atk_cords[1] < '0' || player_atk_cords[1] > '9')
	{
		valid_atk_cord = false;
		system("CLS");
		Board::print_player_board_and_attack_radar();
		std::cout << std::setw(91) << "Sorry. It Seams Like You Have Entered Invalid Coordinates." << std::endl;
		std::cout << std::setw(98) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. E.g = a3" << std::endl;
		Sleep(3000);
	}
	else
	{
		values_of_attack_row_col();
		player_sets_atk_on_board();
	}
}





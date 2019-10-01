#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

//using namespace std;
const int options_row = 3;
const int options_col = 14;
const int title_row = 36;
const int title_col = 36;

class Battleship
{
private:
	// I need 3 boards for the game to use, one to display the player ships, (player_board), One to display where the player is attacking or has attacked already, to display hits/miss/ships ect (player_atk_radar)
	// and a 3rd board for the computer to place ships on, this one will be hidden until the player loses the game, at that point it will display and tell the player how far off of winning they were, (Comp_board) cause I
	// wanna rub it in when you lose steve.
	char player_atk_radar[19][23] =
	{
		{'a', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'b', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'c', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'d', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'e', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'f', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'g', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'h', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'i', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'j', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},

	};

	char player_board[19][23] =
	{
		{'a', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'b', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'c', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'d', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'e', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'f', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'g', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'h', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'i', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'j', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},

	};

	char Comp_board[19][23] =
	{
		{'a', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'b', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'c', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'d', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'e', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'f', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'g', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'h', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'i', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'_', '_', '@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'j', '_', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},

	};
	// Because I learned how to make an options menu with a moveable arrow, I needed to do that. So I did.
	char Options[options_row][options_col]
	{
		{' ',' ', ' ', 'N', 'E', 'W', ' ', 'G', 'A', 'M', 'E', ' ', ' ',},
		{' ',' ', 'H', 'I', 'G', 'H', ' ', 'S', 'C', 'O', 'R', 'E', ' ',},
		{' ',' ', ' ', ' ', ' ', 'Q', 'U', 'I', 'T', ' ', ' ', ' ', ' ',},
	};
	// Fancy fancy art.
	char game_title[title_col][title_row]
	{
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		{'#',' ','#',' ',' ','#',' ',' ','#','#','#','#','#','#',' ','#',' ',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#',' '},
		{'#','#',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#'},
		{'#',' ','#',' ','#','#','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#','#',' ',' ','#',' ',' ','#','#','#',' ',' ','#',' ',' ','#','#',' '},
		{'#',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' '},
		{'#','#',' ',' ','#',' ','#',' ',' ','#',' ',' ','#',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},

	};

	// player ship Horizontal or Verticle
	char Hori_or_Vert[20];

	// variables for "attacking" other pieces
	char player_ship_cords[10];
	char player_atk_cords[10];
	//total number of spaces the ships will take up during the game
	int comp_piece_on_board = 17;
	int player_piece_on_board = 17;
	// Arrow for my menu
	int arrow_row = 0, arrow_col = 0;

	// Sizes of Ships, also hit point values
	int ptrl_boat_size = 2, player_ptrl_boat_size = 2;
	int sub_size = 3, player_sub_size = 3;
	int cruise_size = 3, player_cruise_size = 3;
	int ac_size = 4, player_ac_size = 4;
	int BS_size = 5, player_BS_size = 5;

	// Vairables for "finding" a spot on the "map"
	int row, col;
	int atk_row, atk_col;
	int comp_row, comp_col;
	int comp_atk_row, comp_atk_col;

	int comp_hv;				// computer ships hoz or vert

	char options_move;
	char upordown;				// for Using the menu, to go up or down
	char first_comp_cord;		// to check the first part of the computers "firing" cords

	int ship_number = 0;		// Number of ships left in the game
	int comp_ship = 0;			// Number of computer  ships left in the game

	bool valid_ship_pos;		// to check if the position of the ship is valid while placing it/firing on it
	bool valid_comp_ship_pos;	// same as above but for computer
	bool valid_atk_cord;		// checks if the place was fired upon already or not
	bool valid_comp_atk_cord;	// same but for computer

	bool hit = false;			// variable for if something is hit or not.

	// Variables for each individual ship to check for hits and misses
	bool ptrl_boat_hit = false;
	bool sub_hit = false;
	bool cruise_hit = false;
	bool ac_hit = false;
	bool BS_hit = false;

	std::string name;				// for entering the players name

public:
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   Used for changing the colours of text, background ect, might not be used*/

	// Prints the game title at the top-middle of the page
	void print_game_title()
	{
		std::cout << std::endl; std::cout << std::endl;
		for (int i = 0; i < title_row; i++)
		{

			std::cout << std::setw(45);   // setw() sets where the title will start to draw
			for (int j = 0; j < title_col; j++)
			{
				if (game_title[i][j] == '#')   // Changes all the # in the array to be an ASCII character					
				{
					std::cout << (char)219;
				}
				else
				{
					std::cout << (char)32;  // If its not a hashtag, change it to a "space"
				}
			}
			std::cout << std::endl;
		}
	}

	void print_options() {
		for (int i = 0; i < options_row; i++) {
			std::cout << std::setw(56);
			for (int j = 0; j < options_col; j++) {
				if (i == arrow_row && j == arrow_col) {
					std::cout << (char)175;
				}
				std::cout << Options[i][j];
			}std::cout << std::endl;
		}
	}

	void player_choose_options()
	{
		while (1) {
			if (_kbhit()) {  //_kbhit() just checks if there is something in the input buffer. it does not do anything else. Used in my "menu" to have the player move the arrow up and down
				options_move = _getch();
				if (arrow_row == 0 && arrow_col == 0 && options_move == 13)			// first option, plays the game, starts by asking the player name, computer places ships on the board, then prompts the player to place ships,
																					// then will tell the player to get ready to play (tell_player_shits_about_to_get_real function) and print the boards, then asks for the attack cords.
				{
					system("CLS");
					enter_playername();
					take_comp_input();
					print_player_board_and_attack_radar();
					player_place_ships();
					tell_player_shits_about_to_get_real();
					player_sets_atk();
				}
				else if (arrow_row == 2 && arrow_col == 0 && options_move == 13)
				{
					system("CLS");
					// Instructions go here, this is the Second (thrid in code) option
					if (options_move == -32) {
						system("CLS");
					}
				}
				else if (arrow_row == 3 && arrow_col == 0 && options_move == 13)
				{
					// should quit the program, but cant get it working with exit()
					system("CLS");
					for (int i = 0; i < 18; i++)
					{
						std::cout << std::endl;
					}std::cout << std::setw(58);
					for (int i = 1; i <= 6; i++)
					{
						std::cout << (char)i << " ";
					}
					for (int i = 0; i < 18; i++)
					{
						std::cout << std::endl;
					}
					//Sleep(5000);
					exit(0);
				}
				else if (options_move == 27) {
					system("CLS");
					print_game_title();
					print_options();
				}
				else if (options_move == -32) {
					upordown = _getch();
					switch (upordown) {
					case 72:
						if (arrow_row > 0) {
							arrow_row--;
						}
						break;
					case 80:
						if (arrow_row < options_row - 1) {
							arrow_row++;
						}
						break;
					}
					system("CLS");
					print_game_title();
					print_options();
				}
			}
		}
	}

	// Used to get players Name, the loop is used for spacing to try to get the text in the "center" of the screen
	void enter_playername()
	{
		for (int i = 0; i < 15; i++)
		{
			std::cout << std::endl;
		}
		std::cout << std::setw(70) << "Enter Name: ";
		getline(std::cin, name);
	}
	// Display for both game boards that the player will see or interact with. the third grid I build up top will be used after the game is done, if the player loses to show how close they were to winning.
	void print_player_board_and_attack_radar()
	{
		display_ship_statuses();				// Displays the ships status, Name : Hits Value
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
				if (player_board[k][l] == '*') { std::cout << (char)247 << " "; }
				else if (player_board[k][l] == '#') { std::cout << (char)179 << " "; }
				else if (player_board[k][l] == '@') { std::cout << (char)195; }
				else if (player_board[k][l] == '_') { std::cout << (char)32; }
				else if (player_board[k][l] == '-') { std::cout << (char)196 << (char)196 << (char)196; }
				else if (player_board[k][l] == '^') { std::cout << (char)197; }
				else if (player_board[k][l] == '$') { std::cout << (char)180 << " "; }
				else if (player_board[k][l] == 'P') { std::cout << (char)80 << " "; }
				else if (player_board[k][l] == 'S') { std::cout << (char)83 << " "; }
				else if (player_board[k][l] == 'C') { std::cout << (char)67 << " "; }
				else if (player_board[k][l] == 'B') { std::cout << (char)66 << " "; }
				else if (player_board[k][l] == 'A') { std::cout << (char)65 << " "; }
				else if (player_board[k][l] == '!') { std::cout << (char)33 << " "; }
				else if (player_board[k][l] == '$') { std::cout << (char)237 << " "; }
				else if (player_board[k][l] == 'a') { std::cout << (char)65; }
				else if (player_board[k][l] == 'b') { std::cout << (char)66; }
				else if (player_board[k][l] == 'c') { std::cout << (char)67; }
				else if (player_board[k][l] == 'd') { std::cout << (char)68; }
				else if (player_board[k][l] == 'e') { std::cout << (char)69; }
				else if (player_board[k][l] == 'f') { std::cout << (char)70; }
				else if (player_board[k][l] == 'g') { std::cout << (char)71; }
				else if (player_board[k][l] == 'h') { std::cout << (char)72; }
				else if (player_board[k][l] == 'i') { std::cout << (char)73; }
				else if (player_board[k][l] == 'j') { std::cout << (char)74; }
			}
			std::cout << std::setw(17);
			for (int m = 0; m < 23; m++) {
				if (player_atk_radar[k][m] == '*') { std::cout << (char)247 << " "; }
				else if (player_atk_radar[k][m] == '#') { std::cout << (char)179 << " "; }
				else if (player_atk_radar[k][m] == '@') { std::cout << (char)195; }
				else if (player_atk_radar[k][m] == '-') { std::cout << (char)196 << (char)196 << (char)196; }
				else if (player_atk_radar[k][m] == '^') { std::cout << (char)197; }
				else if (player_atk_radar[k][m] == '$') { std::cout << (char)180 << " "; }
				else if (player_atk_radar[k][m] == '!') { std::cout << (char)33 << " "; }
				else if (player_atk_radar[k][m] == 'X') { std::cout << (char)237 << " "; }
				else if (player_atk_radar[k][m] == '_') { std::cout << (char)32; }
				else if (player_atk_radar[k][m] == 'a') { std::cout << (char)65; }
				else if (player_atk_radar[k][m] == 'b') { std::cout << (char)66; }
				else if (player_atk_radar[k][m] == 'c') { std::cout << (char)67; }
				else if (player_atk_radar[k][m] == 'd') { std::cout << (char)68; }
				else if (player_atk_radar[k][m] == 'e') { std::cout << (char)69; }
				else if (player_atk_radar[k][m] == 'f') { std::cout << (char)70; }
				else if (player_atk_radar[k][m] == 'g') { std::cout << (char)71; }
				else if (player_atk_radar[k][m] == 'h') { std::cout << (char)72; }
				else if (player_atk_radar[k][m] == 'i') { std::cout << (char)73; }
				else if (player_atk_radar[k][m] == 'j') { std::cout << (char)74; }
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

	void display_ship_statuses() {
		system("CLS");
		std::cout << std::setw(80) << "Computer's Ship Status " << (char)179 << std::setw(2) << " " << name << "'s Ship Status" << std::endl;
		std::cout << std::setw(60) << (char)201;
		for (int i = 0; i < 40; i++)
		{
			std::cout << (char)205;
		}
		std::cout << (char)187 << std::endl;
		std::cout << std::setw(60) << (char)186 << "Patrol Boat: " << player_ptrl_boat_size << std::setw(7) << (char)179 << std::setw(18) << "Patrol Boat: " << ptrl_boat_size << (char)186 << std::endl;
		std::cout << std::setw(60) << (char)186 << "Submarine: " << player_sub_size << std::setw(9) << (char)179 << std::setw(18) << "Submarine: " << sub_size << (char)186 << std::endl;
		std::cout << std::setw(60) << (char)186 << "Cruiser: " << player_cruise_size << std::setw(11) << (char)179 << std::setw(18) << "Crusier: " << cruise_size << (char)186 << std::endl;
		std::cout << std::setw(60) << (char)186 << "Carrier: " << player_ac_size << std::setw(11) << (char)179 << std::setw(18) << "Carrier: " << ac_size << (char)186 << std::endl;
		std::cout << std::setw(60) << (char)186 << "Battleship: " << player_BS_size << std::setw(8) << (char)179 << std::setw(18) << "Battleship: " << BS_size << (char)186 << std::endl;
		std::cout << std::setw(60) << (char)200;
		for (int i = 0; i < 40; i++) {
			std::cout << (char)205;
		}
		std::cout << (char)188 << std::endl;

	}

	void player_place_ships()
	{
		do
		{
			// we will go through the 'list' of ships to place, 0-4 (5 ships total) and checks if the placement is okay, 'places' the ship on the board, increments ship_number by 1, then checks the next statement
			// we leave the loop if ship_number is 5 of greater
			valid_ship_pos = true;
			if (ship_number == 0)
			{
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
			std::cin.getline(player_ship_cords, 11, '\n');
			std::cout << std::endl << std::endl;
			check_cords();
			print_player_board_and_attack_radar();
			if (valid_ship_pos == true)
			{
				ship_number++;
			}
		} while (!valid_ship_pos || ship_number < 5);
	}

	void check_cords()
	{
		// function to check if the player entered in the correct information or not. should only let letter+number combo eg "A4. While 6A" or "2435234vkj", should come back with please enter valid input
		if (player_ship_cords[0] < 'a' || player_ship_cords[0] > 'j' || player_ship_cords[1] < '0' || player_ship_cords[1] > '9')
		{
			valid_ship_pos = false;					// sets vaild position to false
			print_player_board_and_attack_radar();    // reprint the board
			std::cout << std::setw(97) << "You entered incorrect Coordinates" << std::endl;
			std::cout << std::setw(122) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. Eg = a3" << std::endl;
			Sleep(1000);
		}
		else {
			values_of_row_col();
			check_for_valid_cell();
		}
	}
	// Check if the cell or cord entered is the * char in the array, if it is then the space is "empty" and we can place a ship, it will then replace the * char with the cooresponding Letter.
	void check_for_valid_cell()
	{
		if (player_board[row][col] == '*')
		{
			if (ship_number == 0)
			{
				player_board[row][col] = 'P';
			}
			else if (ship_number == 1)
			{
				player_board[row][col] = 'S';
			}
			else if (ship_number == 2)
			{
				player_board[row][col] = 'C';
			}
			else if (ship_number == 3)
			{
				player_board[row][col] = 'A';
			}
			else if (ship_number == 4)
			{
				player_board[row][col] = 'B';
			}
			player_h_or_v();
		}
		else
		{
			// reprint the board, 
			print_player_board_and_attack_radar();
			std::cout << std::setw(92) << "Sorry, It Seems Like That Spot Has Already Been Occupied." << std::endl << std::endl;
			Sleep(3000);
			valid_ship_pos = false;
		}
	}

	void player_h_or_v()
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(80) << player_ship_cords[0] << player_ship_cords[1] << std::endl << std::endl;
		std::cout << std::setw(118) << " Enter (h) to set ship Horizontally Or (v) To Set It Vertically: ";
		std::cin.getline(Hori_or_Vert, 20, '\n');
		// steve this was bullshit, it took me 2 weeks to get this done. I hate it.

		// if we enter h, and ship_number is '0', Ptrl_boat character is used, S for sub, C for Cruiser ect
		if (Hori_or_Vert[0] == 'h')
		{
			if (ship_number == 0 && player_board[row][col + 2] == '*')
			{
				player_board[row][col + 2] = 'P';  // Sets the ship at the position entered and will print to the right to fill the spaces the ship takes up
			}
			// if its ship_number 1 and the next 2 col spaces are free, prints out the 3 spaces for the Sub
			else if (ship_number == 1 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
			{
				player_board[row][col + 2] = 'S';
				player_board[row][col + 4] = 'S';
			}
			// if its ship_number 1 and the next 3 col spaces are free, prints out the 4 spaces for the Cruiser
			else if (ship_number == 2 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
			{
				player_board[row][col + 2] = 'C';
				player_board[row][col + 4] = 'C';
			}
			// I dont think I need to keep commenting these, I know what they do.
			else if (ship_number == 3 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*')
			{
				player_board[row][col + 2] = 'A';
				player_board[row][col + 4] = 'A';
				player_board[row][col + 6] = 'A';
			}
			else if (ship_number == 4 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*' && player_board[row][col + 8] == '*')
			{
				player_board[row][col + 2] = 'B';
				player_board[row][col + 4] = 'B';
				player_board[row][col + 6] = 'B';
				player_board[row][col + 8] = 'B';
			}
			else

			{ // if any space is occupied Not enough space to place
				print_player_board_and_attack_radar();
				std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Horizontally." << std::endl << std::endl;
				Sleep(3000);
				player_board[row][col] = '*';
				valid_ship_pos = false;
			}
		}
		else if (Hori_or_Vert[0] == 'v')
		{
			// Same comments as the previous, this is just for the vert seting
			if (ship_number == 0 && player_board[row + 2][col] == '*')
			{
				player_board[row + 2][col] = 'P';
			}
			else if (ship_number == 1 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
			{
				player_board[row + 2][col] = 'S';
				player_board[row + 4][col] = 'S';
			}
			else if (ship_number == 2 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
			{
				player_board[row + 2][col] = 'C';
				player_board[row + 4][col] = 'C';
			}
			else if (ship_number == 3 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*')
			{
				player_board[row + 2][col] = 'A';
				player_board[row + 4][col] = 'A';
				player_board[row + 6][col] = 'A';
			}
			else if (ship_number == 4 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*' && player_board[row + 8][col] == '*')
			{
				player_board[row + 2][col] = 'B';
				player_board[row + 4][col] = 'B';
				player_board[row + 6][col] = 'B';
				player_board[row + 8][col] = 'B';
			}
			else
			{
				print_player_board_and_attack_radar();
				std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Vertically." << std::endl << std::endl;
				Sleep(3000);
				player_board[row][col] = '*';
				valid_ship_pos = false;
			}
		}
		else
		{		// Tell the player they're dumb... I mean to put the right stuff in
			print_player_board_and_attack_radar();
			std::cout << std::setw(135) << "Please Enter The Letter 'h' To Set Your Boat Horizontally Or 'v' To Set It Vertically." << std::endl << std::endl;
			player_board[row][col] = '*';
			Sleep(5000);
			valid_ship_pos = false;
		}
	}

	// The code below is formatted as such so I can read the damn thing easier
	// Assign the vales of the colums to the letters, so the computer knows what cords are where
	void values_of_row_col()
	{
		if (player_ship_cords[0] == 'a') { row = 0; }
		else if (player_ship_cords[0] == 'b') { row = 2; }
		else if (player_ship_cords[0] == 'c') { row = 4; }
		else if (player_ship_cords[0] == 'd') { row = 6; }
		else if (player_ship_cords[0] == 'e') { row = 8; }
		else if (player_ship_cords[0] == 'f') { row = 10; }
		else if (player_ship_cords[0] == 'g') { row = 12; }
		else if (player_ship_cords[0] == 'h') { row = 14; }
		else if (player_ship_cords[0] == 'i') { row = 16; }
		else if (player_ship_cords[0] == 'j') { row = 18; }

		// Sets the rows to the proper values 
		if (player_ship_cords[1] == '0') { col = 3; }
		else if (player_ship_cords[1] == '1') { col = 5; }
		else if (player_ship_cords[1] == '2') { col = 7; }
		else if (player_ship_cords[1] == '3') { col = 9; }
		else if (player_ship_cords[1] == '4') { col = 11; }
		else if (player_ship_cords[1] == '5') { col = 13; }
		else if (player_ship_cords[1] == '6') { col = 15; }
		else if (player_ship_cords[1] == '7') { col = 17; }
		else if (player_ship_cords[1] == '8') { col = 19; }
		else if (player_ship_cords[1] == '9') { col = 21; }
	}

	// assigns the values of the players inputs to code so the program can 'check' that space when called 
	void values_of_attack_row_col()
	{
		if (player_atk_cords[0] == 'a') { atk_row = 0; }
		else if (player_atk_cords[0] == 'b') { atk_row = 2; }
		else if (player_atk_cords[0] == 'c') { atk_row = 4; }
		else if (player_atk_cords[0] == 'd') { atk_row = 6; }
		else if (player_atk_cords[0] == 'e') { atk_row = 8; }
		else if (player_atk_cords[0] == 'f') { atk_row = 10; }
		else if (player_atk_cords[0] == 'g') { atk_row = 12; }
		else if (player_atk_cords[0] == 'h') { atk_row = 14; }
		else if (player_atk_cords[0] == 'i') { atk_row = 16; }
		else if (player_atk_cords[0] == 'j') { atk_row = 18; }
		// assigns the value the player entered for the second Coords input, for the second coord input.

		if (player_atk_cords[1] == '0') { atk_col = 3; }
		else if (player_atk_cords[1] == '1') { atk_col = 5; }
		else if (player_atk_cords[1] == '2') { atk_col = 7; }
		else if (player_atk_cords[1] == '3') { atk_col = 9; }
		else if (player_atk_cords[1] == '4') { atk_col = 11; }
		else if (player_atk_cords[1] == '5') { atk_col = 13; }
		else if (player_atk_cords[1] == '6') { atk_col = 15; }
		else if (player_atk_cords[1] == '7') { atk_col = 17; }
		else if (player_atk_cords[1] == '8') { atk_col = 19; }
		else if (player_atk_cords[1] == '9') { atk_col = 21; }
	}
	// assigns the computers attack to cords to a letter
	void comp_cords_to_alpha() {
		if (first_comp_cord == 0) { comp_row = 'a'; }
		else if (first_comp_cord == 2) { comp_row = 'b'; }
		else if (first_comp_cord == 4) { comp_row = 'c'; }
		else if (first_comp_cord == 6) { comp_row = 'd'; }
		else if (first_comp_cord == 8) { comp_row = 'e'; }
		else if (first_comp_cord == 10) { comp_row = 'f'; }
		else if (first_comp_cord == 12) { comp_row = 'g'; }
		else if (first_comp_cord == 14) { comp_row = 'h'; }
		else if (first_comp_cord == 16) { comp_row = 'i'; }
		else if (first_comp_cord == 18) { comp_row = 'j'; }
	}

	// Get the computer to randomly place their ships
	void take_comp_input() {

		do {
			system("CLS");
			for (int i = 0; i < 19; i++)
			{
				std::cout << std::endl;
			}
			std::cout << std::setw(90) << "Waiting For Computer To Set Ships On It's Board.......";
			valid_comp_ship_pos = true;
			srand(time(0));
			comp_row = 2 * rand() % 11;     // gets a Random even number
			comp_col = 1 + (2 * rand()) % 11; // gets a Random Odd number
			is_comp_move_valid();			// checks if the space is a *, a * is a valid space to place a ship
			if (valid_comp_ship_pos == true) {
				comp_ship++;
			}
		} while (comp_ship < 5 || !valid_comp_ship_pos);

		system("CLS");
		for (int i = 0; i < 19; i++) {
			std::cout << std::endl;
		}
		std::cout << std::setw(90) << "The Computer Has Set It's Ships. Now It's Your Turn.";
		Sleep(3000);
		system("CLS");
	}

	void tell_player_shits_about_to_get_real() {
		for (int i = 0; i < 4; i++) {
			system("CLS");
			system("Color 0C");
			for (int i = 0; i < 18; i++) {
				std::cout << std::endl;
			}   Sleep(500);
			std::cout << std::setw(74) << "Get Ready For Battle....";
			Sleep(500);
			system("Color 08");
		}
	}

	// We need to check if the comps position is valid
	void is_comp_move_valid() 
	{
		// Same code as placing player ships, except this is hidden until the very end
		if (Comp_board[comp_row][comp_col] == '*')
		{
			if (comp_ship == 0)
			{
				Comp_board[comp_row][comp_col] = 'P';
			}
			else if (comp_ship == 1)
			{
				Comp_board[comp_row][comp_col] = 'S';
			}
			else if (comp_ship == 2)
			{
				Comp_board[comp_row][comp_col] = 'C';
			}
			else if (comp_ship == 3)
			{
				Comp_board[comp_row][comp_col] = 'A';
			}
			else if (comp_ship == 4)
			{
				Comp_board[comp_row][comp_col] = 'B';
			}
			comp_h_or_v();
		}
		else {
			valid_comp_ship_pos = false;
		}
	}

	void comp_h_or_v()
	{
		comp_hv = rand() % 1 + 1; // Computer will randomly choose hori or vert
		if (comp_hv == 1)
		{
			if (comp_ship == 0 && Comp_board[comp_row][comp_col + 2] == '*')
			{
				Comp_board[comp_row][comp_col + 2] = 'P';
			}
			else if (comp_ship == 1 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*')
			{
				Comp_board[comp_row][comp_col + 2] = 'S';
				Comp_board[comp_row][comp_col + 4] = 'S';
			}
			else if (comp_ship == 2 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*')
			{
				Comp_board[comp_row][comp_col + 2] = 'C';
				Comp_board[comp_row][comp_col + 4] = 'C';
			}
			else if (comp_ship == 3 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*' && Comp_board[comp_row][comp_col + 6] == '*')
			{
				Comp_board[comp_row][comp_col + 2] = 'A';
				Comp_board[comp_row][comp_col + 4] = 'A';
				Comp_board[comp_row][comp_col + 6] = 'A';
			}
			else if (comp_ship == 4 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*' && Comp_board[comp_row][comp_col + 6] == '*' && Comp_board[comp_row][comp_col + 8] == '*')
			{
				Comp_board[comp_row][comp_col = 2] = 'B';
				Comp_board[comp_row][comp_col + 4] = 'B';
				Comp_board[comp_row][comp_col + 6] = 'B';
				Comp_board[comp_row][comp_col + 8] = 'B';
			}
			else
			{
				Comp_board[comp_row][comp_col] = '*';
				valid_comp_ship_pos = false;
			}
		}
		else if (comp_hv == 2)
		{
			if (comp_ship == 0 && Comp_board[comp_row + 1][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'P';
			}
			else if (comp_ship == 1 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'S';
				Comp_board[comp_row + 3][comp_col] = 'S';
			}
			else if (comp_ship == 2 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'C';
				Comp_board[comp_row + 3][comp_col] = 'C';
			}
			else if (comp_ship == 3 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*' && Comp_board[comp_row + 5][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'A';
				Comp_board[comp_row + 3][comp_col] = 'A';
				Comp_board[comp_row + 5][comp_col] = 'A';

			}
			else if (comp_ship == 4 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*' && Comp_board[comp_row + 5][comp_col] == '*' && Comp_board[comp_row + 7][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'B';
				Comp_board[comp_row + 3][comp_col] = 'B';
				Comp_board[comp_row + 5][comp_col] = 'B';
				Comp_board[comp_row + 7][comp_col] = 'B';

			}
			else {
				Comp_board[comp_row][comp_col] = '*';
				valid_comp_ship_pos = false;
			}
		}
		system("CLS");
	}
	void player_sets_atk()
	{
		do
		{
			valid_atk_cord = true;
			print_player_board_and_attack_radar();
			std::cout << std::setw(76) << "Enter Attack Coordinates: ";
			std::cin.getline(player_atk_cords, 11, '\n');

			check_correct_atk_cords();
			if (comp_piece_on_board == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					system("CLS");
					for (int i = 0; i < 19; i++)
					{
						std::cout << std::endl;
					}
					Sleep(500);
					std::cout << std::setw(60) << name << " ,You Won!!!" << std::endl;
					Sleep(500);
				}
			}
			else if (valid_atk_cord == true)
			{
				Sleep(3000);
				print_player_board_and_attack_radar();
				comp_sets_atk();
			}
		} while (!valid_atk_cord || comp_piece_on_board > 0);
	}

	void check_correct_atk_cords()
	{
		if (player_atk_cords[0] < 'a' || player_atk_cords[0] > 'j' || player_atk_cords[1] < '0' || player_atk_cords[1] > '9')
		{
			valid_atk_cord = false;
			system("CLS");
			print_player_board_and_attack_radar();
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

	void player_sets_atk_on_board()
	{
		if (player_atk_radar[atk_row][atk_col] == '!' || player_atk_radar[atk_row][atk_col] == '$')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(82) << "You Have Already Attacked That Position.";
			Sleep(3000);
			valid_atk_cord = false;
		}
		else if (Comp_board[atk_row][atk_col] == 'P')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(84) << "You Hit Their Patrol Boat.";
			player_atk_radar[atk_row][atk_col] = '!';
			ptrl_boat_size--;
			comp_piece_on_board--;
		}
		else if (Comp_board[atk_row][atk_col] == 'S')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(84) << "You Hit Their Submarine.";
			player_atk_radar[atk_row][atk_col] = '!';
			sub_size--;
			comp_piece_on_board--;
		}
		else if (Comp_board[atk_row][atk_col] == 'C')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(84) << "You Hit Their Cruiser.";
			player_atk_radar[atk_row][atk_col] = '!';
			cruise_size--;
			comp_piece_on_board--;
		}
		else if (Comp_board[atk_row][atk_col] == 'A')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(84) << "You Hit Their Aircraft Carrier.";
			player_atk_radar[atk_row][atk_col] = '!';
			ac_size--;
			comp_piece_on_board--;
		}
		else if (Comp_board[atk_row][atk_col] == 'B')
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(84) << " You Hit Their Battleship";
			player_atk_radar[atk_row][atk_col] = '!';
			BS_size--;
			comp_piece_on_board--;
		}
		else
		{
			print_player_board_and_attack_radar();
			std::cout << std::setw(71) << "Nope. You Missed." << std::endl << std::endl;
			player_atk_radar[atk_row][atk_col] = '$';
		}

	}

	void comp_sets_atk()
	{
		do
		{
			valid_comp_atk_cord = true;
			comp_atk_row = 2 * rand() % 10;    // Need to change this to get a random even number only
			comp_atk_col = 2*rand() % 11 +1;	// Need to change this to get an Odd Number only, if the computer fucks up here, it just breaks, I need to add something that will check for an odd number and and even number combo only, else it will say nope and try again

			is_comp_move_valid_on_atk();
			if (player_piece_on_board == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					system("CLS");
					for (int i = 0; i < 19; i++)
					{
						std::cout << std::endl;
					}
					std::cout << std::setw(60) << name << ", You lost..";
					Sleep(600);
				}
			}
			else if (valid_comp_atk_cord == true)
			{
				Sleep(3000);
				print_player_board_and_attack_radar();
				player_sets_atk();
			}
		} while (!valid_comp_atk_cord || player_piece_on_board > 0);
	
	}


	void is_comp_move_valid_on_atk()
	{
		do
		{
			valid_comp_atk_cord = true;

			if (ptrl_boat_hit == true)
			{
				if (player_board[comp_atk_row][comp_atk_col] == 'P') 
				{ 
					comp_sets_atk_on_board(); 
				}
				else { valid_comp_atk_cord = false; }
			}			
			else if (sub_hit == true) {
				if (player_board[comp_atk_row][comp_atk_col] == 'S') { comp_sets_atk_on_board(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (cruise_hit == true) {
				if (player_board[comp_atk_row][comp_atk_col] == 'C') { comp_sets_atk_on_board(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (ac_hit == true)
			{
				if (player_board[comp_atk_row][comp_atk_col] == 'A') { comp_sets_atk_on_board(); }
				else { valid_comp_atk_cord = false; }
			}
			else if (BS_hit == true)
			{
				if (player_board[comp_atk_row][comp_atk_col] == 'B') { comp_sets_atk_on_board(); }
				else { valid_comp_atk_cord = false; }
			}
			if (ptrl_boat_hit == false && sub_hit == false && cruise_hit == false && ac_hit == false && BS_hit == false)
			{
				comp_sets_atk_on_board();
			}

		} while (!valid_comp_atk_cord || player_piece_on_board > 0);

	}
	void comp_sets_atk_on_board() 
	{
		comp_cords_to_alpha();
		if (player_board[comp_atk_row][comp_atk_col] == 'P')
		{
			std::cout << std::setw(82) << "The Computer Has Hit Your Patrol Boat: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			ptrl_boat_hit = true;
			player_board[comp_atk_row][comp_atk_col] = '!';
			player_piece_on_board--;
			player_ptrl_boat_size--;
		}
		else if (player_board[comp_atk_row][comp_atk_col] == 'S') 
		{
			std::cout << std::setw(81) << "The Computer Has Hit Your Submarine: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			sub_hit = true;
			player_board[comp_atk_row][comp_atk_col] = '!';
			player_piece_on_board--;
			player_sub_size--;
		}
		else if (player_board[comp_atk_row][comp_atk_col] == 'C')
		{
			std::cout << std::setw(81) << "The Computer Has Hit Your Cruiser: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			cruise_hit = true;
			player_board[comp_atk_row][comp_atk_col] = '!';
			player_piece_on_board--;
			player_cruise_size--;
		}
		else if (player_board[comp_atk_row][comp_atk_col] == 'A')
		{
			std::cout << std::setw(81) << "The Computer Has Hit Your Aircraft Carrier: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			ac_hit = true;
			player_board[comp_atk_row][comp_atk_col] = '!';
			player_piece_on_board--;
			player_ac_size--;
		}
		else if (player_board[comp_atk_row][comp_atk_col] == 'B')
		{
			std::cout << std::setw(81) << "The Computer Has Hit Your Battleship: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			BS_hit = true;
			player_board[comp_atk_row][comp_atk_col] = '!';
			player_piece_on_board--;
			player_BS_size--;
		}
		else if (player_board[comp_atk_row][comp_atk_col] == '*')
		{
			std::cout << std::setw(73) << "The Computer Missed: " << comp_atk_row << comp_atk_col - 1 << std::endl << std::endl;
			player_board[comp_atk_row][comp_atk_col] = '$';
		}
		else 
		{
			valid_comp_atk_cord = false;
		}
		clear_hit();
		if (player_piece_on_board == 0) 
		{
			for (int i = 0; i < 6; i++) {
				system("CLS");
				system("Color 2E");
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
			clear_hit();
			Sleep(3000);
			player_sets_atk();
		}
	}


	// Clears the status of ships after the game is done, to play again.
	void clear_hit()
	{
		if (BS_size == 0)
		{
			BS_hit = false;
		}
		if (sub_size == 0)
		{
			sub_hit = false;
		}
		if (ptrl_boat_size == 0)
		{
			ptrl_boat_hit = false;
		}
		if (ac_size == 0)
		{
			ac_hit = false;
		}
		if (cruise_size == 0)
		{
			cruise_hit = false;
		}

	}
	// 'clears' the board
	void board_clearer()
	{
		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 39; j++) 
			{		// checks for all symbols used on the map, to change them back to '*'
				if (player_board[i][j] == 'P' || Comp_board[i][j] == 'P' ||
				player_board[i][j] == 'S' || Comp_board[i][j] == 'S' ||
				player_board[i][j] == 'C' || Comp_board[i][j] == 'C' ||
				player_board[i][j] == 'A' || Comp_board[i][j] == 'A' ||
				player_board[i][j] == 'B' || Comp_board[i][j] == 'B' ||
				player_board[i][j] == '!' || player_atk_radar[i][j] == '!' ||
				player_board[i][j] == '$' || player_atk_radar[i][j] == '$') 
				{
					player_board[i][j] = '*';
					Comp_board[i][j] = '*';
					player_atk_radar[i][j] = '*';
				}
			}
		}
		//reset variables to origional numbers
		comp_ship = 0;
		ship_number = 0;
		comp_piece_on_board = 14;
		player_piece_on_board = 14;
		ptrl_boat_size = 2;
		player_ptrl_boat_size = 2;
		sub_size = 3;
		player_sub_size = 3;
		cruise_size = 3;
		player_cruise_size = 3;
		ac_size = 4;
		player_ac_size = 4;
		BS_size = 5;
		player_BS_size = 5;
	}
	
};


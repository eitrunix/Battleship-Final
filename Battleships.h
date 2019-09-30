#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;
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
	char player_atk_radar[20][22] =
	{
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
	};

	char player_board[20][22] =
	{
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
	};

	char Comp_board[20][22] =
	{
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},
		{'@', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '^', '-', '$',},
		{'#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#', '*', '#',},

	};

	char Options[options_row][options_col]
	{
		{' ',' ', ' ', 'N', 'E', 'W', ' ', 'G', 'A', 'M', 'E', ' ', ' ',},
		{' ',' ', 'H', 'I', 'G', 'H', ' ', 'S', 'C', 'O', 'R', 'E', ' ',},
		{' ',' ', ' ', ' ', ' ', 'Q', 'U', 'I', 'T', ' ', ' ', ' ', ' ',},
	};

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
	// sets a and b to be char A in the making of the boards
	int a = 65, b = 65;
	//total number of spaces the ships will take up during the game
	int comp_piece_on_board = 14;
	int player_piece_on_board = 14;
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

	string name;				// for entering the players name

public:
	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   Used for changing the colours of text, background ect, might not be used*/

	// Prints the game title at the top-middle of the page
	void print_game_title()
	{
		cout << endl; cout << endl;
		for (int i = 0; i < title_row; i++)
		{

			cout << setw(45);   // setw() sets where the title will start to draw
			for (int j = 0; j < title_col; j++)
			{
				if (game_title[i][j] == '#')   // Changes all the # in the array to be an ASCII character					
				{
					cout << (char)219;
				}
				else
				{
					cout << (char)32;
				}
			}
			cout << endl;
		}
	}

	void print_options() {
		for (int i = 0; i < options_row; i++) {
			cout << setw(56);
			for (int j = 0; j < options_col; j++) {
				if (i == arrow_row && j == arrow_col) {
					cout << (char)175;
				}
				cout << Options[i][j];
			}cout << endl;
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
					take_player_input_place();
					//tell_player_shits_about_to_get_real();
					//player_sets_attack();
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
					//system("Color 80");
					for (int i = 0; i < 18; i++)
					{
						cout << endl;
					}cout << setw(58);
					for (int i = 1; i <= 6; i++)
					{
						cout << (char)i << " ";
					}
					for (int i = 0; i < 18; i++)
					{
						cout << endl;
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
			cout << endl;
		}
		cout << setw(70) << "Enter Name: ";
		getline(cin, name);
	}
	// Display for both game boards that the player will see or interact with. the third grid I build up top will be used after the game is done, if the player loses to show how close they were to winning.
	void print_player_board_and_attack_radar()
	{
		display_ship_statuses();				// Displays the ships status, Name : Hits Value
		for (int i = 0; i < 3; i++)
		{
			cout << endl;					// Spacing between board and the Ship Status
		}
		cout << setw(70) << "0   1   2   3   4   5   6   7   8   9" << setw(59) << "0   1   2   3   4   5   6   7   8   9" << endl;
		cout << setw(32) << (char)218 << (char)196 << (char)196 << (char)196;					// sets where the Top line will start to print
		for (int j = 0; j < 9; j++)
		{
			cout << (char)194 << (char)196 << (char)196 << (char)196;						// First boards Top line
		}
		cout << (char)191 << setw(19) << (char)218 << (char)196 << (char)196 << (char)196;		// sets spacing between the top of the boards

		for (int n = 0; n < 9; n++)
		{
			cout << (char)194 << (char)196 << (char)196 << (char)196;						// Top line of second board
		}
		cout << (char)191 << endl;

		for (int k = 0; k < 19; k++)
		{
			cout << setw(30) << (char)a++ << " ";		// prints out the letter A and sets spacing for the board
			for (int l = 0; l < 21; l++)
			{
				if (player_board[k][l] == '*')			// if theres a '*' on a board, change it to an ASCII Character
				{
					cout << (char)247 << " ";
				}
				else if (player_board[k][l] == '#')
				{
					cout << (char)179 << " ";
				}
				else if (player_board[k][l] == '@')
				{
					cout << (char)195;
				}
				else if (player_board[k][l] == '-')
				{
					cout << (char)196 << (char)196 << (char)196;
				}
				else if (player_board[k][l] == '^')
				{
					cout << (char)197;
				}
				else if (player_board[k][l] == '$')
				{
					cout << (char)180 << " ";
				}
				else if (player_board[k][l] == 'P')
				{
					cout << (char)80 << " ";
				}
				else if (player_board[k][l] == 'S')
				{
					cout << (char)83 << " ";
				}
				else if (player_board[k][l] == 'C')
				{
					cout << (char)67 << " ";
				}
				else if (player_board[k][l] == 'B')
				{
					cout << (char)66 << " ";
				}
				else if (player_board[k][l] == 'A')
				{
					cout << (char)65 << " ";
				}
				else if (player_board[k][l] == '!')
				{
					cout << (char)33 << " ";
				}
				else if (player_board[k][l] == '$')
				{
					cout << (char)237 << " ";
				}
			}
			cout << setw(17) << (char)b++;
			for (int m = 0; m < 21; m++) {
				if (player_atk_radar[k][m] == '*')
				{
					cout << (char)247 << " ";
				}
				else if (player_atk_radar[k][m] == '#')
				{
					cout << (char)179 << " ";
				}
				else if (player_atk_radar[k][m] == '@')
				{
					cout << (char)195;
				}
				else if (player_atk_radar[k][m] == '-')
				{
					cout << (char)196 << (char)196 << (char)196;
				}
				else if (player_atk_radar[k][m] == '^')
				{
					cout << (char)197;
				}
				else if (player_atk_radar[k][m] == '$')
				{
					cout << (char)180 << " ";
				}
				else if (player_atk_radar[k][m] == '!')
				{
					cout << (char)33 << " ";
				}
				else if (player_atk_radar[k][m] == 'X')
				{
					cout << (char)237 << " ";
				}
			}
			cout << endl;
		}

		a = 65;					// a = 65 = "A"  sets the character code for the letter A, used to creat the Alphabit part of the board
		b = 65;					// b = 65 = "A"  sets character code for the letter A, used for the second board Alphabet

		// Bottom Line for both boards.
		cout << setw(32) << (char)192 << (char)196 << (char)196 << (char)196;
		for (int o = 0; o < 9; o++)
		{
			cout << (char)193 << (char)196 << (char)196 << (char)196;
		}
		cout << (char)217 << setw(19) << (char)192 << (char)196 << (char)196 << (char)196;
		for (int p = 0; p < 9; p++)
		{
			cout << (char)193 << (char)196 << (char)196 << (char)196;
		}
		cout << (char)217 << endl << endl;
	}

	void display_ship_statuses() {
		system("CLS");
		cout << setw(63) << "Computer's Ship Status " << (char)179 << setw(2) << " " << name << "'s Ship Status" << endl;
		cout << setw(43) << (char)201;
		for (int i = 0; i < 40; i++)
		{
			cout << (char)205;
		}
		cout << (char)187 << endl;
		cout << setw(43) << (char)186 << "Patrol Boat: " << ptrl_boat_size << setw(7) << (char)179 << setw(18) << "Patrol Boat: " << player_ptrl_boat_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Submarine: " << sub_size << setw(9) << (char)179 << setw(18) << "Submarine: " << player_sub_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Cruiser: " << cruise_size << setw(11) << (char)179 << setw(18) << "Crusier: " << player_cruise_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Carrier: " << ac_size << setw(11) << (char)179 << setw(18) << "Carrier: " << player_ac_size << (char)186 << endl;
		cout << setw(43) << (char)186 << "Battleship: " << BS_size << setw(8) << (char)179 << setw(18) << "Battleship: " << player_BS_size << (char)186 << endl;
		cout << setw(43) << (char)200;
		for (int i = 0; i < 40; i++) {
			cout << (char)205;
		}cout << (char)188 << endl;

	}

	void take_player_input_place()
	{
		do
		{
			// we will go through the 'list' of ships to place, 0-4 (5 ships total) and checks if the placement is okay, 'places' the ship on the board, increments ship_number by 1, then checks the next statement
			// we leave the loop if ship_number is 5 of greater
			valid_ship_pos = true;
			if (ship_number == 0)
			{
				cout << setw(90) << "Enter The Coordinate For Your Patrol Boat (2 spots): ";
			}
			else if (ship_number == 1)
			{
				cout << setw(89) << "Enter The Coordinate For Your Submarine (3 spots): ";
			}
			else if (ship_number == 2)
			{
				cout << setw(88) << "Enter The Coordinate For Your Crusier (4 spots): ";
			}
			else if (ship_number == 3)
			{
				cout << setw(87) << "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
			}
			else if (ship_number == 4)
			{
				cout << setw(90) << "Enter the Coordinate For Your Battleship (5 spots)";
			}
			cin.getline(player_ship_cords, 11, '\n');
			cout << endl << endl;
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
		// function to check if the player entered in the correct information or not. should only let letter+number combo eg "A4, 6A" or "2435234vkj", should come back with please enter valid input
		if (player_ship_cords[0] < 'a' || player_ship_cords[0] > 'j' || player_ship_cords[1] < '0' || player_ship_cords[1] > '9')
		{
			valid_ship_pos = false;					// sets vaild position to false
			print_player_board_and_attack_radar();    // reprint the board
			cout << setw(91) << "You entered incorrect Coordinates" << endl;
			cout << setw(98) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. Eg = a3" << endl;
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
			cout << setw(92) << "Sorry, It Seems Like That Spot Has Already Been Occupied." << endl << endl;
			Sleep(3000);
			valid_ship_pos = false;
		}
	}

	void player_h_or_v()
	{
		print_player_board_and_attack_radar();
		cout << setw(28) << player_ship_cords[0] << player_ship_cords[1] << " Enter (h) to set ship Horizontally Or (v) To Set It Vertically: ";
		cin.getline(Hori_or_Vert, 20, '\n');
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
				cout << setw(85) << "Sorry, Not Enough Space To Set It Horizontally." << endl << endl;
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
				cout << setw(85) << "Sorry, Not Enough Space To Set It Vertically." << endl << endl;
				Sleep(3000);
				player_board[row][col] = '*';
				valid_ship_pos = false;
			}
		}
		else
		{		// Tell the player they're dumb... I mean to put the right stuff in
			print_player_board_and_attack_radar();
			cout << setw(105) << "Please Enter The Letter 'h' To Set Your Boat Horizontally Or 'v' To Set It Vertically." << endl << endl;
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
		if (player_ship_cords[1] == '0') { col = 1; }
		else if (player_ship_cords[1] == '1') { col = 3; }
		else if (player_ship_cords[1] == '2') { col = 5; }
		else if (player_ship_cords[1] == '3') { col = 7; }
		else if (player_ship_cords[1] == '4') { col = 9; }
		else if (player_ship_cords[1] == '5') { col = 11; }
		else if (player_ship_cords[1] == '6') { col = 13; }
		else if (player_ship_cords[1] == '7') { col = 15; }
		else if (player_ship_cords[1] == '8') { col = 17; }
		else if (player_ship_cords[1] == '9') { col = 19; }
	}

	// assigns the values of the players inputs to code so the program can 'check' that space when called 
	void values_of_attack_row_col()
	{
		if (player_atk_cords[0] == 'a') { row = 0; }
		else if (player_atk_cords[0] == 'b') { row = 2; }
		else if (player_atk_cords[0] == 'c') { row = 4; }
		else if (player_atk_cords[0] == 'd') { row = 6; }
		else if (player_atk_cords[0] == 'e') { row = 8; }
		else if (player_atk_cords[0] == 'f') { row = 10; }
		else if (player_atk_cords[0] == 'g') { row = 12; }
		else if (player_atk_cords[0] == 'h') { row = 14; }
		else if (player_atk_cords[0] == 'i') { row = 16; }
		else if (player_atk_cords[0] == 'j') { row = 18; }
		// assigns the value the player entered for the second Coords input, for the second coord input.

		if (player_atk_cords[0] == '0') { col = 1; }
		else if (player_atk_cords[1] == '1') { col = 3; }
		else if (player_atk_cords[1] == '2') { col = 5; }
		else if (player_atk_cords[1] == '3') { col = 7; }
		else if (player_atk_cords[1] == '4') { col = 9; }
		else if (player_atk_cords[1] == '5') { col = 11; }
		else if (player_atk_cords[1] == '6') { col = 13; }
		else if (player_atk_cords[1] == '7') { col = 15; }
		else if (player_atk_cords[1] == '8') { col = 17; }
		else if (player_atk_cords[1] == '9') { col = 19; }
	}

	// Get the computer to randomly place their ships
	void take_comp_input() {

		do {
			system("CLS");
			for (int i = 0; i < 19; i++) {
				cout << endl;
			}
			cout << setw(90) << "Waiting For Computer To Set Ships On It's Board.......";
			valid_comp_ship_pos = true;
			srand(time(0));
			comp_row = rand() % 11;
			comp_col = rand() % 11;
			is_comp_move_valid();
			if (valid_comp_ship_pos == true) {
				comp_ship++;
			}
		} while (comp_ship < 5 || !valid_comp_ship_pos);

		system("CLS");
		for (int i = 0; i < 19; i++) {
			cout << endl;
		}
		cout << setw(90) << "The Computer Has Set It's Ships. Now It's Your Turn.";
		Sleep(3000);
		system("CLS");
	}

	// We need to check if the comps position is valid
	void is_comp_move_valid() {
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
		comp_hv = 1 + rand() % 2; // Computer will randomly choose hori or vert
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
			else if (comp_ship == 2 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*' && Comp_board[comp_row][comp_col + 6] == '*')
			{
				Comp_board[comp_row][comp_col + 2] = 'C';
				Comp_board[comp_row][comp_col + 4] = 'C';
				Comp_board[comp_row][comp_col + 6] = 'C';
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
			else if (comp_ship == 2 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*' && Comp_board[comp_row + 5][comp_col] == '*')
			{
				Comp_board[comp_row + 1][comp_col] = 'C';
				Comp_board[comp_row + 3][comp_col] = 'C';
				Comp_board[comp_row + 5][comp_col] = 'C';
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
	// Clears the status of ships after the game is done, to play again.
	void clear_hit()
	{
		if (player_BS_size == 0)
		{
			BS_hit = false;
		}
		if (player_sub_size == 0)
		{
			sub_hit = false;
		}
		if (player_ptrl_boat_size == 0)
		{
			ptrl_boat_hit = false;
		}
		if (player_ac_size == 0)
		{
			ac_hit = false;
		}
		if (player_cruise_size == 0)
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
				player_board[i][j] == 'X' || player_atk_radar[i][j] == 'X') 
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


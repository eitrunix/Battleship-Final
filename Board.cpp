#include "Board.h"
#include "Player.h"
#include "TitleSceen.h"
#include "Piece.h"
#include "AI.h"
#include <Windows.h>

static char player_atk_radar[19][23]
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

static char player_board[19][23] =
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
static char Comp_board[19][23] =
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


Board::Board()
{
}

Board::~Board()
{
}

void Board::Init()
{
}
void Board::display_ship_statuses() {
	system("CLS");
	std::cout << std::setw(80) << TitleScreen::name << "'s Ship Status" << (char)179 << std::setw(2) << " " << "Computer's Ship Status " << std::endl;
	std::cout << std::setw(60) << (char)201;
	for (int i = 0; i < 40; i++)
	{
		std::cout << (char)205;			// Create a top line to box in the Status "screen"
	}
	// X_size is the number of hits on each ship, so it should print out "| Patrol Boat: 2      |        Patrol Boat: 2 |" for each ship and line respectively
	std::cout << (char)187 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Patrol Boat: " << Piece::player_ptrl_boat_size << std::setw(7) << (char)179 << std::setw(18) << "Patrol Boat: " << Piece::ptrl_boat_size << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Submarine: " << Piece::player_sub_size << std::setw(9) << (char)179 << std::setw(18) << "Submarine: " << Piece::sub_size << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Cruiser: " << Piece::player_cruise_size << std::setw(11) << (char)179 << std::setw(18) << "Crusier: " << Piece::cruise_size << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Carrier: " << Piece::player_ac_size << std::setw(11) << (char)179 << std::setw(18) << "Carrier: " << Piece::ac_size << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)186 << "Battleship: " << Piece::player_BS_size << std::setw(8) << (char)179 << std::setw(18) << "Battleship: " << Piece::BS_size << (char)186 << std::endl;
	std::cout << std::setw(60) << (char)200;
	for (int i = 0; i < 40; i++) {
		std::cout << (char)205;			// Bottom line, looping so I dont need to hit (char)205 40 times.
	}
	std::cout << (char)188 << std::endl;

}


void Board::print_player_board_and_attack_radar()
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
		std::cout << std::setw(17); // Adds spaces betweeen the boards
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

// Clears the status of ships after the ship is destroyed, so we can contine through the loop
void Board::clear_hit()
{
	if (Piece::player_ptrl_boat_size == 0) { Piece::ptrl_boat_hit = false; }
	if (Piece::player_sub_size == 0) { Piece::sub_hit = false; }
	if (Piece::player_cruise_size == 0) { Piece::cruise_hit = false; }
	if (Piece::player_ac_size == 0) { Piece::ac_hit = false; }
	if (Piece::player_BS_size == 0) { Piece::BS_hit = false; }

}
// 'clears' the board
void Board::board_clearer()
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
	AI::comp_ship = 0;
	Player::ship_number = 0;
	Board::comp_piece_on_board = 14;
	Board::player_piece_on_board = 14;
	Piece::ptrl_boat_size = 2;
	Piece::player_ptrl_boat_size = 2;
	Piece::sub_size = 3;
	Piece::player_sub_size = 3;
	Piece::cruise_size = 3;
	Piece::player_cruise_size = 3;
	Piece::ac_size = 4;
	Piece::player_ac_size = 4;
	Piece::BS_size = 5;
	Piece::player_BS_size = 5;
}
// Tell the player to get ready, change the colour to red for flashy effect then back to white .. or grey cause I dont know what white is and it looks good enough for me
void Board::tell_player_shits_about_to_get_real() {
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

void Board::check_for_valid_cell()
{
	if (player_board[row][col] == '*')
	{
		if (Player::ship_number == 0)
		{
			player_board[row][col] = 'P';
		}
		else if (Player::ship_number == 1)
		{
			player_board[row][col] = 'S';
		}
		else if (Player::ship_number == 2)
		{
			player_board[row][col] = 'C';
		}
		else if (Player::ship_number == 3)
		{
			player_board[row][col] = 'A';
		}
		else if (Player::ship_number == 4)
		{
			player_board[row][col] = 'B';
		}
		Player::player_h_or_v();
	}
	else
	{
		// reprint the board, tell the player they stupid and already did that.
		Board::print_player_board_and_attack_radar();
		std::cout << std::setw(92) << "Sorry, It Seems Like That Spot Has Already Been Occupied." << std::endl << std::endl;
		Sleep(3000);
		Player::valid_ship_pos = false;
	}

}

void Board::player_h_or_v()
{
	print_player_board_and_attack_radar();
	std::cout << std::setw(80) << Player::player_ship_cords[0] << Player::player_ship_cords[1] << std::endl << std::endl;
	std::cout << std::setw(118) << " Enter (h) to set ship Horizontally Or (v) To Set It Vertically: ";
	std::cin.getline(Player::Hori_or_Vert, 20, '\n');
	// steve this was bullshit, it took me 2 weeks to get this done. I hate it.

	// if we enter h, and ship_number is '0', Ptrl_boat character is used, S for sub, C for Cruiser ect
	if (Player::Hori_or_Vert[0] == 'h')
	{
		if (Player::ship_number == 0 && player_board[row][col + 2] == '*')
		{
			player_board[row][col + 2] = 'P';  // Sets the ship at the position entered and will print to the right to fill the spaces the ship takes up
		}
		// if its ship_number 1 and the next 2 col spaces are free, prints out the 3 spaces for the Sub
		else if (Player::ship_number == 1 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'S';
			player_board[row][col + 4] = 'S';
		}
		// if its ship_number 1 and the next 3 col spaces are free, prints out the 4 spaces for the Cruiser
		else if (Player::ship_number == 2 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'C';
			player_board[row][col + 4] = 'C';
		}
		// I dont think I need to keep commenting these, We know what they do.
		else if (Player::ship_number == 3 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*')
		{
			player_board[row][col + 2] = 'A';
			player_board[row][col + 4] = 'A';
			player_board[row][col + 6] = 'A';
		}
		else if (Player::ship_number == 4 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*' && player_board[row][col + 8] == '*')
		{
			player_board[row][col + 2] = 'B';
			player_board[row][col + 4] = 'B';
			player_board[row][col + 6] = 'B';
			player_board[row][col + 8] = 'B';
		}
		else

		{ // if any space is occupied Not enough space to place
			print_player_board_and_attack_radar();		//reprint board
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Horizontally." << std::endl << std::endl; //yell at player
			Sleep(3000);	//pause to make the game look fancy... it doesnt but whateve
			player_board[row][col] = '*'; // make sure the space is a * still
			Player::valid_ship_pos = false;				// set valid_ship_pos to false so we run through the loop again
		}
	}
	else if (Player::Hori_or_Vert[0] == 'v')
	{
		// Same comments as the previous, this is just for the vert seting
		if (Player::ship_number == 0 && player_board[row + 2][col] == '*')
		{
			player_board[row + 2][col] = 'P';
		}
		else if (Player::ship_number == 1 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'S';
			player_board[row + 4][col] = 'S';
		}
		else if (Player::ship_number == 2 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'C';
			player_board[row + 4][col] = 'C';
		}
		else if (Player::ship_number == 3 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*')
		{
			player_board[row + 2][col] = 'A';
			player_board[row + 4][col] = 'A';
			player_board[row + 6][col] = 'A';
		}
		else if (Player::ship_number == 4 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*' && player_board[row + 8][col] == '*')
		{
			player_board[row + 2][col] = 'B';
			player_board[row + 4][col] = 'B';
			player_board[row + 6][col] = 'B';
			player_board[row + 8][col] = 'B';
		}
		else
		{
			Board::print_player_board_and_attack_radar();
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Vertically." << std::endl << std::endl;
			Sleep(3000);
			player_board[row][col] = '*';
			Player::valid_ship_pos = false;
		}
	}
	else
	{		// Tell the player they're dumb... I mean to put the right stuff in
		Board::print_player_board_and_attack_radar();
		std::cout << std::setw(135) << "Please Enter The Letter 'h' To Set Your Boat Horizontally Or 'v' To Set It Vertically." << std::endl << std::endl;
		player_board[row][col] = '*';
		Sleep(5000);
		Player::valid_ship_pos = false;
	}


}

void Board::values_of_row_col()
{
	if (Player::player_ship_cords[0] == 'a') { row = 0; }				// If the player enters 'a' as the first coords, the computer will know its actually position 0 in the array, repeat for each
	else if (Player::player_ship_cords[0] == 'b') { row = 2; }			// rows are 
	else if (Player::player_ship_cords[0] == 'c') { row = 4; }
	else if (Player::player_ship_cords[0] == 'd') { row = 6; }
	else if (Player::player_ship_cords[0] == 'e') { row = 8; }
	else if (Player::player_ship_cords[0] == 'f') { row = 10; }
	else if (Player::player_ship_cords[0] == 'g') { row = 12; }
	else if (Player::player_ship_cords[0] == 'h') { row = 14; }
	else if (Player::player_ship_cords[0] == 'i') { row = 16; }
	else if (Player::player_ship_cords[0] == 'j') { row = 18; }

	// Sets the rows to the proper values 
	if (Player::player_ship_cords[1] == '0') { col = 3; }
	else if (Player::player_ship_cords[1] == '1') { col = 5; }
	else if (Player::player_ship_cords[1] == '2') { col = 7; }
	else if (Player::player_ship_cords[1] == '3') { col = 9; }
	else if (Player::player_ship_cords[1] == '4') { col = 11; }
	else if (Player::player_ship_cords[1] == '5') { col = 13; }
	else if (Player::player_ship_cords[1] == '6') { col = 15; }
	else if (Player::player_ship_cords[1] == '7') { col = 17; }
	else if (Player::player_ship_cords[1] == '8') { col = 19; }
	else if (Player::player_ship_cords[1] == '9') { col = 21; }
}

void Board::values_of_attack_row_col()
{
	if (Player::player_atk_cords[0] == 'a') { atk_row = 0; }
	else if (Player::player_atk_cords[0] == 'b') { atk_row = 2; }
	else if (Player::player_atk_cords[0] == 'c') { atk_row = 4; }
	else if (Player::player_atk_cords[0] == 'd') { atk_row = 6; }
	else if (Player::player_atk_cords[0] == 'e') { atk_row = 8; }
	else if (Player::player_atk_cords[0] == 'f') { atk_row = 10; }
	else if (Player::player_atk_cords[0] == 'g') { atk_row = 12; }
	else if (Player::player_atk_cords[0] == 'h') { atk_row = 14; }
	else if (Player::player_atk_cords[0] == 'i') { atk_row = 16; }
	else if (Player::player_atk_cords[0] == 'j') { atk_row = 18; }
	// assigns the value the player entered for the second Coords input, for the second coord input.

	if (Player::player_atk_cords[1] == '0') { atk_col = 3; }
	else if (Player::player_atk_cords[1] == '1') { atk_col = 5; }
	else if (Player::player_atk_cords[1] == '2') { atk_col = 7; }
	else if (Player::player_atk_cords[1] == '3') { atk_col = 9; }
	else if (Player::player_atk_cords[1] == '4') { atk_col = 11; }
	else if (Player::player_atk_cords[1] == '5') { atk_col = 13; }
	else if (Player::player_atk_cords[1] == '6') { atk_col = 15; }
	else if (Player::player_atk_cords[1] == '7') { atk_col = 17; }
	else if (Player::player_atk_cords[1] == '8') { atk_col = 19; }
	else if (Player::player_atk_cords[1] == '9') { atk_col = 21; }
}
void Board::player_sets_atk_on_board()
{
	if (player_atk_radar[atk_row][atk_col] == '!' || player_atk_radar[atk_row][atk_col] == '$')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(82) << "You Have Already Attacked That Position.";
		Sleep(3000);
		Player::valid_atk_cord = false;
	}
	else if (Comp_board[atk_row][atk_col] == 'P')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(84) << "You Hit Their Patrol Boat.";
		player_atk_radar[atk_row][atk_col] = '!';
		Piece::ptrl_boat_size--;
		comp_piece_on_board--;
	}
	else if (Comp_board[atk_row][atk_col] == 'S')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(84) << "You Hit Their Submarine.";
		player_atk_radar[atk_row][atk_col] = '!';
		Piece::sub_size--;
		comp_piece_on_board--;
	}
	else if (Comp_board[atk_row][atk_col] == 'C')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(84) << "You Hit Their Cruiser.";
		player_atk_radar[atk_row][atk_col] = '!';
		Piece::cruise_size--;
		comp_piece_on_board--;
	}
	else if (Comp_board[atk_row][atk_col] == 'A')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(84) << "You Hit Their Aircraft Carrier.";
		player_atk_radar[atk_row][atk_col] = '!';
		Piece::ac_size--;
		comp_piece_on_board--;
	}
	else if (Comp_board[atk_row][atk_col] == 'B')
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(84) << " You Hit Their Battleship";
		player_atk_radar[atk_row][atk_col] = '!';
		Piece::BS_size--;
		comp_piece_on_board--;
	}
	else
	{
		print_player_board_and_attack_radar();
		std::cout << std::setw(71) << "Nope. You Missed." << std::endl << std::endl;
		player_atk_radar[atk_row][atk_col] = '$';
	}
}

void Board::is_comp_move_valid()
{
	// checks the array for an empty space '*' to place ships in, its empty we can place the current ships character at the position, this is for the cvomputer so we dont see this
	if (Comp_board[comp_row][comp_col] == '*')
	{
		if (AI::comp_ship == 0)
		{
			Comp_board[comp_row][comp_col] = 'P';
		}
		else if (AI::comp_ship == 1)
		{
			Comp_board[comp_row][comp_col] = 'S';
		}
		else if (AI::comp_ship == 2)
		{
			Comp_board[comp_row][comp_col] = 'C';
		}
		else if (AI::comp_ship == 3)
		{
			Comp_board[comp_row][comp_col] = 'A';
		}
		else if (AI::comp_ship == 4)
		{
			Comp_board[comp_row][comp_col] = 'B';
		}
		comp_h_or_v(); // same a player. let them place horizontally or vertically
	}
	else {
		AI::valid_comp_ship_pos = false; // if the space isnt empty, try again
	}
}
void Board::comp_h_or_v()
{
	AI::comp_hv = rand() % 1 + 1; // Computer will randomly choose hori or vert
	if (AI::comp_hv == 1)
	{		// this is the same as the players h_or_v but for the Compter.
		if (AI::comp_ship == 0 && Comp_board[comp_row][comp_col + 2] == '*')
		{
			Comp_board[comp_row][comp_col + 2] = 'P';
		}
		else if (AI::comp_ship == 1 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*')
		{
			Comp_board[comp_row][comp_col + 2] = 'S';
			Comp_board[comp_row][comp_col + 4] = 'S';
		}
		else if (AI::comp_ship == 2 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*')
		{
			Comp_board[comp_row][comp_col + 2] = 'C';
			Comp_board[comp_row][comp_col + 4] = 'C';
		}
		else if (AI::comp_ship == 3 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*' && Comp_board[comp_row][comp_col + 6] == '*')
		{
			Comp_board[comp_row][comp_col + 2] = 'A';
			Comp_board[comp_row][comp_col + 4] = 'A';
			Comp_board[comp_row][comp_col + 6] = 'A';
		}
		else if (AI::comp_ship == 4 && Comp_board[comp_row][comp_col + 2] == '*' && Comp_board[comp_row][comp_col + 4] == '*' && Comp_board[comp_row][comp_col + 6] == '*' && Comp_board[comp_row][comp_col + 8] == '*')
		{
			Comp_board[comp_row][comp_col = 2] = 'B';
			Comp_board[comp_row][comp_col + 4] = 'B';
			Comp_board[comp_row][comp_col + 6] = 'B';
			Comp_board[comp_row][comp_col + 8] = 'B';
		}
		else
		{
			Comp_board[comp_row][comp_col] = '*';
			AI::valid_comp_ship_pos = false;
		}
	}
	else if (AI::comp_hv == 2)
	{
		if (AI::comp_ship == 0 && Comp_board[comp_row + 1][comp_col] == '*')
		{
			Comp_board[comp_row + 1][comp_col] = 'P';
		}
		else if (AI::comp_ship == 1 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*')
		{
			Comp_board[comp_row + 1][comp_col] = 'S';
			Comp_board[comp_row + 3][comp_col] = 'S';
		}
		else if (AI::comp_ship == 2 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*')
		{
			Comp_board[comp_row + 1][comp_col] = 'C';
			Comp_board[comp_row + 3][comp_col] = 'C';
		}
		else if (AI::comp_ship == 3 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*' && Comp_board[comp_row + 5][comp_col] == '*')
		{
			Comp_board[comp_row + 1][comp_col] = 'A';
			Comp_board[comp_row + 3][comp_col] = 'A';
			Comp_board[comp_row + 5][comp_col] = 'A';

		}
		else if (AI::comp_ship == 4 && Comp_board[comp_row + 1][comp_col] == '*' && Comp_board[comp_row + 3][comp_col] == '*' && Comp_board[comp_row + 5][comp_col] == '*' && Comp_board[comp_row + 7][comp_col] == '*')
		{
			Comp_board[comp_row + 1][comp_col] = 'B';
			Comp_board[comp_row + 3][comp_col] = 'B';
			Comp_board[comp_row + 5][comp_col] = 'B';
			Comp_board[comp_row + 7][comp_col] = 'B';

		}
		else {
			Comp_board[comp_row][comp_col] = '*';
			AI::valid_comp_ship_pos = false;
		}
	}
	system("CLS");
}
void Board::computer_move_is_valid() {
	if (Comp_board[comp_row][comp_col] == '*')
	{
		if (AI::comp_ship == 0) { Comp_board[comp_row][comp_col] = 'P'; }
		else if (AI::comp_ship == 1) { Comp_board[comp_row][comp_col] = 'S'; }
		else if (AI::comp_ship == 2) { Comp_board[comp_row][comp_col] = 'C'; }
		else if (AI::comp_ship == 3) { Comp_board[comp_row][comp_col] = 'A'; }
		else if (AI::comp_ship == 4) { Comp_board[comp_row][comp_col] = 'B'; }
		comp_h_or_v();
	}
	else {
		AI::valid_comp_ship_pos = false;
	}
}

void Board::comp_sets_atk()
{
	do
	{
		// Sets valid_comp_atk_cord to true
		AI::valid_comp_atk_cord = true;
		AI::comp_atk_row = (rand() % 10) * 2;		// Generates a Random even number between 0-8
		AI::comp_atk_col = ((rand() % 10) * 2) + 1;  // Generates a Random ODD number between 1-9

		// If the location targeted is P, S, C, A or B. The we know it hit a ship and can move to changing the board
		if (Piece::ptrl_boat_hit == true)
		{
			if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'P') { comp_sets_atk_onboard(); }
			else { AI::valid_comp_atk_cord = false; }
		}
		else if (Piece::sub_hit == true)
		{
			if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'S') { comp_sets_atk_onboard(); }
			else { AI::valid_comp_atk_cord = false; }
		}
		else if (Piece::cruise_hit == true)
		{
			if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'C') { comp_sets_atk_onboard(); }
			else { AI::valid_comp_atk_cord = false; }
		}
		else if (Piece::ac_hit == true)
		{
			if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'A') { comp_sets_atk_onboard(); }
			else { AI::valid_comp_atk_cord = false; }
		}
		else if (Piece::BS_hit == true)
		{
			if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'B') { comp_sets_atk_onboard(); }
			else { AI::valid_comp_atk_cord = false; }
		}
		if (Piece::ptrl_boat_hit == false && Piece::sub_hit == false && Piece::cruise_hit == false && Piece::ac_hit == false && Piece::BS_hit == false)
		{
			comp_sets_atk_onboard();
		}
	} while (!AI::valid_comp_atk_cord || player_piece_on_board > 0);
}

void Board::comp_sets_atk_onboard()
{
	AI::comp_cords_to_alpha();
	if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'P')
	{
		std::cout << std::setw(82) << "The Computer Has Hit Your Patrol Boat: " << AI::aplha_comp_atk << (AI::comp_atk_col / 2) << std::endl << std::endl;
		Piece::ptrl_boat_hit = true;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '!';
		player_piece_on_board--;
		Piece::player_ptrl_boat_size--;
	}
	else if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'S')
	{
		std::cout << std::setw(81) << "The Computer Has Hit Your Submarine: " << AI::aplha_comp_atk << (AI::comp_atk_col / 2) << std::endl << std::endl;
		Piece::sub_hit = true;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '!';
		player_piece_on_board--;
		Piece::player_sub_size--;
	}
	else if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'C')
	{
		std::cout << std::setw(81) << "The Computer Has Hit Your Cruiser: " << AI::aplha_comp_atk << (AI::comp_atk_col / 2) << std::endl << std::endl;
		Piece::cruise_hit = true;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '!';
		player_piece_on_board--;
		Piece::player_cruise_size--;
	}
	else if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'A')
	{
		std::cout << std::setw(81) << "The Computer Has Hit Your Aircraft Carrier: " << AI::aplha_comp_atk << (AI::comp_atk_col / 2) << std::endl << std::endl;
		Piece::ac_hit = true;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '!';
		player_piece_on_board--;
		Piece::player_ac_size--;
	}
	else if (player_board[AI::comp_atk_row][AI::comp_atk_col] == 'B')
	{
		std::cout << std::setw(81) << "The Computer Has Hit Your Battleship: " << AI::aplha_comp_atk << (AI::comp_atk_col / 2) << std::endl << std::endl;
		Piece::BS_hit = true;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '!';
		player_piece_on_board--;
		Piece::player_BS_size--;
	}
	else if (player_board[AI::comp_atk_row][AI::comp_atk_col] == '*')
	{
		std::cout << std::setw(73) << "The Computer Missed: " << AI::aplha_comp_atk << (AI::comp_atk_row / 2) << std::endl << std::endl;
		player_board[AI::comp_atk_row][AI::comp_atk_col] = '$';
	}
	else
	{
		AI::valid_comp_atk_cord = false;
	}

	clear_hit();

	if (player_piece_on_board == 0)
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
	else if (AI::valid_comp_atk_cord == true)
	{
		Sleep(3000);
		Player::player_sets_atk();
	}

}

// assigns the computers first coord seclection to cords to a letter
// just looks better for the player
void Board::comp_cords_to_alpha()
{
	if (AI::comp_atk_row == 0) { comp_row = 'a'; }
	else if (AI::comp_atk_row == 2) { comp_row = 'b'; }
	else if (AI::comp_atk_row == 4) { comp_row = 'c'; }
	else if (AI::comp_atk_row == 6) { comp_row = 'd'; }
	else if (AI::comp_atk_row == 8) { comp_row = 'e'; }
	else if (AI::comp_atk_row == 10) { comp_row = 'f'; }
	else if (AI::comp_atk_row == 12) { comp_row = 'g'; }
	else if (AI::comp_atk_row == 14) { comp_row = 'h'; }
	else if (AI::comp_atk_row == 16) { comp_row = 'i'; }
	else if (AI::comp_atk_row == 18) { comp_row = 'j'; }
}

// Get the computer to randomly place their ships
void Board::take_comp_input() {

	do {

		// clear the screen, makes it look like a 'loading screen' a bit... Probably shouldnt do it this way tbh but it works
		system("CLS");
		for (int i = 0; i < 19; i++)
		{
			std::cout << std::endl;
		}
		std::cout << std::setw(90) << "Waiting For Computer To Set Ships On It's Board.......";

		AI::valid_comp_ship_pos = true;			// sets to true at start, in is_comp_move_valid we may change it back to run this again but the numbers generated suck
		srand(time(0));
		comp_row = 2 * rand() % 11;			// gets a Random even number
		comp_col = 1 + (2 * rand()) % 11;	// gets a Random Odd number
		is_comp_move_valid();				// checks if the space is a *, a * is a valid space to place a ship
		if (AI::valid_comp_ship_pos == true) {
			AI::comp_ship++;
		}
	} while (AI::comp_ship < 5 || !AI::valid_comp_ship_pos);

	// Tell the player the computer is done and ready, and its their turn to place ships
	system("CLS");
	for (int i = 0; i < 19; i++) {
		std::cout << std::endl;
	}
	std::cout << std::setw(90) << "The Computer Has Set It's Ships. Now It's Your Turn.";
	Sleep(3000);
	system("CLS");

}



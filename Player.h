#pragma once
class Player
{
public :
	Player();
	~Player(); 

	static bool valid_ship_pos;		// to check if the position of the ship is valid while placing it/firing on it
	static bool valid_atk_cord;		// checks if the place was fired upon already or not
	static int ship_number;		// Number of ships left in the game
	//Placing Pieces 
	// variables for "attacking" other pieces
	static char player_ship_cords[10];
	static char player_atk_cords[10];
	//Placing Pieces
// player ship Horizontal or Verticle
	static char Hori_or_Vert[20];

	static void player_place_ships();
	static void check_cords();
	static void check_for_valid_cell();
	static void player_h_or_v();
	static void values_of_row_col();
	static void values_of_attack_row_col();
	static void player_sets_atk();
	static void check_correct_atk_cords();
	static void player_sets_atk_on_board();
};


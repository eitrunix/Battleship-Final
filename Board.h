#include <iostream>
#include <iomanip>

class Board
{
public:
	Board();
	~Board();

	static void display_ship_statuses();
	static void print_player_board_and_attack_radar();
	static void board_clearer();
	static void clear_hit();
	void Init();
	static void tell_player_shits_about_to_get_real();

	//Board Variables
// Vairables for "finding" a spot on the "map"
	static int row, col;
	static int atk_row, atk_col;
	//total number of spaces the ships will take up during the game
	static int comp_piece_on_board;
	static int player_piece_on_board;
	static int comp_row, comp_col;

	static void check_for_valid_cell();
	static void player_h_or_v();
	static void values_of_row_col();
	static void values_of_attack_row_col();
	static void player_sets_atk_on_board();
	static void comp_sets_atk_onboard();
	static void comp_sets_atk();
	static void computer_move_is_valid();
	static void is_comp_move_valid();
	static void comp_h_or_v();
	static void take_comp_input();
	static void comp_cords_to_alpha();
};
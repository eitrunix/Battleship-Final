#pragma once
class AI
{
public:
	AI();
	~AI();

	void Init();
	static void comp_cords_to_alpha();
	static void take_comp_input();
	static void is_comp_move_valid();
	static void comp_h_or_v();
	static void computer_move_is_valid();
	static void comp_sets_atk();
	static void comp_sets_atk_onboard();


	static int comp_ship;			// Number of computer  ships left in the game

	static int comp_atk_row, comp_atk_col;

	static bool valid_comp_ship_pos;	// same as above but for computer
	static bool valid_comp_atk_cord;	// same but for computer
	//AI Attacking
	static int comp_hv;				// computer ships hoz or vert

	static char aplha_comp_atk;		// to check the first part of the computers "firing" cords, used to change the number we generate to a letter...its not working wtf???

};


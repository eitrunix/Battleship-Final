#pragma once
class AI
{
public:
	AI();
	~AI();

	int comp_ship;			// Number of computer  ships left in the game

	int comp_atk_row, comp_atk_col;

	bool valid_comp_ship_pos;	// same as above but for computer
	bool valid_comp_atk_cord;	// same but for computer
	//AI Attacking
	int comp_hv;				// computer ships hoz or vert

	char aplha_comp_atk;		// to check the first part of the computers "firing" cords, used to change the number we generate to a letter...its not working wtf???

};


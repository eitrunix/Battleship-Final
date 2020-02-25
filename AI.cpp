#include "AI.h"

AI::AI()
{
	comp_ship = 0;			// Number of computer  ships left in the game

	comp_atk_row, comp_atk_col;

	valid_comp_ship_pos;	// same as above but for computer
	valid_comp_atk_cord;	// same but for computer
	//AI Attacking
	comp_hv;				// computer ships hoz or vert

	aplha_comp_atk;		// to check the first part of the computers "firing" cords, used to change the number we generate to a letter...its not working wtf???

}

AI::~AI()
{
}


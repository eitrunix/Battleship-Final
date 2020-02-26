#include "Piece.h"
// Sizes of Ships, also hit point values

Piece::Piece()
{
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
	// Variables for each individual ship to check for hits and misses
	ptrl_boat_hit = false;
	sub_hit = false;
	cruise_hit = false;
	ac_hit = false;
	BS_hit = false;

	hit = false;			// variable for if something is hit or not.
}

Piece::~Piece()
{
}

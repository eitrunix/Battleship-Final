#include "Piece.h"
// Sizes of Ships, also hit point values
void init()
{
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
	// Variables for each individual ship to check for hits and misses
	Piece::ptrl_boat_hit = false;
	Piece::sub_hit = false;
	Piece::cruise_hit = false;
	Piece::ac_hit = false;
	Piece::BS_hit = false;

	Piece::hit = false;			// variable for if something is hit or not.
}
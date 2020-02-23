#pragma once
class Piece
{
public:
	Piece();
	~Piece();


	//Pieces 
// Sizes of Ships, also hit point values
	static int ptrl_boat_size, player_ptrl_boat_size;
	static int sub_size, player_sub_size;
	static int cruise_size, player_cruise_size;
	static int ac_size, player_ac_size;
	static int BS_size, player_BS_size;
	// Variables for each individual ship to check for hits and misses
	static bool ptrl_boat_hit;
	static bool sub_hit;
	static bool cruise_hit;
	static bool ac_hit;
	static bool BS_hit;

	static bool hit;			// variable for if something is hit or not.

};


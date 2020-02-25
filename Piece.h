#pragma once
class Piece
{
public:
	Piece();
	~Piece();


	//Pieces 
// Sizes of Ships, also hit point values
	int ptrl_boat_size, player_ptrl_boat_size;
	int sub_size, player_sub_size;
	int cruise_size, player_cruise_size;
	int ac_size, player_ac_size;
	int BS_size, player_BS_size;
	// Variables for each individual ship to check for hits and misses
	bool ptrl_boat_hit;
	bool sub_hit;
	bool cruise_hit;
	bool ac_hit;
	bool BS_hit;

	bool hit;			// variable for if something is hit or not.

};


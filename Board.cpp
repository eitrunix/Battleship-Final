#include "Player.h"
#include "AI.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Scoreboard.h"

using namespace DataStructuresAndAI;

Player* player;
AI* Ai;
Scoreboard* scoreboard;
Battleship* battleship = new Battleship();
AircraftCarrier* aircraftCarrier = new AircraftCarrier();
Cruiser* cruiser = new Cruiser();
Submarine* submarine = new Submarine();
PatrolBoat* patrolBoat = new PatrolBoat();

char player_atk_radar[19][23]
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

char player_board[19][23] =
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
char Comp_board[19][23] =
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

LinkList<Piece*> pieces;
LinkList<Piece*>::Iterator itr;

LinkList<Piece*> aiPieces;
LinkList<Piece*>::Iterator itr2;

Board::Board()
{
	player = new Player();
	Ai = new AI();
	

	pieces.push_back(battleship);
	pieces.push_back(aircraftCarrier);
	pieces.push_back(cruiser); 
	pieces.push_back(submarine);
	pieces.push_back(patrolBoat);

	aiPieces.push_back(battleship);
	aiPieces.push_back(aircraftCarrier);
	aiPieces.push_back(cruiser);
	aiPieces.push_back(submarine);
	aiPieces.push_back(patrolBoat);

	itr = pieces.begin();
	itr2 = aiPieces.begin();


}
Board::~Board()
{
}
// Clears the status of ships after the ship is destroyed, so we can contine through the loop
void Board::ClearHits()
{
	for (itr; itr != pieces.end(); itr++)
	{
		Piece* p = *itr;
		p->health = 0;
		p->hit = false;
	}
	for (itr2; itr2 != aiPieces.end(); itr2++)
	{
		Piece* p = *itr2;
		p->health = 0;
		p->hit = false;
	}


}
void Board::ClearBoard()
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
	Ai->comp_ship = 0;
	player->shipNumber = 0;
	PieceOnBoard_Comp = 14;
	PieceOnBoard_Player = 14;

	//PlayerPiece.PatrolBoatHealth = 2;
	//PlayerPiece.SubmarineHealth = 3;
	//PlayerPiece.CruiserHealth = 3;
	//PlayerPiece.AircraftCarrierHealth = 4;
	//PlayerPiece.BattleshipHealth = 5;

	//AiPiece.PatrolBoatHealth = 2;
	//AiPiece.SubmarineHealth = 3;
	//AiPiece.CruiserHealth = 3;
	//AiPiece.AircraftCarrierHealth = 4;
	//AiPiece.BattleshipHealth = 5;

	
}
void Board::PrintBoards()
{
	DisplayScoreboard();
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
void Board::EnterName()
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << std::endl;
	}
	std::cout << std::setw(70) << "Enter Name: ";
	getline(std::cin, name);

	scoreboard = new Scoreboard(pieces, aiPieces, name);
	scoreboard->GetScore();


}
void Board::DisplayScoreboard()
{
	scoreboard->GetScore();
	scoreboard->PrintBoard();
}
void Board::PlayerPlaceShips()
{
	{
		do
		{
			// we will go through the 'list' of ships to place, 0-4 (5 ships total) and checks if the placement is okay, 'places' the ship on the board, increments ship_number by 1, then checks the next statement
			// we leave the loop if ship_number is 5 of greater
			player->validShipPos = true;
			if (player->shipNumber == 0)
			{
				std::cout << std::setw(109) << "Enter The Coordinate For Your Patrol Boat (2 spots): ";
			}
			else if (player->shipNumber == 1)
			{
				std::cout << std::setw(109) << "Enter The Coordinate For Your Submarine (3 spots): ";
			}
			else if (player->shipNumber == 2)
			{
				std::cout << std::setw(108) << "Enter The Coordinate For Your Crusier (4 spots): ";
			}
			else if (player->shipNumber == 3)
			{
				std::cout << std::setw(107) << "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
			}
			else if (player->shipNumber == 4)
			{
				std::cout << std::setw(100) << "Enter the Coordinate For Your Battleship (5 spots): ";
			}
			std::cin.getline(player->playerShipCords, 11, '\n');  // Ask for the players input in cords,
			std::cout << std::endl << std::endl;
			CheckCords();									// Check if its a valid placement
			system("CLS");
			PrintBoards();			// Reprint the new board with the new piece on it.
			if (player->validShipPos == true)
			{
				player->shipNumber++;								// If we did place a ship, we add to the ship number, so we dont end up placing more ships than we need (0-4)
			}
		} while (!player->validShipPos || player->shipNumber < 5); //do this while valid_ship_pos is false and the ship number is less than 5
	}
}
void Board::CheckCords()
{
	// function to check if the player entered in the correct information or not. should only let letter+number combo eg "A4. While 6A" or "2435234vkj", should come back with please enter valid input
	if (player->playerShipCords[0] < 'a' || player->playerShipCords[0] > 'j' || player->playerShipCords[1] < '0' || player->playerShipCords[1] > '9')
	{
		player->validShipPos = false;					// sets vaild position to false
		PrintBoards();    // reprint the board
		std::cout << std::setw(97) << "You entered incorrect Coordinates" << std::endl;
		std::cout << std::setw(122) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. Eg = a3" << std::endl;
		Sleep(1000);
	}
	else {
		// Check the values of the rows and colums to match with the input.
		RowColVals();
		// check if the position specified is empty or not
		CheckValidCell();
	}
}
void Board::CheckValidCell()
{
	if (player_board[row][col] == '*')
	{
		if (player->shipNumber == 0)
		{
			player_board[row][col] = 'P';
		}
		else if (player->shipNumber == 1)
		{
			player_board[row][col] = 'S';
		}
		else if (player->shipNumber == 2)
		{
			player_board[row][col] = 'C';
		}
		else if (player->shipNumber == 3)
		{
			player_board[row][col] = 'A';
		}
		else if (player->shipNumber == 4)
		{
			player_board[row][col] = 'B';
		}
		PlayerHoV();
	}
	else
	{
		// reprint the board, tell the player they stupid and already did that.
		PrintBoards();
		std::cout << std::setw(92) << "Sorry, It Seems Like That Spot Has Already Been Occupied." << std::endl << std::endl;
		Sleep(3000);
		player->validShipPos = false;
	}

}
void Board::PlayerHoV()
{
	PrintBoards();
	std::cout << std::setw(80) << player->playerShipCords[0] << player->playerShipCords[1] << std::endl << std::endl;
	std::cout << std::setw(118) << " Enter (h) to set ship Horizontally Or (v) To Set It Vertically: ";
	std::cin.getline(player->HoV, 20, '\n');

	// if we enter h, and ship_number is '0', Ptrl_boat character is used, S for sub, C for Cruiser ect
	if (player->HoV[0] == 'h')
	{
		if (player->shipNumber == 0 && player_board[row][col + 2] == '*')
		{
			player_board[row][col + 2] = 'P';  // Sets the ship at the position entered and will print to the right to fill the spaces the ship takes up
		}
		// if its ship_number 1 and the next 2 col spaces are free, prints out the 3 spaces for the Sub
		else if (player->shipNumber == 1 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'S';
			player_board[row][col + 4] = 'S';
		}
		// if its ship_number 1 and the next 3 col spaces are free, prints out the 4 spaces for the Cruiser
		else if (player->shipNumber == 2 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'C';
			player_board[row][col + 4] = 'C';
		}
		// I dont think I need to keep commenting these, We know what they do.
		else if (player->shipNumber == 3 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*')
		{
			player_board[row][col + 2] = 'A';
			player_board[row][col + 4] = 'A';
			player_board[row][col + 6] = 'A';
		}
		else if (player->shipNumber == 4 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*' && player_board[row][col + 8] == '*')
		{
			player_board[row][col + 2] = 'B';
			player_board[row][col + 4] = 'B';
			player_board[row][col + 6] = 'B';
			player_board[row][col + 8] = 'B';
		}
		else

		{ // if any space is occupied Not enough space to place
			PrintBoards();		//reprint board
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Horizontally." << std::endl << std::endl; //yell at player
			Sleep(3000);	//pause to make the game look fancy... it doesnt but whateve
			player_board[row][col] = '*'; // make sure the space is a * still
			player->validShipPos = false;				// set valid_ship_pos to false so we run through the loop again
		}
	}
	else if (player->HoV[0] == 'v')
	{
		// Same comments as the previous, this is just for the vert seting
		if (player->shipNumber == 0 && player_board[row + 2][col] == '*')
		{
			player_board[row + 2][col] = 'P';
		}
		else if (player->shipNumber == 1 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'S';
			player_board[row + 4][col] = 'S';
		}
		else if (player->shipNumber == 2 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'C';
			player_board[row + 4][col] = 'C';
		}
		else if (player->shipNumber == 3 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*')
		{
			player_board[row + 2][col] = 'A';
			player_board[row + 4][col] = 'A';
			player_board[row + 6][col] = 'A';
		}
		else if (player->shipNumber == 4 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*' && player_board[row + 8][col] == '*')
		{
			player_board[row + 2][col] = 'B';
			player_board[row + 4][col] = 'B';
			player_board[row + 6][col] = 'B';
			player_board[row + 8][col] = 'B';
		}
		else
		{
			PrintBoards();
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Vertically." << std::endl << std::endl;
			Sleep(3000);
			player_board[row][col] = '*';
			player->validShipPos = false;
		}
	}
	else
	{		// Tell the player they're dumb... I mean to put the right stuff in
		PrintBoards();
		std::cout << std::setw(135) << "Please Enter The Letter 'h' To Set Your Boat Horizontally Or 'v' To Set It Vertically." << std::endl << std::endl;
		player_board[row][col] = '*';
		Sleep(5000);
		player->validShipPos = false;
	}


}
void Board::RowColVals()
{
	if (player->playerShipCords[0] == 'a') { row = 0; }				// If the player enters 'a' as the first coords, the computer will know its actually position 0 in the array, repeat for each
	else if (player->playerShipCords[0] == 'b') { row = 2; }			// rows are 
	else if (player->playerShipCords[0] == 'c') { row = 4; }
	else if (player->playerShipCords[0] == 'd') { row = 6; }
	else if (player->playerShipCords[0] == 'e') { row = 8; }
	else if (player->playerShipCords[0] == 'f') { row = 10; }
	else if (player->playerShipCords[0] == 'g') { row = 12; }
	else if (player->playerShipCords[0] == 'h') { row = 14; }
	else if (player->playerShipCords[0] == 'i') { row = 16; }
	else if (player->playerShipCords[0] == 'j') { row = 18; }

	// Sets the rows to the proper values 
	if (player->playerShipCords[1] == '0') { col = 3; }
	else if (player->playerShipCords[1] == '1') { col = 5; }
	else if (player->playerShipCords[1] == '2') { col = 7; }
	else if (player->playerShipCords[1] == '3') { col = 9; }
	else if (player->playerShipCords[1] == '4') { col = 11; }
	else if (player->playerShipCords[1] == '5') { col = 13; }
	else if (player->playerShipCords[1] == '6') { col = 15; }
	else if (player->playerShipCords[1] == '7') { col = 17; }
	else if (player->playerShipCords[1] == '8') { col = 19; }
	else if (player->playerShipCords[1] == '9') { col = 21; }
}
void Board::RowColAtkVals()
{
	if (player->playerAtkCords[0] == 'a') { atkRow = 0; }
	else if (player->playerAtkCords[0] == 'b') { atkRow = 2; }
	else if (player->playerAtkCords[0] == 'c') { atkRow = 4; }
	else if (player->playerAtkCords[0] == 'd') { atkRow = 6; }
	else if (player->playerAtkCords[0] == 'e') { atkRow = 8; }
	else if (player->playerAtkCords[0] == 'f') { atkRow = 10; }
	else if (player->playerAtkCords[0] == 'g') { atkRow = 12; }
	else if (player->playerAtkCords[0] == 'h') { atkRow = 14; }
	else if (player->playerAtkCords[0] == 'i') { atkRow = 16; }
	else if (player->playerAtkCords[0] == 'j') { atkRow = 18; }
	// assigns the value the player entered for the second Coords input, for the second coord input.

	if (player->playerAtkCords[1] == '0') { atkCol = 3; }
	else if (player->playerAtkCords[1] == '1') { atkCol = 5; }
	else if (player->playerAtkCords[1] == '2') { atkCol = 7; }
	else if (player->playerAtkCords[1] == '3') { atkCol = 9; }
	else if (player->playerAtkCords[1] == '4') { atkCol = 11; }
	else if (player->playerAtkCords[1] == '5') { atkCol = 13; }
	else if (player->playerAtkCords[1] == '6') { atkCol = 15; }
	else if (player->playerAtkCords[1] == '7') { atkCol = 17; }
	else if (player->playerAtkCords[1] == '8') { atkCol = 19; }
	else if (player->playerAtkCords[1] == '9') { atkCol = 21; }
}
void Board::AICordsToAlpha()
{
	if (Ai->comp_atk_row == 0) { compRow = 'a'; }
	else if (Ai->comp_atk_row == 2) { compRow = 'b'; }
	else if (Ai->comp_atk_row == 4) { compRow = 'c'; }
	else if (Ai->comp_atk_row == 6) { compRow = 'd'; }
	else if (Ai->comp_atk_row == 8) { compRow = 'e'; }
	else if (Ai->comp_atk_row == 10) { compRow = 'f'; }
	else if (Ai->comp_atk_row == 12) { compRow = 'g'; }
	else if (Ai->comp_atk_row == 14) { compRow = 'h'; }
	else if (Ai->comp_atk_row == 16) { compRow = 'i'; }
	else if (Ai->comp_atk_row == 18) { compRow = 'j'; }
}
void Board::AISetShips()
{

	do {
		bool success = true;
		// clear the screen, makes it look like a 'loading screen' a bit... Probably shouldnt do it this way tbh but it works
		system("CLS");
		for (int i = 0; i < 19; i++)
		{
			std::cout << std::endl;
		}
		std::cout << std::setw(90) << "Waiting For Computer To Set Ships On It's Board.......";

		Ai->valid_comp_ship_pos = true;			// sets to true at start, in is_comp_move_valid we may change it back to run this again but the numbers generated suck
		srand(time(0));
		if(success)
		{
			compRow = 2 * rand() % 11;			// gets a Random even number
			compCol = 1 + (2 * rand()) % 11;	// gets a Random Odd number
		}
		CheckValidMoveAI();				// checks if the space is a *, a * is a valid space to place a ship
		if (Ai->valid_comp_ship_pos == true) {
			Ai->comp_ship++;
		}
		else
		{
			success = false;
			compCol++;
			if (compCol >= 23 || compRow >= 19)
			{
				success = true;
			}
		}
	} while (Ai->comp_ship < 5 || !Ai->valid_comp_ship_pos);

	// Tell the player the computer is done and ready, and its their turn to place ships
	system("CLS");
	for (int i = 0; i < 19; i++) {
		std::cout << std::endl;
	}
	std::cout << std::setw(90) << "The Computer Has Set It's Ships. Now It's Your Turn.";
	Sleep(3000);
	system("CLS");

}
void Board::FakeLoadingScreeen()
{
	for (int i = 0; i < 4; i++)
	{
		system("CLS");
		system("Color 0C");
		for (int i = 0; i < 18; i++)
		{
			std::cout << std::endl;
		}

		Sleep(500);
		std::cout << std::setw(74) << "Get Ready For Battle....";
		Sleep(500);
		system("Color 08");
	}
}
void Board::CheckValidMoveAI()
{
	// checks the array for an empty space '*' to place ships in, its empty we can place the current ships character at the position, this is for the cvomputer so we dont see this
	if (Comp_board[compRow][compCol] == '*')
	{
		if (Ai->comp_ship == 0)
		{
			Comp_board[compRow][compCol] = 'P';
		}
		else if (Ai->comp_ship == 1)
		{
			Comp_board[compRow][compCol] = 'S';
		}
		else if (Ai->comp_ship == 2)
		{
			Comp_board[compRow][compCol] = 'C';
		}
		else if (Ai->comp_ship == 3)
		{
			Comp_board[compRow][compCol] = 'A';
		}
		else if (Ai->comp_ship == 4)
		{
			Comp_board[compRow][compCol] = 'B';
		}
		AIHoV(); // same a player. let them place horizontally or vertically
	}
	else {
		Ai->valid_comp_ship_pos = false; // if the space isnt empty, try again
	}
}
void Board::AIHoV()
{
	Ai->comp_hv = rand() % 2 + 1; // Computer will randomly choose hori or vert
	if (Ai->comp_hv == 1)
	{		// this is the same as the players h_or_v but for the Compter.
		if (Ai->comp_ship == 0 && Comp_board[compRow][compCol + 2] == '*')
		{
			Comp_board[compRow][compCol + 2] = 'P';
		}
		else if (Ai->comp_ship == 1 && Comp_board[compRow][compCol + 2] == '*' && Comp_board[compRow][compCol + 4] == '*')
		{
			Comp_board[compRow][compCol + 2] = 'S';
			Comp_board[compRow][compCol + 4] = 'S';
		}
		else if (Ai->comp_ship == 2 && Comp_board[compRow][compCol + 2] == '*' && Comp_board[compRow][compCol + 4] == '*')
		{
			Comp_board[compRow][compCol + 2] = 'C';
			Comp_board[compRow][compCol + 4] = 'C';
		}
		else if (Ai->comp_ship == 3 && Comp_board[compRow][compCol + 2] == '*' && Comp_board[compRow][compCol + 4] == '*' && Comp_board[compRow][compCol + 6] == '*')
		{
			Comp_board[compRow][compCol + 2] = 'A';
			Comp_board[compRow][compCol + 4] = 'A';
			Comp_board[compRow][compCol + 6] = 'A';
		}
		else if (Ai->comp_ship == 4 && Comp_board[compRow][compCol + 2] == '*' && Comp_board[compRow][compCol + 4] == '*' && Comp_board[compRow][compCol + 6] == '*' && Comp_board[compRow][compCol + 8] == '*')
		{
			Comp_board[compRow][compCol = 2] = 'B';
			Comp_board[compRow][compCol + 4] = 'B';
			Comp_board[compRow][compCol + 6] = 'B';
			Comp_board[compRow][compCol + 8] = 'B';
		}
		else
		{
			Comp_board[compRow][compCol] = '*';
			Ai->valid_comp_ship_pos = false;
		}
	}
	else if (Ai->comp_hv == 2)
	{
		if (Ai->comp_ship == 0 && Comp_board[compRow + 1][compCol] == '*')
		{
			Comp_board[compRow + 1][compCol] = 'P';
		}
		else if (Ai->comp_ship == 1 && Comp_board[compRow + 1][compCol] == '*' && Comp_board[compRow + 3][compCol] == '*')
		{
			Comp_board[compRow + 1][compCol] = 'S';
			Comp_board[compRow + 3][compCol] = 'S';
		}
		else if (Ai->comp_ship == 2 && Comp_board[compRow + 1][compCol] == '*' && Comp_board[compRow + 3][compCol] == '*')
		{
			Comp_board[compRow + 1][compCol] = 'C';
			Comp_board[compRow + 3][compCol] = 'C';
		}
		else if (Ai->comp_ship == 3 && Comp_board[compRow + 1][compCol] == '*' && Comp_board[compRow + 3][compCol] == '*' && Comp_board[compRow + 5][compCol] == '*')
		{
			Comp_board[compRow + 1][compCol] = 'A';
			Comp_board[compRow + 3][compCol] = 'A';
			Comp_board[compRow + 5][compCol] = 'A';

		}
		else if (Ai->comp_ship == 4 && Comp_board[compRow + 1][compCol] == '*' && Comp_board[compRow + 3][compCol] == '*' && Comp_board[compRow + 5][compCol] == '*' && Comp_board[compRow + 7][compCol] == '*')
		{
			Comp_board[compRow + 1][compCol] = 'B';
			Comp_board[compRow + 3][compCol] = 'B';
			Comp_board[compRow + 5][compCol] = 'B';
			Comp_board[compRow + 7][compCol] = 'B';

		}
		else {
			Comp_board[compRow][compCol] = '*';
			Ai->valid_comp_ship_pos = false;
		}
	}
	system("CLS");
}
void Board::PlayerAttack()
{
	scoreboard->GetScore();
	do
	{
		player->validAtkCord = true;
		PrintBoards();
		std::cout << std::setw(76) << "Enter Attack Coordinates: ";
		std::cin.getline(player->playerAtkCords, 11, '\n');

		CheckPlayerAttack();
		if (PieceOnBoard_Comp == 0)
		{
			for (int i = 0; i < 6; i++)
			{
				system("CLS");
				for (int i = 0; i < 19; i++)
				{
					std::cout << std::endl;
				}
				Sleep(500);
				std::cout << std::setw(60) << name << " ,You Won!!!" << std::endl;
				Sleep(500);
			}
		}
		else if (player->validAtkCord == true)
		{
			Sleep(3000);
			PrintBoards();
			AIAttack();
		}
	} while (!player->validAtkCord || Ai->comp_ship > 0);
}
void Board::CheckPlayerAttack()
{
	if (player->playerAtkCords[0] < 'a' || player->playerAtkCords[0] > 'j' || player->playerAtkCords[1] < '0' || player->playerAtkCords[1] > '9')
	{
		player->validAtkCord = false;
		system("CLS");
		PrintBoards();
		std::cout << std::setw(91) << "Sorry. It Seams Like You Have Entered Invalid Coordinates." << std::endl;
		std::cout << std::setw(98) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. E.g = a3" << std::endl;
		Sleep(3000);
	}
	else
	{
		RowColAtkVals();
		PlayerAttackSet();
	}
}
void Board::PlayerAttackSet()
{
	if (player_atk_radar[atkRow][atkCol] == '!' || player_atk_radar[atkRow][atkCol] == '$')
	{
		PrintBoards();
		std::cout << std::setw(82) << "You Have Already Attacked That Position.";
		Sleep(3000);
		player->validAtkCord = false;
	}
	else if (Comp_board[atkRow][atkCol] == 'P')
	{
		PrintBoards();
		std::cout << std::setw(84) << "You Hit Their Patrol Boat.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiPBhealth--;
		PieceOnBoard_Comp--;
	}
	else if (Comp_board[atkRow][atkCol] == 'S')
	{
		PrintBoards();
		std::cout << std::setw(84) << "You Hit Their Submarine.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiSubHealth--;
		PieceOnBoard_Comp--;
	}
	else if (Comp_board[atkRow][atkCol] == 'C')
	{
		PrintBoards();
		std::cout << std::setw(84) << "You Hit Their Cruiser.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiCrusHealth--;
		PieceOnBoard_Comp--;
	}
	else if (Comp_board[atkRow][atkCol] == 'A')
	{
		PrintBoards();
		std::cout << std::setw(84) << "You Hit Their Aircraft Carrier.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiACHealth--;
		PieceOnBoard_Comp--;
	}
	else if (Comp_board[atkRow][atkCol] == 'B')
	{
		PrintBoards();
		std::cout << std::setw(84) << " You Hit Their Battleship";
		player_atk_radar[atkRow][atkCol] = '!';
		aiBSHealth--;
		PieceOnBoard_Comp--;
	}
	else
	{
		PrintBoards();
		std::cout << std::setw(71) << "Nope. You Missed." << std::endl << std::endl;
		player_atk_radar[atkRow][atkCol] = '$';
	}
}
void Board::AiAttackOnBoard()
{
	itr = pieces.begin();
	itr2 = aiPieces.begin();
	Piece* p = *itr;
	scoreboard->GetScore();

	AICordsToAlpha();
	if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'P')
	{
		for (itr; itr != pieces.end(); itr++) {
			if(p->name == "PatrolBoat")
			{
				std::cout << std::setw(82) << "The Computer Has Hit Your Patrol Boat: " << Ai->aplha_comp_atk << (Ai->comp_atk_col / 2) << std::endl << std::endl;

				p->hit = true;
				player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '!';
				PieceOnBoard_Player--;
				p->health--;
			}
		}
	}
	else if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'S')
	{
		for (itr; itr != pieces.end(); itr++) {
			if (p->name == "Submarine")
			{
				std::cout << std::setw(81) << "The Computer Has Hit Your Submarine: " << Ai->aplha_comp_atk << (Ai->comp_atk_col / 2) << std::endl << std::endl;
				p->hit = true;
				player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '!';
				PieceOnBoard_Player--;
				p->health--;
			}
		}
	}
	else if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'C')
	{
		for (itr; itr != pieces.end(); itr++) {
			if (p->name == "Cruiser")
			{
				std::cout << std::setw(81) << "The Computer Has Hit Your Cruiser: " << Ai->aplha_comp_atk << (Ai->comp_atk_col / 2) << std::endl << std::endl;
				p->hit = true;
				player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '!';
				PieceOnBoard_Player--;
				p->health--;
			}
		}
	}
	else if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'A')
	{
		for (itr; itr != pieces.end(); itr++) {
			if (p->name == "AircraftCarrier")
			{
				std::cout << std::setw(81) << "The Computer Has Hit Your Aircraft Carrier: " << Ai->aplha_comp_atk << (Ai->comp_atk_col / 2) << std::endl << std::endl;
				p->hit = true;
				player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '!';
				PieceOnBoard_Player--;
				p->health--;
			}
		}
	}
	else if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'B')
	{
		for (itr; itr != pieces.end(); itr++) {
			if (p->name == "AircraftCarrier")
			{

				std::cout << std::setw(81) << "The Computer Has Hit Your Battleship: " << Ai->aplha_comp_atk << (Ai->comp_atk_col / 2) << std::endl << std::endl;
				p->hit = true;
				player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '!';
				PieceOnBoard_Player--;
				p->health--;
			}
		}
	}
	else if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == '*')
	{
		std::cout << std::setw(73) << "The Computer Missed: " << Ai->aplha_comp_atk << (Ai->comp_atk_row / 2) << std::endl << std::endl;
		player_board[Ai->comp_atk_row][Ai->comp_atk_col] = '$';
	}
	else
	{
		Ai->valid_comp_atk_cord = false;
	}

	ClearHits();

	if (PieceOnBoard_Player == 0)
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
	else if (Ai->valid_comp_atk_cord == true)
	{
		Sleep(3000);
		PlayerAttack();
	}

}
void Board::AIAttack()
{
	scoreboard->GetScore();


	itr = pieces.begin();
	itr2 = aiPieces.begin();
	Piece* p = *itr;
	do
	{
		// Sets valid_comp_atk_cord to true
		Ai->valid_comp_atk_cord = true;
		Ai->comp_atk_row = (rand() % 10) * 2;		// Generates a Random even number between 0-8
		Ai->comp_atk_col = ((rand() % 10) * 2) + 1;  // Generates a Random ODD number between 1-9
		for (itr; itr != pieces.end(); itr++)
		{

			// If the location targeted is P, S, C, A or B. The we know it hit a ship and can move to changing the board
			if (p->name == "PatrolBoat" && p->hit == true)
			{
				if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'P') { AiAttackOnBoard(); }
				else { Ai->valid_comp_atk_cord = false; }
			}
			else if (p->name == "Submarine" && p->hit == true)
			{
				if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'S') { AiAttackOnBoard(); }
				else { Ai->valid_comp_atk_cord = false; }
			}
			else if (p->name == "Cruiser" && p->hit == true)
			{
				if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'C') { AiAttackOnBoard(); }
				else { Ai->valid_comp_atk_cord = false; }
			}
			else if (p->name == "AircraftCarrier" && p->hit == true)
			{
				if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'A') { AiAttackOnBoard(); }
				else { Ai->valid_comp_atk_cord = false; }
			}
			else if (p->name == "Battleship" && p->hit == true)
			{
				if (player_board[Ai->comp_atk_row][Ai->comp_atk_col] == 'B') { AiAttackOnBoard(); }
				else { Ai->valid_comp_atk_cord = false; }
			}
			if ((p->name == "Battleship" && p->hit == false) && (p->name == "AircraftCarrier" && p->hit == false) && (p->name == "Cruiser" && p->hit == false) && (p->name == "Submarine" && p->hit == false) && (p->name == "PatrolBoat" && p->hit == false))
			{
				AiAttackOnBoard();
			}
		}
	} while (!Ai->valid_comp_atk_cord || PieceOnBoard_Player > 0);
}

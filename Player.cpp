#include "Player.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

Battleship* battleship = new Battleship();
AircraftCarrier* aircraftCarrier = new AircraftCarrier();
Cruiser* cruiser = new Cruiser();
Submarine* submarine = new Submarine();
PatrolBoat* patrolBoat = new PatrolBoat();

Player::Player()
{	
	
	validShipPos;
	validAtkCord;					// For checking if the location is a a Valid attack
	shipNumber = 0;					// Number of ships the player has left in the game

	// Attacking Variables
	playerShipCords[10];
	playerAtkCords[10];
	// Placing Pieces
	HoV[20];

	pieces.push_back(battleship);
	pieces.push_back(aircraftCarrier);
	pieces.push_back(cruiser);
	pieces.push_back(submarine);
	pieces.push_back(patrolBoat);

	itr = pieces.begin();
	PlayerPieceOnBoard = battleship->health + aircraftCarrier->health + cruiser->health + submarine->health + patrolBoat->health;

}

void Player::CheckCords()
{
	// function to check if the player entered in the correct information or not. should only let letter+number combo eg "A4. While 6A" or "2435234vkj", should come back with please enter valid input
	if (playerShipCords[0] < 'a' || playerShipCords[0] > 'j' || playerShipCords[1] < '0' || playerShipCords[1] > '9')
	{
		validShipPos = false;					// sets vaild position to false
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

void Player::PlayerPlaceShips()
{
	{
		do
		{
			// we will go through the 'list' of ships to place, 0-4 (5 ships total) and checks if the placement is okay, 'places' the ship on the board, increments ship_number by 1, then checks the next statement
			// we leave the loop if ship_number is 5 of greater
			validShipPos = true;
			if (shipNumber == 0)
			{
				std::cout << std::setw(109) << "Enter The Coordinate For Your Patrol Boat (2 spots): ";
			}
			else if (shipNumber == 1)
			{
				std::cout << std::setw(109) << "Enter The Coordinate For Your Submarine (3 spots): ";
			}
			else if (shipNumber == 2)
			{
				std::cout << std::setw(108) << "Enter The Coordinate For Your Crusier (4 spots): ";
			}
			else if (shipNumber == 3)
			{
				std::cout << std::setw(107) << "Enter The Coordinate For Your Aircraft Carrier (4 spots): ";
			}
			else if (shipNumber == 4)
			{
				std::cout << std::setw(100) << "Enter the Coordinate For Your Battleship (5 spots): ";
			}
			std::cin.getline(playerShipCords, 11, '\n');  // Ask for the players input in cords,
			std::cout << std::endl << std::endl;
			CheckCords();									// Check if its a valid placement
			system("CLS");

			if (validShipPos == true)
			{
				shipNumber++;								// If we did place a ship, we add to the ship number, so we dont end up placing more ships than we need (0-4)
			}
		} while (!validShipPos || shipNumber < 5); //do this while valid_ship_pos is false and the ship number is less than 5
	}
}

void Player::PlayerHoV()
{
	std::cout << std::setw(80) << playerShipCords[0] << playerShipCords[1] << std::endl << std::endl;
	std::cout << std::setw(118) << " Enter (h) to set ship Horizontally Or (v) To Set It Vertically: ";
	std::cin.getline(HoV, 20, '\n');

	Piece* p = *itr;
	itr = pieces.begin();
	// if we enter h, and ship_number is '0', Ptrl_boat character is used, S for sub, C for Cruiser ect
	if (HoV[0] == 'h')
	{
		if (shipNumber == 0 && player_board[row][col + 2] == '*')
		{
			player_board[row][col + 2] = 'P';  // Sets the ship at the position entered and will print to the right to fill the spaces the ship takes up
		}
		// if its ship_number 1 and the next 2 col spaces are free, prints out the 3 spaces for the Sub
		else if (shipNumber == 1 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'S';
			player_board[row][col + 4] = 'S';
		}
		// if its ship_number 1 and the next 3 col spaces are free, prints out the 4 spaces for the Cruiser
		else if (shipNumber == 2 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*')
		{
			player_board[row][col + 2] = 'C';
			player_board[row][col + 4] = 'C';
		}
		// I dont think I need to keep commenting these, We know what they do.
		else if (shipNumber == 3 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*')
		{
			player_board[row][col + 2] = 'A';
			player_board[row][col + 4] = 'A';
			player_board[row][col + 6] = 'A';
		}
		else if (shipNumber == 4 && player_board[row][col + 2] == '*' && player_board[row][col + 4] == '*' && player_board[row][col + 6] == '*' && player_board[row][col + 8] == '*')
		{
			player_board[row][col + 2] = 'B';
			player_board[row][col + 4] = 'B';
			player_board[row][col + 6] = 'B';
			player_board[row][col + 8] = 'B';
		}
		else

		{ // if any space is occupied Not enough space to place
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Horizontally." << std::endl << std::endl; //yell at player
			Sleep(3000);	//pause to make the game look fancy... it doesnt but whateve
			player_board[row][col] = '*'; // make sure the space is a * still
			validShipPos = false;				// set valid_ship_pos to false so we run through the loop again
		}

	}
	else if (HoV[0] == 'v')
	{
		// Same comments as the previous, this is just for the vert seting
		if (shipNumber == 0 && player_board[row + 2][col] == '*')
		{
			player_board[row + 2][col] = 'P';
		}
		else if (shipNumber == 1 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'S';
			player_board[row + 4][col] = 'S';
		}
		else if (shipNumber == 2 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*')
		{
			player_board[row + 2][col] = 'C';
			player_board[row + 4][col] = 'C';
		}
		else if (shipNumber == 3 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*')
		{
			player_board[row + 2][col] = 'A';
			player_board[row + 4][col] = 'A';
			player_board[row + 6][col] = 'A';
		}
		else if (shipNumber == 4 && player_board[row + 2][col] == '*' && player_board[row + 4][col] == '*' && player_board[row + 6][col] == '*' && player_board[row + 8][col] == '*')
		{
			player_board[row + 2][col] = 'B';
			player_board[row + 4][col] = 'B';
			player_board[row + 6][col] = 'B';
			player_board[row + 8][col] = 'B';
		}
		else
		{
			std::cout << std::setw(95) << "Sorry, Not Enough Space To Set It Vertically." << std::endl << std::endl;
			Sleep(3000);
			player_board[row][col] = '*';
			validShipPos = false;
		}
	}
	else
	{		// Tell the player they're dumb... I mean to put the right stuff in
		std::cout << std::setw(135) << "Please Enter The Letter 'h' To Set Your Boat Horizontally Or 'v' To Set It Vertically." << std::endl << std::endl;
		player_board[row][col] = '*';
		Sleep(5000);
		validShipPos = false;
	}


}

void Player::CheckValidCell()
{
	if (player_board[row][col] == '*')
	{
		if (shipNumber == 0)
		{
			player_board[row][col] = 'P';
		}
		else if (shipNumber == 1)
		{
			player_board[row][col] = 'S';
		}
		else if (shipNumber == 2)
		{
			player_board[row][col] = 'C';
		}
		else if (shipNumber == 3)
		{
			player_board[row][col] = 'A';
		}
		else if (shipNumber == 4)
		{
			player_board[row][col] = 'B';
		}
		PlayerHoV();
	}
	else
	{
		// reprint the board, tell the player they stupid and already did that.
		std::cout << std::setw(92) << "Sorry, It Seems Like That Spot Has Already Been Occupied." << std::endl << std::endl;
		Sleep(3000);
		validShipPos = false;
	}

}

void Player::PlayerAttack()
{
	do
	{
		validAtkCord = true;
		std::cout << std::setw(76) << "Enter Attack Coordinates: ";
		std::cin.getline(playerAtkCords, 11, '\n');

		CheckPlayerAttack();
		if (validAtkCord == true)
		{
			Sleep(3000);
		}
	} while (!validAtkCord || comp_ship > 0);
}

void Player::CheckPlayerAttack()
{
	if (playerAtkCords[0] < 'a' || playerAtkCords[0] > 'j' || playerAtkCords[1] < '0' || playerAtkCords[1] > '9')
	{
		validAtkCord = false;
		system("CLS");
		std::cout << std::setw(91) << "Sorry. It Seams Like You Have Entered Invalid Coordinates." << std::endl;
		std::cout << std::setw(98) << "Make Sure The Coordinate Is An Alphabet Followed By A Number. E.g = a3" << std::endl;
		Sleep(3000);
	}
	else
	{
		RowColAtkVals();
	}
	PlayerAttackSet();
}

void Player::RowColAtkVals()
{
	if (playerAtkCords[0] == 'a') { atkRow = 0; }
	else if (playerAtkCords[0] == 'b') { atkRow = 2; }
	else if (playerAtkCords[0] == 'c') { atkRow = 4; }
	else if (playerAtkCords[0] == 'd') { atkRow = 6; }
	else if (playerAtkCords[0] == 'e') { atkRow = 8; }
	else if (playerAtkCords[0] == 'f') { atkRow = 10; }
	else if (playerAtkCords[0] == 'g') { atkRow = 12; }
	else if (playerAtkCords[0] == 'h') { atkRow = 14; }
	else if (playerAtkCords[0] == 'i') { atkRow = 16; }
	else if (playerAtkCords[0] == 'j') { atkRow = 18; }
	// assigns the value the player entered for the second Coords input, for the second coord input.

	if (playerAtkCords[1] == '0') { atkCol = 3; }
	else if (playerAtkCords[1] == '1') { atkCol = 5; }
	else if (playerAtkCords[1] == '2') { atkCol = 7; }
	else if (playerAtkCords[1] == '3') { atkCol = 9; }
	else if (playerAtkCords[1] == '4') { atkCol = 11; }
	else if (playerAtkCords[1] == '5') { atkCol = 13; }
	else if (playerAtkCords[1] == '6') { atkCol = 15; }
	else if (playerAtkCords[1] == '7') { atkCol = 17; }
	else if (playerAtkCords[1] == '8') { atkCol = 19; }
	else if (playerAtkCords[1] == '9') { atkCol = 21; }
}

void Player::PlayerAttackSet()
{
	Piece *p = *itr;
	if (player_atk_radar[atkRow][atkCol] == '!' || player_atk_radar[atkRow][atkCol] == '$')
	{
		std::cout << std::setw(82) << "You Have Already Attacked That Position.";
		Sleep(3000);
		validAtkCord = false;
	}
	else if (Comp_board[atkRow][atkCol] == 'P')
	{
		std::cout << std::setw(84) << "You Hit Their Patrol Boat.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiPBhealth--;
		for (itr; itr != nullptr; itr++)
		{
			if (p->ID == 1)
			{
				p->health -= 1;
			}
		}
	}
	else if (Comp_board[atkRow][atkCol] == 'S')
	{
		std::cout << std::setw(84) << "You Hit Their Submarine.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiSubHealth--;
		for (itr; itr != nullptr; itr++)
		{
			if (p->ID == 1)
			{
				p->health -= 1;
			}
		}

	}
	else if (Comp_board[atkRow][atkCol] == 'C')
	{
		std::cout << std::setw(84) << "You Hit Their Cruiser.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiCrusHealth--;
		for (itr; itr != nullptr; itr++)
		{
			if (p->ID == 1)
			{
				p->health -= 1;
			}
		}

	}
	else if (Comp_board[atkRow][atkCol] == 'A')
	{
		std::cout << std::setw(84) << "You Hit Their Aircraft Carrier.";
		player_atk_radar[atkRow][atkCol] = '!';
		aiACHealth--;
		for (itr; itr != nullptr; itr++)
		{
			if (p->ID == 1)
			{
				p->health -= 1;
			}
		}

	}
	else if (Comp_board[atkRow][atkCol] == 'B')
	{
		std::cout << std::setw(84) << " You Hit Their Battleship";
		player_atk_radar[atkRow][atkCol] = '!';
		aiBSHealth--;
		for (itr; itr != nullptr; itr++)
		{
			if (p->ID == 1)
			{
				p->health -= 1;
			}
		}

	}
	else
	{
		std::cout << std::setw(71) << "Nope. You Missed." << std::endl << std::endl;
		player_atk_radar[atkRow][atkCol] = '$';
	}
}

void Player::RowColVals()
{
	if (playerShipCords[0] == 'a') { row = 0; }				// If the player enters 'a' as the first coords, the computer will know its actually position 0 in the array, repeat for each
	else if (playerShipCords[0] == 'b') { row = 2; }			// rows are 
	else if (playerShipCords[0] == 'c') { row = 4; }
	else if (playerShipCords[0] == 'd') { row = 6; }
	else if (playerShipCords[0] == 'e') { row = 8; }
	else if (playerShipCords[0] == 'f') { row = 10; }
	else if (playerShipCords[0] == 'g') { row = 12; }
	else if (playerShipCords[0] == 'h') { row = 14; }
	else if (playerShipCords[0] == 'i') { row = 16; }
	else if (playerShipCords[0] == 'j') { row = 18; }

	// Sets the rows to the proper values 
	if (playerShipCords[1] == '0') { col = 3; }
	else if (playerShipCords[1] == '1') { col = 5; }
	else if (playerShipCords[1] == '2') { col = 7; }
	else if (playerShipCords[1] == '3') { col = 9; }
	else if (playerShipCords[1] == '4') { col = 11; }
	else if (playerShipCords[1] == '5') { col = 13; }
	else if (playerShipCords[1] == '6') { col = 15; }
	else if (playerShipCords[1] == '7') { col = 17; }
	else if (playerShipCords[1] == '8') { col = 19; }
	else if (playerShipCords[1] == '9') { col = 21; }
}


void Player::ClearHits()
{
	for (itr; itr != pieces.end(); itr++)
	{
		Piece* p = *itr;
		p->health = 0;
		p->hit = false;
	}
}

void Player::EnterName()
{
	for (int i = 0; i < 15; i++)
	{
		std::cout << std::endl;
	}
	std::cout << std::setw(70) << "Enter Name: ";
	getline(std::cin, name);

}

void Player::ResetBoard()
{
}

Player::~Player()
{
}

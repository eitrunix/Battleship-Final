#include "TitleSceen.h"
#include "Board.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

Board* b;

void TitleScreen::BuildTitle() 
{
	Options[options_row][options_col];
	game_title[title_row][title_col];
	// Fancy fancy art.
}
TitleScreen::TitleScreen()
{
	b = new Board();
}
TitleScreen::~TitleScreen()
{
}
void TitleScreen::print_game_title()
{
	std::cout << std::endl; std::cout << std::endl;
	for (int i = 0; i < title_row; i++)
	{

		std::cout << std::setw(45);   // setw() sets where the title will start to draw
		for (int j = 0; j < title_col; j++)
		{
			if (game_title[i][j] == '#')   // Changes all the # in the array to be an ASCII character					
			{
				std::cout << (char)219;
			}
			else
			{
				std::cout << (char)32;  // If its not a hashtag, change it to a "space"
			}
		}
		std::cout << std::endl;
	}
}

void TitleScreen::print_options()
{
	for (int i = 0; i < options_row; i++) 
	{
		std::cout << std::setw(56);
		for (int j = 0; j < options_col; j++) 
		{
			if (i == arrow_row && j == arrow_col) 
			{
				std::cout << (char)175;
			}
			std::cout << Options[i][j];
		}
		std::cout << std::endl;
	}
}

void TitleScreen::player_choose_options()
{
	while (1) {
		if (_kbhit()) {  //_kbhit() just checks if there is something in the input buffer. it does not do anything else. Used in my "menu" to have the player move the arrow up and down
			options_move = _getch();
			if (arrow_row == 0 && arrow_col == 0 && options_move == 13)			// first option, plays the game, starts by asking the player name, computer places ships on the board, then prompts the player to place ships,
																				// then will tell the player to get ready to play (tell_player_shits_about_to_get_real function) and print the boards, then asks for the attack cords.
			{
				PlayGame();
			}
			else if (arrow_row == 2 && arrow_col == 0 && options_move == 13)
			{
				system("CLS");
				// Instructions go here, this is the Second (thrid in code) option
				if (options_move == -32) {
					system("CLS");
				}
			}
			else if (arrow_row == 3 && arrow_col == 0 && options_move == 13)
			{
				// should quit the program, but cant get it working with exit()
				system("CLS");
				for (int i = 0; i < 18; i++)
				{
					std::cout << std::endl;
				}std::cout << std::setw(58);
				for (int i = 1; i <= 6; i++)
				{
					std::cout << (char)i << " ";
				}
				for (int i = 0; i < 18; i++)
				{
					std::cout << std::endl;
				}
				//Sleep(5000);
				exit(0);
			}
			else if (options_move == 27) {
				system("CLS");
				print_game_title();
				print_options();
			}
			else if (options_move == -32) {
				upordown = _getch();
				switch (upordown) {
				case 72:
					if (arrow_row > 0) {
						arrow_row--;
					}
					break;
				case 80:
					if (arrow_row < options_row - 1) {
						arrow_row++;
					}
					break;
				}
				system("CLS");
				print_game_title();
				print_options();
			}
		}
	}
}
// Used to get players Name, the loop is used for spacing to try to get the text in the "center" of the screen


void TitleScreen::PlayGame()
{
	system("CLS");
	b->EnterName();
	b->DisplayScoreboard();
	b->FakeLoadingScreeen();
	b->take_comp_input();
	b->PrintBoards();
	b->PlayerPlaceShips();		
	b->FakeLoadingScreeen();
	b->PlayerSetAttack();
}

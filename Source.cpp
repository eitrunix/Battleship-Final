#include "Battleships.h"
#include "Board.h"
#include "TitleSceen.h"
#include "Player.h"
#include "AI.h"


TitleScreen t;
Board b;
int main()
{
	t.print_game_title();
	t.print_options();
	t.player_choose_options();
	
}


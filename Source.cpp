#include "TitleSceen.h"

GameStateManager* game = new GameStateManager(1, true);

TitleScreen* title = new TitleScreen(game);

int main()
{
	title->BuildTitle();
}


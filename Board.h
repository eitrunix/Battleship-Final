#include <string>
#include "Piece.h"
#include "LinkList.h"

#ifndef BOARD__H
#define BOARD__H

class Board 
{
public:
	Board();
	~Board();

	void PrintBoards(Player *player);
	void ClearBoard(Player* player);
	void FakeLoadingScreeen();
	// Board Variables



};

#endif
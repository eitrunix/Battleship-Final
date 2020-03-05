#pragma once
#ifndef AI__H
#define AI__H
#include "Piece.h"
#include "Player.h"
#include "LinkList.h"
using namespace DataStructuresAndAI;
class AI
{
public:
	AI(Player Player);
	~AI();
	Player* player;
	int comp_atk_row, comp_atk_col;

	bool valid_comp_ship_pos;	// same as above but for computer
	bool valid_comp_atk_cord;	// same but for computer
	//AI Attacking
	int comp_hv;				// computer ships hoz or vert
	LinkList<Piece*> Aipieces;
	LinkList<Piece*>::Iterator Aiitr;
	void ClearHits();

	void AIAttack();
	void CheckValidMoveAI();
	void AICordsToAlpha();
	void AISetShips();
	void AIHoV();
	void AiAttackOnBoard();


	int compRow, compCol;

	char aplha_comp_atk;		// to check the first part of the computers "firing" cords, used to change the number we generate to a letter...its not working wtf???
private:
};

#endif // !AI__H

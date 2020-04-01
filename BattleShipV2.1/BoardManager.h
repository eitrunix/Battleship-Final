#pragma once
#ifndef __BOARDMANAGER_H 
#define __BOARDMANAGER_H
#include "Piece.h"
using namespace SDLFramework;

class BoardManager
{
private:
	static BoardManager* bmInstance;
	BoardManager* mBoardManager;

public:
	BoardManager();
	~BoardManager();


	static BoardManager* Instance();

	void Update();
	void LateUpdate();
	void Render();
	static void Release();

	int playerRadarRow;
	int playerRadarCol;
	int compRow;
	int compCol;

};

class Board
{
private:

public:
	Board();
	~Board();

	static void Release();
	int Row;
	int Col;
	Texture* boardTex;
};


#endif __BOARDMANAGER_H
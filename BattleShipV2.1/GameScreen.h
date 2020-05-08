#pragma once
#ifndef __GAMESCREEN_H 
#define __GAMESCREEN_H
#include "AnimatedTexture.h" 
#include "InputManager.h"
#include "ScoreBoard.h"
#include "Board.h"
using namespace SDLFramework;

class GameScreen : public GameEntity
{
private:
	enum class BoardState
	{
		Title,
		PlaceShips,
		MakeAttack,
		AIAttack,
		AIPlaceShips,
		GameOver,
	};

	Timer* mTimer;
	InputManager* mInputManager;
	BattleshipBoard* pBoard;
	BattleshipBoard* pRadar;
	PlayerManager* mPlayerManager;
	// Screen Entities 
	ScoreBoard* mScoreBoard;
	GameEntity* mPlayerOneArea;
	GameEntity* mPlayerTwoArea;

	// Images Boards Background
	Texture* Board;
	Texture* Radar;
	
	// Input Area
	GameEntity* mInputArea;
	Texture* defaultText;
	Texture* invalidAttack;
	Texture* invalidPlacement;
	Texture* Vertical;
	Texture* Horizontal;
	Texture* blankText;

	//Board Icons
	Texture* boat1;

	// Plaing Ships Vairables
	bool allShipsPlaced = false;
	bool aiShipsPlaced = false;
	int playerShips = 0;
	int aiShips = 0;
	bool horizontal = false;

	// Attacking Variables
	bool validAttack = false;
	bool validPlace;
	bool aiDone;
	// AI Variables

public:
	GameScreen();
	~GameScreen();

	bool active;

	int playerHealth = 0;
	int aiHealth = 0;
	void Update() override;
	void Render() override;
	void ChangeBoardState(BoardState newState);
	void PlayerPlaceShips();
	void PlayerAttack();
	void AIPlaceShips();
	void AIAttack();
	void MousePos(int offset);
	void CheckWinCon();

	bool sGameOver = false;
	bool playerWin;
	bool aiWin;
	BoardState bState;

	LinkList<Piece*>::Iterator Itr;
	LinkList<Texture*>::Iterator TexItr;

	bool validCheck = false;

	// Mouse Grid Position Varables
	Vector2 mousePos;
	int mouseX;
	int mouseY;

	float boardSize = 10.0f;

	float pBoardXOffset = 91.5f;
	float pBoatdYOffset = 297.0f;

	float cBoardXOffset = 550.0f;
	float cBoatdYOffset = 297.0f;

	float boardXPosOffset = 40.0f;
	float boardYPosOffset = -230.0f;
	float radarYPosOffset = 230.0f;
	int xIndex;
	int yIndex;

	int gridWidth = 430, gridHeight = 430;
	int rows = 10, cols = 10;

	int pOffsetX = 690, pOffsetY = 2750, rOffsetX = 5280;
};

#endif // __GAMESCREEN_H
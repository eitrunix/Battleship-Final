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
	};

	Timer* mTimer;
	InputManager* mInputManager;
	BattleshipBoard* pBoard;
	BattleshipBoard* pRadar;

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

	//Board Icons
	Texture* boat1;
	bool validAttack = false;
	bool allShipsPlaced = false;
	int playerShips = 0;
public:
	GameScreen();
	~GameScreen();
	
	void Update() override;
	void Render() override;
	void ChangeBoardState(BoardState newState);
	void PlayerPlaceShips(int x, int y);
	void AIPlaceShips(int x, int y);
	void HorzorVert();
	void MousePos(int offset);
	bool sGameOver = false;
	BoardState bState;

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

	int pOffsetX = 690, pOffsetY = 2750;

	int rOffsetX = 5280;
};

#endif // __GAMESCREEN_H
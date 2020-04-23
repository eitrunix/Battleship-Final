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
	Timer* mTimer;
	InputManager* mInputManager;
	BattleshipBoard* pBoard;
	BattleshipBoard* pRadar;
	// Screen Entities 
	ScoreBoard* mScoreBoard;
	GameEntity* mPlayerOneArea;
	GameEntity* mPlayerTwoArea;
	//MouseControl* mMouse;
	// Images Boards Background
	Texture* Board;
	Texture* Radar;

public:
	GameScreen();
	~GameScreen();

	void Update() override;
	void Render() override;

	float boardSize = 10.0f;
	Vector2 mousePos;
	int mouseX;
	int mouseY;
};

#endif // __GAMESCREEN_H
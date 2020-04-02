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
	Board* PBoard;
	// Screen Entities 
	ScoreBoard* mScoreBoard;
	GameEntity* mPlayerOneArea;
	GameEntity* mPlayerTwoArea;
	
	// Images Boards Background
	Texture* Board;
	Texture* Radar;

public:
	GameScreen();
	~GameScreen();

	void Update() override;
	void Render() override;

};

#endif // __GAMESCREEN_H
#pragma once
#ifndef __STARTSCREEN_H 
#define __STARTSCREEN_H
#include "AnimatedTexture.h" 
#include "InputManager.h"
using namespace SDLFramework;

class StartScreen : public GameEntity 
{
private:    
	Timer* mTimer;    
	InputManager* mInputManager;
	// Title Area
	GameEntity* mTitleArea;
	GameEntity* mBoatsArea;
	GameEntity* mInstructsArea;

	Texture* tTitle;
	Texture* tStart;
	Texture* tInstructs;
	Texture* tQuit;

	Texture* tInstructions1;
	Texture* tInstructions2;
	Texture* tInstructions3;
	Texture* tInstructions4;
	Texture* tInstructions5;
	Texture* tInstructions6;

	Texture* aBoat1;
	Texture* aBoat2;
	Texture* aBoat3;
	Texture* aBoat4;
	Texture* aBoat5;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
	bool PlayGame = false;
	bool displayInstructions = false;

	std::string insText;
	int TITLE_TEXT_SIZE = 64;
	int TEXT_SIZE = 32;
	int INST_TEXT_SIZE = 24;
};

#endif // __STARTSCREEN_H 
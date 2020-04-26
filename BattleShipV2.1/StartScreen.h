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
	Texture* tTitle;
	Texture* tStart;
	Texture* tInstructs;
	Texture* tQuit;

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

};

#endif // __STARTSCREEN_H 
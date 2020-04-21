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
	Texture* tTitle;

public:
	StartScreen();
	~StartScreen();

	void Update() override;
	void Render() override;
	bool onScreen = false;

};

#endif // __STARTSCREEN_H 
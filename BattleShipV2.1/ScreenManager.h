#pragma once
#include "StartScreen.h"
#include "GameScreen.h"
#include "GameOverScreen.h"
using namespace SDLFramework;
#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

class ScreenManager 
{
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play, GameOver, CleanUp };
	//Screens mCurrentScreen;

	InputManager* mInput;
	GameScreen* mGameScreen;
	StartScreen* mStartScreen;
	GameOverScreen* mGameOverScreen;
public:

	static ScreenManager* Instance();
	static void Release();

	Screens mCurrentScreen = Start;

	void Update();
	void Render();
	void ChangeScreens(Screens screen);
private:
	ScreenManager();
	~ScreenManager();
};
#endif

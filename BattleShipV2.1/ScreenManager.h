#pragma once
#include "StartScreen.h"
#include "GameScreen.h"

using namespace SDLFramework;
#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

class ScreenManager 
{
private:
	static ScreenManager* sInstance;

	enum Screens { Start, Play };
	Screens mCurrentScreen;

	InputManager* mInput;

	//GameScreen* mGameScreen;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};
#endif

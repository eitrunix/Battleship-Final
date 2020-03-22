#include "SDLInputManager.h"
#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H


class ScreenManager
{

private:
	static ScreenManager* sInstance;
	enum Screens { MAIN, START, PLAY };
	Screens mCurrentScreen;
	//SDLInputManager* mInput;

public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();
	ScreenManager();
	~ScreenManager();

private:

};
#endif
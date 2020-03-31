#include "InputManager.h"

using namespace SDLFramework;
#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H

class ScreenManager {
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


class GameScreen : GameEntity
{
	Timer* mTimer;
	AudioManager* mAudio;

	Texture* mStartLabel;

	float mLevelStartTimer;
	float mLevelStartDelay;

	bool mGameStarted;

	bool mLevelStarted;
	int mCurrentStage;

	//Player* mPlayer;

	void StartNextLevel();

public:
	GameScreen();
	~GameScreen();

	void StartNewGame();

	bool GameOver();

	void Update();
	void Render();
};
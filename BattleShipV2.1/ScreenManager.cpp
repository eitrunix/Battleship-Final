#include "ScreenManager.h"
ScreenManager* ScreenManager::sInstance = nullptr;
ScreenManager* ScreenManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new ScreenManager();
	}
	return sInstance;

}

ScreenManager::ScreenManager()
{
	mStartScreen = new StartScreen();
	mGameScreen = new GameScreen();
	mGameOverScreen = new GameOverScreen();
	mInput = InputManager::Instance();
}

ScreenManager::~ScreenManager()
{
	delete mGameScreen;
	mGameScreen = nullptr;
	delete mGameOverScreen;
	mGameOverScreen = nullptr;
	delete mStartScreen;
	mStartScreen = nullptr;

}

void ScreenManager::Release()
{
	

}

void ScreenManager::Update()
{
	switch (mCurrentScreen)
	{
	case Start:
		if (mStartScreen->PlayGame == true)
		{
			mCurrentScreen = Play;
			mGameScreen->active = true;
			mGameScreen->sGameOver = false;
			mGameOverScreen->sTitle = false;
		}
		break;
	case Play:
		if (mGameScreen->sGameOver == true)
		{
			mCurrentScreen = GameOver;
			mStartScreen->PlayGame = false;
			mGameOverScreen->sTitle = false;

			if (mGameScreen->playerWin)
			{
				mGameOverScreen->playerWin = true;
			}
			else if (mGameScreen->aiWin)
			{
				mGameOverScreen->aiWin = true;
			}
			else
			{
				mGameOverScreen->howThisHappen = true;
			}
		}
		break;
	case GameOver:
		if (mGameOverScreen->sTitle == true)
		{
			mCurrentScreen = CleanUp;
			mGameScreen->sGameOver = false;
			mGameScreen->active = false;
			mStartScreen->PlayGame = false;
		}
		break;

	case CleanUp:
		mCurrentScreen = Start;
		mGameScreen->aiWin = false;
		mGameScreen->playerWin = false;
		break;
	}

	switch (mCurrentScreen) 
	{
	case Start:
		mStartScreen->Update();
		break;
	case GameOver:
		mGameOverScreen->Update();
		break;		
	case Play:
		mGameScreen->Update();
		break;

	}

	if (mInput->KeyPressed(SDL_SCANCODE_P))
	{
		switch (mCurrentScreen)
		{
		case Start:
			mCurrentScreen = Play;
			break;
		case Play:
			mCurrentScreen = GameOver;
			break;
		case GameOver:
			mCurrentScreen = Start;
			break;
		}

	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen)
	{
	case Start:
		mStartScreen->Render();
		break;
	case Play:
		mGameScreen->Render();
		break;
	case GameOver:
		mGameOverScreen->Render();
	}
}


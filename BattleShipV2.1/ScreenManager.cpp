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

}

ScreenManager::~ScreenManager()
{
	delete mGameScreen;
	mGameScreen = nullptr;
	delete mStartScreen;
	mStartScreen = nullptr;

}

void ScreenManager::Release()
{
	

}

void ScreenManager::Update()
{
	if (mStartScreen->onScreen == false)
	{
		mCurrentScreen = Play;
	}
	switch (mCurrentScreen) 
	{
	case Start:
		mStartScreen->Update();
		break;
	case Play:
		mGameScreen->Update();
		break;

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

	}
}

void ScreenManager::ChangeScreens(Screens screen)
{
	mCurrentScreen = screen;
}


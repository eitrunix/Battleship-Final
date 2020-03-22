#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager::ScreenManager()
{
	mCurrentScreen = START;
}

ScreenManager::~ScreenManager()
{
	/*mInput = nullptr;*/
}

ScreenManager* ScreenManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new ScreenManager();
	}
	return sInstance;
}

void ScreenManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

void ScreenManager::Update()
{
	switch (mCurrentScreen)
	{
	case START:
		break;
	case PLAY:
		break;
	case MAIN:
		break;
	}
}

void ScreenManager::Render()
{
	switch (mCurrentScreen)
	{
	case START:
	case PLAY:
		break;
	case MAIN:
		break;
	}
}


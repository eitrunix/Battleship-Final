#include "Timer.h"
namespace SDLFramework
{
	Timer* Timer::sInstance = nullptr;

	Timer::Timer()
	{
		Reset();
		mTimeScale = 1.0f;
	}

	Timer::~Timer()
	{

	}

	void Timer::SetInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Timer();
		}
	}

	Timer* Timer::GetInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new Timer();
		}
		return sInstance;
	}

	void Timer::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	void Timer::Reset()
	{
		mStartTicks = SDL_GetTicks();
		mElapsedTicks = 0;
		mDeltaTime = 0.0f;
	}

	float Timer::GetDeltaTime()
	{
		return mDeltaTime;
	}

	void Timer::SetTimeScale(float ts)
	{
		mTimeScale = ts;
	}

	float Timer::GetTimeScale()
	{
		return mTimeScale;
	}

	void Timer::Update()
	{
		mElapsedTicks = SDL_GetTicks() - mStartTicks;
		mDeltaTime = mElapsedTicks * 0.001f; // convert to seconds
	}
}
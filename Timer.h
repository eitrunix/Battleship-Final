#ifndef __TIMER_H
#define __TIMER_H
#include <SDL.h>

namespace SDLFramework
{
	class Timer
	{
		// ************* Attributes ************* //
	private:
		static Timer* sInstance;
		unsigned int mStartTicks;
		unsigned int mElapsedTicks;
		float mDeltaTime;
		float mTimeScale;

	public:


		// ************* Functions ************* //
	private:

	public:
		Timer();
		~Timer();

		static void SetInstance();
		static Timer* GetInstance();
		float GetDeltaTime();
		void SetTimeScale(float ts);
		float GetTimeScale();

		static void Release();
		void Reset();
		void Update();


		// ************* Protected ************* //
	protected:


	};
}
#endif
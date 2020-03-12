#ifndef __ANIMATEDTEXTURE_H
#define __ANIMATEDTEXTURE_H
#include "Texture.h"
#include "Timer.h"
#include <string>

namespace SDLFramework
{
	class AnimatedTexture : public Texture
	{

		// ************* Attributes ************* //
	public:
		enum WrapMode { Once = 0, Loop = 1 };
		enum AnimDir { Horizontal = 0, Vertical = 1 };
		AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed = false);
		~AnimatedTexture();

		void Update();

	private:

		Timer* mTimer;
		int mStartX;
		int mStartY;

		int mFrameCount; // total frames
		float mAnimationSpeed; // in seconds
		float mTimePerFrame; // time to display
		float mAnimationTimer; // time displayed

		WrapMode mWrapMode;
		AnimDir mAnimationDirection;
		bool mAnimationDone;

		// ************* Functions ************* //
	private:
		void SetWrapMode(WrapMode mode);
		void ResetAnimation();
		bool IsAnimating();

	public:

		// ************* Protected ************* //
	protected:

	};
}
#endif

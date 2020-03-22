#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>
#include "AnimatedTexture.h"
#include "Timer.h"
#include "SDLInputManager.h"
#include "AudioManager.h"
#include "ScreenManager.h"
#include "GameStateManager.h"
#include "HealthManager.h"
#include "PlayableManager.h"
#include "BoardManager.h"

namespace SDLFramework
{
	class GameManager
	{

	public:
		GameManager();
		~GameManager();
		static GameManager* Instance();
		static void Release();

		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		// singleton
		static GameManager* sInstance;
		// loop control
		bool mQuit;
		// modules
		GraphicsManager* mGraphics;
		GameStateManager* s_Instance;
		HealthManager* 
		SDL_Event mEvent;
		// timer variables
		const int FRAME_RATE = 60;
		Timer* mTimer;

		// Asset/textures
		AssetManager* mAssetManager;
		SDLInputManager* mInputManager;
		AudioManager* mAudioManager;

		AnimatedTexture* mTex;
		Texture* mTexTwo;
		Texture* mFontTexture;

		const float scaleIncrement = 2.0f;
		void PlayerOneInputUpdate();
		void PlayerTwoInputUpdate();

		ScreenManager* mScreenManager;
	};
}

#endif
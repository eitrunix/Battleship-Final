#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>
//#include "AnimatedTexture.h"
#include "Timer.h"
#include "InputManager.h"
#include "AudioManager.h" 
#include "BoardManager.h"
#include "GameStateManager.h"

namespace SDLFramework {

	class GameManager
	{
	private:
		const int FRAME_RATE = 60;
		bool mQuit;
		static GameManager* sInstance;
		Texture* mFontTex;
		Graphics * mGraphics;
		AssetManager * mAssetManager;
		InputManager * mInputManager;
		AudioManager* mAudioManager;
		BoardManager* mBoardManager;
		GameStateManager* mGameStateManager;
		HealthManager* mHealthManager;
		PlayerManager* mPlayerManager;

		Timer * mTimer;
		SDL_Event mEvent;
		AnimatedTexture * mTex;

	public:
		static GameManager * Instance();
		static void Release();

		void Run();

		void Update();
		void LateUpdate();

		void Render();

		GameManager();
		~GameManager();
	};
}
#endif
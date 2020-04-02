#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>
//#include "AnimatedTexture.h"
//#include "ScreenManager.h"

#include "GameScreen.h"
#include "AudioManager.h" 

namespace SDLFramework {

	class GameManager
	{
	private:
		const int FRAME_RATE = 60;
		bool mQuit;
		static GameManager* sInstance;

		Graphics * mGraphics;
		AssetManager * mAssetManager;
		InputManager * mInputManager;
		AudioManager* mAudioManager;

		//ScreenManager* mScreenManager;

		Timer * mTimer;
		SDL_Event mEvent;

		GameScreen* mGameScreen;

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
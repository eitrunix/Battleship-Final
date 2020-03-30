#include "GameManager.h"

namespace SDLFramework {

	GameManager * GameManager::sInstance = nullptr;

	GameManager * GameManager::Instance()
	{
		if (sInstance == nullptr) 
		{
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() 
	{
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() 
	{
		while (!mQuit) 
		{
			mTimer->Update();

			while (SDL_PollEvent(&mEvent)) 
			{
				switch (mEvent.type) 
				{
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) 
			{
				Update();
				LateUpdate();
				Render();
				mTimer->Reset();
			}
		}
	}

	void GameManager::Update() 
	{

	}

	void GameManager::LateUpdate() 
	{
	}

	void GameManager::Render() 
	{
		mGraphics->ClearBackBuffer();
		mGraphics->Render();
	}

	GameManager::GameManager() : mQuit(false) 
	{
		mGraphics = Graphics::Instance();

		if (!Graphics::Initialized()) 
		{
			mQuit = true;
		}
		mAudioManager = AudioManager::Instance();
		mAssetManager = AssetManager::Instance();
		//////
		mGameStateManager = GameStateManager::Instance();
		mBoardManager = BoardManager::Instance();
		mPlayerManager = PlayerManager::Instance();
		mHealthManager = HealthManager::Instance();
		/////
		mTimer = Timer::Instance();

		 //Textures and stuff
		
		mFontTex = new Texture("Space Shooty Game", "ARCADE.TTF", 72, { 255, 0, 0 });
		mFontTex->Position(Vector2(400, 200));
	}

	GameManager::~GameManager() 
	{

		Timer::Release();
		mTimer = nullptr;

		AssetManager::Release();
		mAssetManager = nullptr;

		Graphics::Release();
		mGraphics = nullptr;

		AudioManager::Release();    
		mAudioManager = nullptr;

		GameStateManager::Release();
		mGameStateManager = nullptr;

		BoardManager::Release();
		mBoardManager = nullptr;

		PlayerManager::Release();
		mPlayerManager = nullptr;

		HealthManager::Release();
		mHealthManager = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}
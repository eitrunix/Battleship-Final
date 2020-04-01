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
		mInputManager->Update();
		//mScreenManager->Update();
		mGameScreen->Update();
	}

	void GameManager::LateUpdate() 
	{
		mInputManager->UpdatePrevInput(); 
	}

	void GameManager::Render() 
	{
		mGraphics->ClearBackBuffer();
		//mScreenManager->Render();
		mGameScreen->Render();
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
		mInputManager = InputManager::Instance();
		mAssetManager = AssetManager::Instance();
		//////
		mGameStateManager = GameStateManager::Instance();
		mBoardManager = BoardManager::Instance();
		mPlayerManager = PlayerManager::Instance();
		mHealthManager = HealthManager::Instance();
		/////
		mTimer = Timer::Instance();
		//mScreenManager = ScreenManager::Instance();

		//Textures, Screens, Audio ect
		mGameScreen = new GameScreen();
	}

	GameManager::~GameManager() 
	{
		//ScreenManager::Release();
		//mScreenManager = nullptr;
		delete mGameScreen;
		mGameScreen = nullptr;


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
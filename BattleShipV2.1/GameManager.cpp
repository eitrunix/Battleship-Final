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

		mBoardManager->waterTileTex = new AnimatedTexture("Water.png", 0, 0, 0, 0, 0, 0, AnimatedTexture::Horizontal);
		mBoardManager->hitTileTex = new AnimatedTexture("Water.png", 0, 0, 0, 0, 0, 0, AnimatedTexture::Horizontal);
		mBoardManager->missTileTex = new AnimatedTexture("Water.png", 0, 0, 0, 0, 0, 0, AnimatedTexture::Horizontal);

		 //Textures and stuff
	}
	void GameManager::UpdateTile(Board board[10][10])
	{
		int tempRow = sizeof board / sizeof board[0];
		int tempCol = sizeof board[0] / sizeof board[0][0];

		for (int row = 0; row < tempRow; row++)
		{
			for (int col = 0; col < tempCol; col++)
			{
				if (board[row][col].type == TileType::Water)
				{
					board[row][col].TileTex = mBoardManager->waterTileTex;
				}
				if (board[row][col].type == TileType::Hit)
				{
					board[row][col].TileTex = mBoardManager->hitTileTex;
				}
				if (board[row][col].type == TileType::Miss)
				{
					board[row][col].TileTex = mBoardManager->missTileTex;
				}
			}
		}
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
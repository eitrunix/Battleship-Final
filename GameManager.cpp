#include "GameManager.h"

namespace SDLFramework
{
	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance()
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
		// main game loop
		while (!mQuit)
		{
			mTimer->Update();
			// event processing loop
			while (SDL_PollEvent(&mEvent))
			{
				switch (mEvent.type)
				{
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}
			if (mTimer->GetDeltaTime() >= 1.0f / FRAME_RATE)
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
		mScreenManager->Update();

		PlayerOneInputUpdate();
		PlayerTwoInputUpdate();

		mTex->Update();

		if (mInputManager->KeyDown(SDL_SCANCODE_1))
		{
			mAudioManager->PlaySFX("SFX/59873__uzerx__lazer.wav", 0, -1);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_2))
		{
			mAudioManager->PlaySFX("SFX/243020__plasterbrain__game-start.wav", 0, 0);
		}

		// Anything after this comment is just printing shit
		if (mInputManager->KeyPressed(SDL_SCANCODE_SPACE))
		{
			std::cout << "Space pressed!" << std::endl;
		}
		if (mInputManager->KeyReleased(SDL_SCANCODE_SPACE))
		{
			std::cout << "Space released!" << std::endl;
		}
		if (mInputManager->MouseButtonPressed(SDLInputManager::Left))
		{
			std::cout << "Left mouse button pressed!" << std::endl;
		}
		if (mInputManager->MouseButtonReleased(SDLInputManager::Left))
		{
			std::cout << "Left mouse button released!" << std::endl;
		}
	}

	void GameManager::LateUpdate()
	{
		mInputManager->UpdatePrevInput();
	}

	void GameManager::Render()
	{
		mGraphics->ClearBackBuffer();
		mScreenManager->Render();
		mTex->Render();
		mTexTwo->Render();
		mGraphics->Render();
	}

	void GameManager::PlayerOneInputUpdate()
	{
		if (mInputManager->KeyDown(SDL_SCANCODE_W)) //Forward and Back
		{
			mTex->Translate(Vector2(0, -80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_S))
		{
			mTex->Translate(Vector2(0, 80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_A)) //Left and Right
		{
			mTex->Translate(Vector2(-80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_D))
		{
			mTex->Translate(Vector2(80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_Q)) //Rotate Left and Right
		{
			mTex->Rotate((-25) * mTimer->GetDeltaTime());
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_E))
		{
			mTex->Rotate((25) * mTimer->GetDeltaTime());
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_Z)) //Scale Up and Down
		{
			Vector2 tempScale = mTex->Scale();
			tempScale += Vector2(0.1f, 0.1f);
			mTex->Scale(tempScale);
			mTex->Translate(Vector2(-120.0f, -120.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_C))
		{
			Vector2 tempScale = mTex->Scale();
			tempScale -= Vector2(0.1f, 0.1f);
			mTex->Scale(tempScale);
			mTex->Translate(Vector2(120.0f, 120.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
	}

	void GameManager::PlayerTwoInputUpdate()
	{
		if (mInputManager->KeyDown(SDL_SCANCODE_I)) //Forward and Back
		{
			mTexTwo->Translate(Vector2(0, -80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_K))
		{
			mTexTwo->Translate(Vector2(0, 80.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_J)) //Left and Right
		{
			mTexTwo->Translate(Vector2(-80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_L))
		{
			mTexTwo->Translate(Vector2(80.0f, 0) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_U)) //Rotate Left and Right
		{
			mTexTwo->Rotate((-25) * mTimer->GetDeltaTime());
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_O))
		{
			mTexTwo->Rotate((25) * mTimer->GetDeltaTime());
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_M)) //Scale Up and Down
		{
			Vector2 tempScale = mTexTwo->Scale();
			tempScale += Vector2(0.1f, 0.1f);
			mTexTwo->Scale(tempScale);
			mTexTwo->Translate(Vector2(-55.0f, -55.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_PERIOD))
		{
			Vector2 tempScale = mTexTwo->Scale();
			tempScale -= Vector2(0.1f, 0.1f);
			mTexTwo->Scale(tempScale);
			mTexTwo->Translate(Vector2(55.0f, 55.0f) * mTimer->GetDeltaTime(), GameEntity::World);
		}
	}

	GameManager::GameManager() : mQuit(false)
	{
		// create Graphics singleton
		mGraphics = GraphicsManager::Instance();
		// create timer singleton
		mTimer = Timer::GetInstance();
		// verify Graphics module is ready
		if (!GraphicsManager::Initialized())
		{
			mQuit = true;
		}
		mAssetManager = AssetManager::Instance();

		mTex = new AnimatedTexture("SpriteSheet.png", // filename
			204, // x clip
			45, // y clip
			40, // clip w
			38, // clip h
			4, // total frames
			0.5f, // animation length in second
			AnimatedTexture::Horizontal); //frame layout

		mTex->Position(Vector2(GraphicsManager::SCREEN_WIDTH * 0.25f, GraphicsManager::SCREEN_HEIGHT * 0.5f));
		mTexTwo = new Texture("SpriteSheet.png");
		mTexTwo = new Texture("SpriteSheet.png", 184, 76, 22, 22);
		mTexTwo->Position(Vector2(GraphicsManager::SCREEN_WIDTH * 0.75f, GraphicsManager::SCREEN_HEIGHT * 0.5f));

		mInputManager = SDLInputManager::Instance();
		mAudioManager = AudioManager::Instance();

		mAudioManager->PlayMusic("SFX/478313__skibkamusic__skibka-music-theoretical-perspectives.wav", 0);

		mScreenManager = ScreenManager::Instance();
	}

	GameManager::~GameManager()
	{
		// release modules
		delete mScreenManager;
		mScreenManager = nullptr;

		delete mTex;
		mTex = nullptr;
		delete mTexTwo;
		mTexTwo = nullptr;
		GraphicsManager::Release();
		mGraphics = nullptr;
		Timer::Release();
		mTimer = nullptr;
		AssetManager::Release();
		mAssetManager = nullptr;
		SDLInputManager::Release();
		mInputManager = nullptr;
		delete mFontTexture;
		mFontTexture = nullptr;

		AudioManager::Release();
		mAudioManager = nullptr;
		SDLInputManager::Release();
		mInputManager = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}
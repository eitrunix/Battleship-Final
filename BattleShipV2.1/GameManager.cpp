#include "GameManager.h"

namespace SDLFramework {

	GameManager * GameManager::sInstance = nullptr;

	GameManager * GameManager::Instance()
	{
		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() {
		while (!mQuit) {
			mTimer->Update();

			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				Update();
				LateUpdate();
				Render();
				mTimer->Reset();
			}
		}
	}

	void GameManager::Update() {
		mInputManager->Update();

		if (mInputManager->KeyDown(SDL_SCANCODE_W)) {
			mTex->Translate(Vector2(0, -40.0f) * mTimer->DeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_S)) {
			mTex->Translate(Vector2(0, 40.0f) * mTimer->DeltaTime(), GameEntity::World);
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_A)) {
			mTex->Translate(Vector2(-40.0f, 0) * mTimer->DeltaTime(), GameEntity::World);
		}
		else if (mInputManager->KeyDown(SDL_SCANCODE_D)) {
			mTex->Translate(Vector2(40.0f, 0) * mTimer->DeltaTime(), GameEntity::World);
		}

		if (mInputManager->KeyPressed(SDL_SCANCODE_SPACE)) {
			std::cout << "Space pressed!" << std::endl;
		}
		if (mInputManager->KeyReleased(SDL_SCANCODE_SPACE)) {
			std::cout << "Space released!" << std::endl;
		}

		if (mInputManager->MouseButtonPressed(InputManager::Left)) {
			std::cout << "Left mouse button pressed!" << std::endl;
		}
		if (mInputManager->KeyDown(SDL_SCANCODE_L)) 
		{ 
			mAudioManager->PlaySFX("SFX/coin_credit.wav", 0, -1); 
		}

		mTex->Update();
	}

	void GameManager::LateUpdate() {
		mInputManager->UpdatePrevInput();
	}

	void GameManager::Render() {
		mGraphics->ClearBackBuffer();
		mFontTex->Render();
		mTex->Render();
		mGraphics->Render();
	}

	GameManager::GameManager() : mQuit(false) {
		mGraphics = Graphics::Instance();

		if (!Graphics::Initialized()) {
			mQuit = true;
		}
		mInputManager = InputManager::Instance();    
		mAudioManager = AudioManager::Instance();
		mAssetManager = AssetManager::Instance();

		mTimer = Timer::Instance();
		//mAudioManager->PlayMusic("SFX/11 Name Entry.mp3", 10);
		mTex = new AnimatedTexture("SpriteSheet.png", 204, 45, 40, 38, 4, 0.5f, AnimatedTexture::Horizontal);
		mTex->Position(Vector2(Graphics::SCREEN_WIDTH*0.5f, Graphics::SCREEN_HEIGHT*0.5f));
		mFontTex = new Texture("Space Shooty Game", "ARCADE.TTF", 72, { 255, 0, 0 });
		mFontTex->Position(Vector2(400, 200));
	}

	GameManager::~GameManager() {
		delete mTex;
		mTex = nullptr;
		delete mFontTex;
		mFontTex = nullptr;

		Timer::Release();
		mTimer = nullptr;

		InputManager::Release();
		mInputManager = nullptr;

		AssetManager::Release();
		mAssetManager = nullptr;

		Graphics::Release();
		mGraphics = nullptr;

		AudioManager::Release();    
		mAudioManager = nullptr;

		InputManager::Release();   
		mInputManager = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}
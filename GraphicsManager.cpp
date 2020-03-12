#include "GraphicsManager.h"

namespace SDLFramework
{
	GraphicsManager* GraphicsManager::sInstance = nullptr;
	bool GraphicsManager::sInitialized = false;

	GraphicsManager* GraphicsManager::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new GraphicsManager();
		}
		return sInstance;
	}

	void GraphicsManager::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	bool GraphicsManager::Initialized()
	{
		return sInitialized;
	}

	SDL_Texture* GraphicsManager::LoadTexture(std::string path)
	{
		SDL_Texture* tex = nullptr;
		SDL_Surface* surface = IMG_Load(path.c_str());
		if (surface == nullptr)
		{
			std::cerr << "Unable to load " << path << ". IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}
		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr)
		{
			std::cerr << "Unable to create texture from surface! IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}
		SDL_FreeSurface(surface);
		return tex;
	}

	void GraphicsManager::DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip)
	{
		SDL_RenderCopyEx(mRenderer, tex, srcRect, dstRect, angle, nullptr, flip);
	}

	void GraphicsManager::ClearBackBuffer()
	{
		SDL_RenderClear(mRenderer);
	}

	void GraphicsManager::Render()
	{
		SDL_RenderPresent(mRenderer);
	}

	GraphicsManager::GraphicsManager() : mRenderer(nullptr)
	{
		sInitialized = Init();
	}

	GraphicsManager::~GraphicsManager()
	{
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
	}

	bool GraphicsManager::Init()
	{
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
		{
			std::cerr << "Unable to initialize SDL! SDL Error: " << SDL_GetError() << std
				::endl;
			return false;
		}

		mWindow = SDL_CreateWindow(
			WINDOW_TITLE, // window title
			SDL_WINDOWPOS_UNDEFINED, // window x pos
			SDL_WINDOWPOS_UNDEFINED, // window y pos
			SCREEN_WIDTH, // window width
			SCREEN_HEIGHT, // window height
			SDL_WINDOW_SHOWN); // window flags

		if (mWindow == nullptr)
		{
			std::cerr << "Unable to create Window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mRenderer == nullptr)
		{
			std::cerr << "Unable to create renderer! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		// temporary background colour change
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		if (TTF_Init() == -1)
		{
			std::cerr << "Unable to initialized SDL_ttf! TTF Error: " << TTF_GetError
			() << std::endl;
			return false;
		}
		return true;
	}

	SDL_Texture* GraphicsManager::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color)
	{
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
		if (surface == nullptr)
		{
			std::cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}
		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr)
		{
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}
		SDL_FreeSurface(surface);
		return tex;
	}
}
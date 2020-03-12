#ifndef __GRAPHICSMANAGER_H
#define __GRAPHICSMANAGER_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <sstream>


namespace SDLFramework
{
	class GraphicsManager
	{

	public:
		static const short SCREEN_WIDTH = 1024;
		static const short SCREEN_HEIGHT = 896;
		const char* WINDOW_TITLE = "Galaga";

		static GraphicsManager* Instance();
		static void Release();
		static bool Initialized();
		SDL_Texture* LoadTexture(std::string path);
		void ClearBackBuffer();
		void Render();

		void DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect = nullptr, SDL_Rect* dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
		SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

	private:
		static GraphicsManager* sInstance;
		static bool sInitialized;
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;

		GraphicsManager();
		~GraphicsManager();
		bool Init();
	};
}
#endif
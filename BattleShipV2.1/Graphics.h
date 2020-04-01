#ifndef __GRAPHICS_H
#define __GRAPHICS_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

namespace SDLFramework {

	class Graphics {
	public:
		static const short SCREEN_WIDTH = 1024;
		static const short SCREEN_HEIGHT = 896;

	private:
		static Graphics * sInstance;
		static bool sInitialized;

		SDL_Window * mWindow;
		SDL_Renderer * mRenderer;

	public:
		static Graphics * Instance();
		static void Release();
		static bool Initialized();

		SDL_Texture * LoadTexture(std::string path);
		void DrawTexture(SDL_Texture * tex, SDL_Rect * srcRect = nullptr, SDL_Rect * dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
		SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

		void ClearBackBuffer();

		void Render();

	private:
		Graphics();
		~Graphics();

		bool Init();
	};
}
#endif
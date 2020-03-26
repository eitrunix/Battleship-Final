#ifndef __TEXTURE_H
#define __TEXTURE_H
#include "Graphics.h"
#include "GameEntity.h"
#include "AssetManager.h"

namespace SDLFramework {

	class Texture : public GameEntity 
	{
		protected:
			SDL_Texture * mTex;
			Graphics * mGraphics;
	
			int mWidth;
			int mHeight;
	
			bool mClipped;
			SDL_Rect mSourceRect;
			SDL_Rect mDestinationRect;
	
		public:
			Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);
			Texture(std::string filename, bool managed = false);
			Texture(std::string filename, int x, int y, int w, int h, bool managed = false);
			~Texture();
	
			Vector2 ScaledDimensions();
	
			void Render() override;
	};
}
#endif
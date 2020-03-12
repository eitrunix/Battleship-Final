#ifndef __TEXTURE_H
#define __TEXTURE_H
#include "GraphicsManager.h"
#include "GameEntity.h"
#include "AssetManager.h"

namespace SDLFramework
{
	class Texture : public GameEntity
	{

		// ************* Attributes ************* //
	private:
		SDL_Texture* mTex;
		GraphicsManager* mGraphics;
		bool mClipped;
		SDL_Rect mDestinationRect;

	public:


		// ************* Functions ************* //
	private:

	public:
		Texture(std::string filename, bool managed = false);
		Texture(std::string filename, int x, int y, int w, int h, bool managed = false);
		Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);
		~Texture();
		Vector2 ScaledDimensions();
		void Render() override;

		// ************* Protected ************* //
	protected:
		SDL_Rect mSourceRect;
		int mWidth;
		int mHeight;

	};
}
#endif

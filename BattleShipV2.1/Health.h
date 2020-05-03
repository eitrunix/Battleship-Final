#pragma once
#include "AnimatedTexture.h" 
#include <vector>

using namespace SDLFramework;

class Health : public GameEntity
{
	std::vector<Texture*> mScore;
	SDL_Color mColour;

public:
	Health();
	Health(SDL_Color colour);
	~Health();

	void SetHealth(int health);
	void Render();

private:
	void ClearHealth();

};


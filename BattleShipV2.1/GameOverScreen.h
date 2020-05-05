#pragma once

#include "AnimatedTexture.h" 
#include "InputManager.h"
using namespace SDLFramework;

class GameOverScreen : public GameEntity
{
private:

	Timer* mTimer;
	InputManager* mInputManager;
	GameEntity* gameScreen;
	Texture* winLoss;
	Texture* backToStart;


public:

	GameOverScreen();
	~GameOverScreen();
	bool sTitle = false;
	void Update() override;
	void Render() override;

};


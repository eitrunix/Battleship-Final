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
	Texture* win;
	Texture* loss;
	Texture* uh;
	Texture* backToStart;


public:	
	
	GameOverScreen();
	~GameOverScreen();

	bool aiWin;
	bool playerWin;
	bool howThisHappen;
	bool sTitle = false;
	void Update() override;
	void Render() override;

};


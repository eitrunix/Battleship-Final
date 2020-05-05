#include "Health.h"

Health::Health() : Health({ 200,0,0 })
{
}

Health::Health(SDL_Color colour)
{
	mColour = colour;
	SetHealth(0);
}

Health::~Health()
{
	ClearHealth();
}

void Health::SetHealth(int health)
{
	ClearHealth();
	if (health == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			mScore.push_back(new Texture("0", "ARCADE.ttf", 32, { 200, 0,0 }));
			mScore[i]->Parent(this);
			mScore[i]->Position(Vector2(32.0f * i, 0.0f));
		}
	}
	else
	{
		std::string str = std::to_string(health);
		unsigned lastIndex = (unsigned)str.length() - 1;
		for (unsigned i = 0; i <= lastIndex; i++)
		{
			mScore.push_back(new Texture(str.substr(i, 1), "ARCADE.ttf", 32, {200, 0, 0}));
			mScore[i]->Parent(this);
			mScore[i]->Position(Vector2(-32.0f * (lastIndex - i), 0.0f));

		}
	}
}

void Health::Render()
{
	for (auto digit : mScore)
	{
		digit->Render();
	}
}

void Health::ClearHealth()
{
	for (unsigned i = 0; i < mScore.size(); i++)
	{
		mScore[i] = nullptr;
	}
	mScore.clear();
}


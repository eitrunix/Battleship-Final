#pragma once
#ifndef __TILE_H 
#define __TILE_H
#include "AnimatedTexture.h" 
#include "PlayerManager.h"
using namespace SDLFramework;

enum class TileType
{
	Water,
	Hit,
	Miss,
	Ship,
};


class Tile : public GameEntity
{

public:

	PlayerManager* mPlayerManager;
	bool isOccupied = false;

	void Update() override;
	void Render() override;

	void ChangeType(TileType _type);
	Tile(int TileRow, int TileCol, TileType _type);
	~Tile();

	int TileRow = 0;
	int TileCol = 0;

	const int TILE_WIDTH = 80;
	const int TILE_HEIGHT = 80;

	bool isHit = false;
	bool Attacked = false;
	bool tileChanged = false;
	TileType mType;

	Texture* HitTex;
	Texture* MissTex;
	Texture* TileTex;
	Texture* ShipTex;

private:
	SDL_Rect mBox;

};
#endif // __TILE_H 
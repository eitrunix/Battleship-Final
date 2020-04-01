#pragma once
#ifndef __TILE_H 
#define __TILE_H
#include "AnimatedTexture.h" 

using namespace SDLFramework;


class Tile : GameEntity
{
private:

public:

	enum class TileType
	{
		Water,
		Hit,
		Miss,
		Ship,
	};

	Texture* TileTex;
	TileType type = TileType::Water;
	bool isOccupied = false;

	int tileRow = 0;
	int tileCol = 0;

	void Update() override;
	void Render() override;

	Tile();
	~Tile();

};
#endif // __TILE_H 
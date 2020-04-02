#pragma once
#ifndef __TILE_H 
#define __TILE_H
#include "AnimatedTexture.h" 
using namespace SDLFramework;


class Tile : GameEntity
{

public:

	enum class TileType
	{
		Water,
		Hit,
		Miss,
		Ship,
	};

	Texture* TileTex;
	bool isOccupied = false;

	void Update() override;
	void Render() override;

	void ChangeType(TileType type);
	Tile(int TileRow, int TileCol, TileType type);
	~Tile();

	int TileRow;
	int TileCol;
	const int TILE_WIDTH = 80;
	const int TILE_HEIGHT = 80;
	TileType mType;

private:
	SDL_Rect mBox;

};
#endif // __TILE_H 
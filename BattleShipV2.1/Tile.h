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

	bool isOccupied = false;

	void Update() override;
	void Render() override;

	void ChangeType(TileType _type);
	Tile(int TileRow, int TileCol, TileType _type);
	~Tile();

	int TileRow;
	int TileCol;

	const int TILE_WIDTH = 80;
	const int TILE_HEIGHT = 80;

	bool isHit;
	bool isMiss;

	TileType mType;
	Texture* Hittex;
	Texture* MissTex;
	Texture* TileTex;

	bool isMissf();
	bool isHitf();
private:
	SDL_Rect mBox;

};
#endif // __TILE_H 
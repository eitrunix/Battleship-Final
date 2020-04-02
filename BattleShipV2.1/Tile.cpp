#include "Tile.h"

Tile::Tile(int TileRow, int TileCol, TileType _type)
{
	//Get the offsets
	mBox.x = TileRow;
	mBox.y = TileCol;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = _type;

	isMiss = false;
	isHit = false;
}

Tile::~Tile()
{
	delete TileTex;
	TileTex = nullptr;
}

void Tile::ChangeType(TileType _type)
{
	mType = _type;
}
void Tile::Render()
{
	TileTex->Render();
}

void Tile::Update()
{
	if (!isHit)
	{
		TileTex = new Texture("Water.png");
	}
	if (isHit)
	{
		Hittex = new Texture("Hit.png");
	}
	if (isMiss) 
	{
		MissTex = new Texture("Miss.png");
	}

}

bool Tile::isHitf()
{
	mType = TileType::Hit;
	isHit = true;
	return isHit;
}

bool Tile::isMissf()
{
	isMiss = true;
	return isMiss;
}
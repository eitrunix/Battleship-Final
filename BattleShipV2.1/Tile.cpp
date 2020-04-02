#include "Tile.h"

Tile::Tile(int TileRow, int TileCol, TileType type)
{
	//Get the offsets
	mBox.x = TileRow;
	mBox.y = TileCol;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = type;
	
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

}
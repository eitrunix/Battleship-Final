#include "Tile.h"

void Tile::ChangeType(TileType _type)
{
	mType = _type;
}

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

	HitTex = new Texture("Hit.png");
	MissTex = new Texture("Miss.png");	
	TileTex = new Texture("Water.png");

}

Tile::~Tile()
{
	delete TileTex;
	TileTex = nullptr;
	delete HitTex;
	HitTex = nullptr;
	delete MissTex;
	MissTex = nullptr;

}

void Tile::Render()
{
	if (isHit)
	{
		TileTex = HitTex;
		HitTex->Render();
		HitTex->Position(Position());
		TileTex->Active(false);
	}
	if (isMiss)
	{
		TileTex = MissTex;
		MissTex->Render();
		MissTex->Position(Position());
	}
	else
	{
		TileTex->Render();
		TileTex->Position(Position());

	}

}

void Tile::Update()
{

}

bool Tile::isHitf(bool hit)
{
	isHit = hit;
	return isHit;
}

bool Tile::isMissf(bool miss)
{
	isMiss = miss;
	return isMiss;
}
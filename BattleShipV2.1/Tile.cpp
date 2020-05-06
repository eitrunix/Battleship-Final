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

	isHit = false;

	HitTex = new Texture("Hit.png");
	MissTex = new Texture("Miss.png");	
	TileTex = new Texture("Water.png");
	mPlayerManager = PlayerManager::Instance();

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
	switch (mType)
	{
	case TileType::Hit:
		TileTex = HitTex;
		HitTex->Position(Position());
		HitTex->Render();

		break;
	case TileType::Miss:
		TileTex = MissTex;
		MissTex->Position(Position());
		MissTex->Render();

		break;
	case TileType::Water:
		TileTex->Render();
		TileTex->Position(Position());
		break;
	case TileType::Ship:
		TileTex = ShipTex;
		TileTex->Render();
		TileTex->Position(Position());
		break;
	}


}

void Tile::Update()
{

}

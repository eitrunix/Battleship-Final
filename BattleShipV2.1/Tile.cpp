#include "Tile.h"

Tile::Tile()
{
	TileTex = new Texture("Water.png");
	type = TileType::Water;

}

Tile::~Tile()
{
	delete TileTex;
	TileTex = nullptr;
}

void Tile::Render()
{

	TileTex->Render();

}

void Tile::Update()
{

}
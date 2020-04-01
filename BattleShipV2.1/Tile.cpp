#include "Tile.h"


void Tile::Update()
{

}

void Tile::Render()
{

	TileTex->Render();

}

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

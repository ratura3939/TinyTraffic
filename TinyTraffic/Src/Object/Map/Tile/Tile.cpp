#include "../../../pch.h"
#include "Tile.h"

namespace {
	const int CENTER_COLOR = 0x00ff00;	//中心色
	const int NOT_PLACEABLE_COLOR = 0xff0000;	//設置不可色
}

Tile::Tile(const VECTOR& _position)
	:isPlaceable_(false)
	,tileType_(TILE_TYPE::MAX)
{
	pos_ = _position;

	color_ = NOT_PLACEABLE_COLOR;
}

Tile::~Tile(void)
{
}

void Tile::Draw(void)
{
	DrawSphere3D(pos_, 4.0f, 8, color_, color_, false);
}

void Tile::Release(void)
{
}

void Tile::DoLoad(void)
{
}

void Tile::DoInit(void)
{
}

void Tile::DoUpdate(void)
{
}

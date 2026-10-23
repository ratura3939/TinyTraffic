#include "../../../pch.h"
#include "Tile.h"

namespace {
	const int CENTER_COLOR = 0x00ff00;	//中心色
	const int NOT_PLACEABLE_COLOR = 0xff0000;	//設置不可色
}

Tile::Tile(const VECTOR& _position)
	:isPlaceable_(false)
{
	pos_ = _position;
}

Tile::~Tile(void)
{
}

void Tile::Draw(void)
{
	int useColor = isPlaceable_ ? CENTER_COLOR : NOT_PLACEABLE_COLOR;
	DrawSphere3D(pos_, 4.0f, 8, useColor, useColor, false);
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

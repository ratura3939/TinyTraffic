#include "../../../pch.h"
#include "Tile.h"

namespace {
	const int CENTER_COLOR = 0x00ff00;	//中心色
}

Tile::Tile(const VECTOR& _position)
{
	pos_ = _position;
}

Tile::~Tile(void)
{
}

void Tile::Draw(void)
{
	DrawSphere3D(pos_, 4.0f, 8, CENTER_COLOR, CENTER_COLOR, false);
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

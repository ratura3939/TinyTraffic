#include "../../../pch.h"
#include "Tile.h"

namespace {
	const int CENTER_COLOR = 0x00ff00;	//中心色
}

void Tile::Draw(void)
{
	DrawSphere3D(pos_, 8.0f, 8, CENTER_COLOR, CENTER_COLOR, false);
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

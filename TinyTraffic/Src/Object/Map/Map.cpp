#include "../../pch.h"
#include "Map.h"

Map::Map(const int _mapImage)
    :mapImage_(_mapImage)
{
}

Map::~Map(void)
{
}

void Map::Draw(void)
{
	DrawRotaGraph(0, 0, 1.0f, 0.0f, mapImage_, false);
}

void Map::Release(void)
{
}

void Map::DoLoad(void)
{
}

void Map::DoInit(void)
{
}

void Map::DoUpdate(void)
{
}

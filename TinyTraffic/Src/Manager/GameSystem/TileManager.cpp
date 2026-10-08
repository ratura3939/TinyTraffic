#include "../../pch.h"
#include"../../Object/Map/Tile/Tile.h"
#include"../../Object/Map/Tile/TileState.h"
#include "TileManager.h"

void TileManager::Load(void)
{
	for (int x = 0; x < TILE_NUM_X; ++x)
	{
		for (int y = 0; y < TILE_NUM_Y; ++y)
		{
			tile_[x][y] = std::make_unique<Tile>();
			tile_[x][y]->Load();
		}
	}
	tileState_ = std::make_unique<TileState>();
}

void TileManager::Init(void)
{
	for (int x = 0; x < TILE_NUM_X; ++x)
	{
		for (int y = 0; y < TILE_NUM_Y; ++y)
		{
			tile_[x][y]->Init();
		}
	}
}

void TileManager::Update(void)
{
}

void TileManager::Draw(void) const
{
	for (int x = 0; x < TILE_NUM_X; ++x)
	{
		for (int y = 0; y < TILE_NUM_Y; ++y)
		{
			tile_[x][y]->Draw();
		}
	}
}

TileManager::TileManager(void)
{
}

TileManager::~TileManager(void)
{
}

#include "../../pch.h"
#include"../../Application.h"
#include"../../Object/Map/Tile/Tile.h"
#include"../../Object/Map/Tile/TileState.h"
#include"../Generic/SceneManager.h"
#include"../Generic/Camera.h"
#include "TileManager.h"

void TileManager::Load(void)
{
	//グリッドの半分の長さ
	const int halfGridX = TILE_NUM_X / 2;
	const int halfGridY = TILE_NUM_Y / 2;

	//マップの中央位置を中心としてグリッドを生成する(後々、スタート位置をマップ中央から以外にする可能性もあるので注意。あくまで全体マップの中心をグリッドの中心とする)
	const VECTOR& cameraPos = SceneManager::GetInstance().GetCamera().GetPos();
	VECTOR worldCenterPos = { cameraPos.x, cameraPos.y, 0.0f };

	//各方向の始点(中心から半分＊グリッドサイズを引く)
	const float startX = worldCenterPos.x - static_cast<float>(halfGridX * GRIT_SIZE);
	const float startY = worldCenterPos.y - static_cast<float>(halfGridY * GRIT_SIZE);

	//タイルの初期位置
	VECTOR tileInitPosition = { startX + GRIT_SIZE / 2.0f,  startY + GRIT_SIZE / 2.0f,0.0f };
	VECTOR tilePosition = tileInitPosition;

	//タイル生成
	for (int x = 0; x < TILE_NUM_X; ++x)
	{
		for (int y = 0; y < TILE_NUM_Y; ++y)
		{
			tile_[x][y] = std::make_unique<Tile>(tilePosition);
			tile_[x][y]->Load();

			tilePosition.y += GRIT_SIZE;
		}

		tilePosition.x += GRIT_SIZE;
		tilePosition.y = tileInitPosition.y;
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

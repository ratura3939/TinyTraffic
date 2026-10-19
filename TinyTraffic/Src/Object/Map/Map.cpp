#include "../../pch.h"
#include"../../Application.h"
#include"../../Manager/Generic/InputManager.h"
#include"../../Manager/Generic/SceneManager.h"
#include"../../Manager/Generic/Camera.h"
#include"../../Manager/GameSystem/TileManager.h"
#include"../../Constans/GameRule.h"
#include "Map.h"

namespace {
	const int GRID_COLOR = 0xff0000;	//グリッドの色(R)
}

Map::Map(const int _mapImage)
    :mapImage_(_mapImage)
{
}

Map::~Map(void)
{
}

void Map::Draw(void)
{
	const VECTOR& centerPos = Application::GetInstance().GetWindowCenterPos();
	DrawRotaGraph(static_cast<int>(centerPos.x), static_cast<int>(centerPos.y), scale_, 0.0f, mapImage_, false);

	//タイルの描画
	TileManager::GetInstance().Draw();

	//グリッド線の描画
	DrawGrid();
}

void Map::Release(void)
{
}

void Map::SetScaleFromProgress(const float _progress)
{
	//ゲームの開始から終了までの拡大率変化賞
	float totalScalingAmount = MAP_SCALE_GAME_END - MAP_SCALE_GAME_START;

	//進行度に応じて拡大率を設定
	scale_ = MAP_SCALE_GAME_START + totalScalingAmount * _progress;
}

void Map::DoLoad(void)
{
	TileManager::CreateInstance(SingletonRegistry::DESTROY_TIMING::GAME_END);
}

void Map::DoInit(void)
{
	scale_ = MAP_SCALE_GAME_START;
}

void Map::DoUpdate(void)
{
	Application& app = Application::GetInstance();

	//const VECTOR& windowCenterPos = app.GetWindowCenterPos();
	VECTOR windowCenterPos = app.GetWindowCenterPos();
	VECTOR worldCenterPos = ConvScreenPosToWorldPos(windowCenterPos);
	scale_ = MAP_SCALE_GAME_START;
}

void Map::DrawGrid(void)
{
	//グリッドの半分の長さ
	const int halfGridX = TILE_NUM_X / 2;
	const int halfGridY = TILE_NUM_Y / 2;

	Application& app = Application::GetInstance();

	//マップの中央位置を中心としてグリッドを生成する(後々、スタート位置をマップ中央から以外にする可能性もあるので注意。あくまで全体マップの中心をグリッドの中心とする)
	//const VECTOR& worldCenterPos = ConvScreenPosToWorldPos(app.GetWindowCenterPos());
	//const VECTOR& windowCenterPos = app.GetWindowCenterPos();
	VECTOR windowCenterPos = app.GetWindowCenterPos();
	VECTOR worldCenterPos = ConvScreenPosToWorldPos(windowCenterPos);

	//各方向の始点(中心から半分＊グリッドサイズを引く)
	const float startX = worldCenterPos.x - static_cast<float>(halfGridX * GRIT_SIZE);
	const float startY = worldCenterPos.y - static_cast<float>(halfGridY * GRIT_SIZE);
	
	//グリッド描画の位置
	VECTOR drawGridStartPos;
	VECTOR drawGridEndPos;

	//列用グリッドの生成(X方向)
	drawGridStartPos = { startX, startY, 0.0f };
	drawGridEndPos = { startX, startY + GRIT_SIZE * TILE_NUM_Y, 0.0f };

	DrawGridLines(drawGridStartPos, drawGridEndPos, TILE_NUM_X, GRID_DRAW_TYPE::GIRID_X);

	//行用グリッドの生成(Y方向)
	drawGridStartPos = { startX, startY, 0.0f };
	drawGridEndPos = { startX + GRIT_SIZE * TILE_NUM_X, startY, 0.0f };

	DrawGridLines(drawGridStartPos, drawGridEndPos, TILE_NUM_Y, GRID_DRAW_TYPE::GRID_Y);
}

void Map::DrawGridLines(const VECTOR& _startPos, const VECTOR& _endPos, const int _drawNum, const GRID_DRAW_TYPE& _drawType)
{
	//スタート位置・エンド位置
	VECTOR drawGridStartPos = _startPos;
	VECTOR drawGridEndPos = _endPos;

	//グリッド間隔
	VECTOR girdInterval = Utility::VECTOR_ZERO;

	//描画方向によって差分を設定
	if (_drawType == GRID_DRAW_TYPE::GIRID_X)
	{
		girdInterval = { GRIT_SIZE, 0.0f, 0.0f };
	}
	else if (_drawType == GRID_DRAW_TYPE::GRID_Y)
	{
		girdInterval = { 0.0f, GRIT_SIZE, 0.0f };
	}

	for (int i = 0; i < _drawNum; ++i)
	{
		//ライン描画
		DrawLine3D(drawGridStartPos, drawGridEndPos, GRID_COLOR);

		//差分追加
		drawGridStartPos = VAdd(drawGridStartPos, girdInterval);
		drawGridEndPos = VAdd(drawGridEndPos, girdInterval);
	}
}

#include "../../pch.h"
#include"../../Application.h"
#include"../../Manager/Generic/InputManager.h"
#include"../../Manager/Generic/SceneManager.h"
#include"../../Manager/Generic/Camera.h"
#include "Map.h"

namespace {
	const float SCALE_GAME_START = 4.0f;	//マップの初期拡大率
	const float SCALE_GAME_END = 1.7f;		//マップの最終拡大率

	const int GRIT_X_NUM = 36;	//グリッドの横の数
	const int GRIT_Y_NUM = 20;	//グリッドの縦の数
	const float GRIT_SIZE = 16.0f * SCALE_GAME_END;	//グリッドの大きさ(大きさは最終拡大率基準)

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

	//グリッド線の描画
	DrawGrid();
}

void Map::Release(void)
{
}

void Map::SetScaleFromProgress(const float _progress)
{
	//ゲームの開始から終了までの拡大率変化賞
	float totalScalingAmount = SCALE_GAME_END - SCALE_GAME_START;

	//進行度に応じて拡大率を設定
	scale_ = SCALE_GAME_START + totalScalingAmount * _progress;
}

void Map::DoLoad(void)
{
}

void Map::DoInit(void)
{
	scale_ = SCALE_GAME_START;
}

void Map::DoUpdate(void)
{
	
}

void Map::DrawGrid(void)
{
	//グリッドの半分の長さ
	const int halfGridX = GRIT_X_NUM / 2;
	const int halfGridY = GRIT_Y_NUM / 2;

	Application& app = Application::GetInstance();

	//マップの中央位置を中心としてグリッドを生成する(後々、スタート位置をマップ中央から以外にする可能性もあるので注意。あくまで全体マップの中心をグリッドの中心とする)
	const VECTOR& worldCenterPos = ConvScreenPosToWorldPos(app.GetWindowCenterPos());

	//各方向の始点(中心から半分＊グリッドサイズを引く)
	const float startX = worldCenterPos.x - static_cast<float>(halfGridX * GRIT_SIZE);
	const float startY = worldCenterPos.y - static_cast<float>(halfGridY * GRIT_SIZE);
	
	//グリッド描画の位置
	VECTOR drawGridStartPos;
	VECTOR drawGridEndPos;

	//列用グリッドの生成(X方向)
	drawGridStartPos = { startX, startY, 0.0f };
	drawGridEndPos = { startX, startY + GRIT_SIZE * GRIT_Y_NUM, 0.0f };

	DrawGridLines(drawGridStartPos, drawGridEndPos, GRIT_X_NUM, GRID_DRAW_TYPE::GIRID_X);

	//行用グリッドの生成(Y方向)
	drawGridStartPos = { startX, startY, 0.0f };
	drawGridEndPos = { startX + GRIT_SIZE * GRIT_X_NUM, startY, 0.0f };

	DrawGridLines(drawGridStartPos, drawGridEndPos, GRIT_Y_NUM, GRID_DRAW_TYPE::GRID_Y);
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

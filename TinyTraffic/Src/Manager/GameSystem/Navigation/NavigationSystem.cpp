#include "../../pch.h"
#include"../TileManager.h"
#include "NavigationSystem.h"

void NavigationSystem::Load(void)
{
}

void NavigationSystem::Init(void)
{
}

void NavigationSystem::Update(void)
{
}

void NavigationSystem::Draw(void) const
{
}

bool NavigationSystem::RequestChangeTileToRoad(const int _x, const int _y)
{
	//同一マスだったら処理は必要ない
	if (prevRequestChangeToRoadTileIdxX_ == _x && prevRequestChangeToRoadTileIdxY_ == _y) {
		return false;
	}

	//前回リクエスト位置と比較し、隣接しているマスの場合リクエストを許可する
	bool isSuccess = false;

	//許容範囲の距離
	const int AcceptableDistance = 1;

	//隣接判定
	bool isRequestAllowed_X = fabs(prevRequestChangeToRoadTileIdxX_ - _x) <= AcceptableDistance;
	bool isRequestAllowed_Y = fabs(prevRequestChangeToRoadTileIdxY_ - _y) <= AcceptableDistance;

	//前回のリクエスト位置と隣接している場合
	if (isRequestAllowed_X && isRequestAllowed_Y) {
		//前回の位置と今回の位置を道路として設定
		TileManager& tileM = TileManager::GetInstance();
		
		tileM.SetTileState(prevRequestChangeToRoadTileIdxX_, prevRequestChangeToRoadTileIdxY_, TILE_TYPE::ROAD);
		tileM.SetTileState(_x, _y, TILE_TYPE::ROAD);
		isSuccess = true;
	}

	//前回リクエスト位置を更新
	prevRequestChangeToRoadTileIdxX_ = _x;
	prevRequestChangeToRoadTileIdxY_ = _y;

	return isSuccess;
}

NavigationSystem::NavigationSystem(void)
	:prevRequestChangeToRoadTileIdxX_(-100)
	,prevRequestChangeToRoadTileIdxY_(-100)
{
}

NavigationSystem::~NavigationSystem(void)
{
}

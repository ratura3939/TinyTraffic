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

bool NavigationSystem::RequestChangeTile(const int _x, const int _y)
{
	//同一マスだったら処理は必要ない
	if (prevRequestChangeIdxX_ == _x && prevRequestChangeIdxY_ == _y) {
		return false;
	}

	//前回リクエスト位置と比較し、隣接しているマスの場合リクエストを許可する
	bool isSuccess = false;

	//許容範囲の距離
	const int AcceptableDistance = 1;

	//隣接判定
	bool isRequestAllowed_X = fabs(prevRequestChangeIdxX_ - _x) <= AcceptableDistance;
	bool isRequestAllowed_Y = fabs(prevRequestChangeIdxY_ - _y) <= AcceptableDistance;

	//前回のリクエスト位置と隣接している場合
	if (isRequestAllowed_X && isRequestAllowed_Y) {
		isSuccess = true;
	}
	else {
		//前回リクエスト位置を更新
		prevRequestChangeIdxX_ = _x;
		prevRequestChangeIdxY_ = _y;
	}

	return isSuccess;
}

void NavigationSystem::SetConnectionInfo(const bool _isConnect, const int _targetX, const int _targetY, const int _neighborX, const int _neighborY)
{
	//ターゲット→隣接の接続
	Vector2 direction = GetDirectionTargetToNeighbor(_targetX, _targetY, _neighborX, _neighborY);

	navigationMap_[_targetX][_targetY].connectFlag[direction.x][direction.y] = _isConnect;

	//隣接→ターゲットの接続
	direction = GetDirectionTargetToNeighbor(_neighborX, _neighborY, _targetX, _targetY);

	navigationMap_[_neighborX][_neighborY].connectFlag[direction.x][direction.y] = _isConnect;
}

void NavigationSystem::RemoveConnectionInfo(const int _targetX, const int _targetY)
{
	NavigationMapData& targetMapData = navigationMap_[_targetX][_targetY];

	for (int neighborX = 0; neighborX < NEIGHBOR_AREA_SIZE; ++neighborX)
	{
		for (int neighborY = 0; neighborY < NEIGHBOR_AREA_SIZE; ++neighborY)
		{
			if (targetMapData.connectFlag[neighborX][neighborY])
			{
				const int neighborTileIdxX = _targetX + (neighborX - IDX_CONNECTION_AREA_TARGET_X);
				const int neighborTileIdxY = _targetY + (neighborY - IDX_CONNECTION_AREA_TARGET_Y);
				SetConnectionInfo(false, _targetX, _targetY, neighborTileIdxX, neighborTileIdxY);
			}
		}
	}
}

Vector2 NavigationSystem::GetDirectionTargetToNeighbor(const int _targetX, const int _targetY, const int _neighborX, const int _neighborY) const
{
	int directionX = _neighborX - _targetX;
	int directionY = _neighborY - _targetY;

	const int targetToNeighborX = directionX + IDX_CONNECTION_AREA_TARGET_X;
	const int targetToNeighborY = directionY + IDX_CONNECTION_AREA_TARGET_Y;

	return Vector2(targetToNeighborX, targetToNeighborY);
}

NavigationSystem::NavigationSystem(void)
	:prevRequestChangeIdxX_(-100)
	,prevRequestChangeIdxY_(-100)
{
}

NavigationSystem::~NavigationSystem(void)
{
}

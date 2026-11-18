#include "../../pch.h"
#include"../../Application.h"
#include"../../Object/Map/Tile/Tile.h"
#include"../../Object/Map/Tile/TileState.h"
#include"../Generic/SceneManager.h"
#include"../Generic/Camera.h"
#include"Navigation/NavigationSystem.h"
#include "TileManager.h"

//デバッグ用のインクルード
#include"CursorManager.h"

void TileManager::Load(void)
{
	//グリッドの半分の長さ
	const int halfGridX = TILE_NUM_X / 2;
	const int halfGridY = TILE_NUM_Y / 2;

	//マップの中央位置を中心としてグリッドを生成する(後々、スタート位置をマップ中央から以外にする可能性もあるので注意。あくまで全体マップの中心をグリッドの中心とする)
	const VECTOR& cameraPos = SceneManager::GetInstance().GetCamera().GetPos();
	VECTOR worldCenterPos = { cameraPos.x, cameraPos.y, 0.0f };

	//各方向の始点(中心から半分＊グリッドサイズを引く)
	tileStartPosX_ = worldCenterPos.x - static_cast<float>(halfGridX * GRIT_SIZE);
	tileStartPosY_ = worldCenterPos.y - static_cast<float>(halfGridY * GRIT_SIZE);

	//タイルの初期位置
	VECTOR tileInitPosition = { tileStartPosX_ + GRIT_SIZE / 2.0f,  tileStartPosY_ + GRIT_SIZE / 2.0f,0.0f };
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

	//初期エリア
	InitPlacebleArea();
}

void TileManager::Update(void)
{
	
}

void TileManager::Draw(void)
{
	for (int x = 0; x < TILE_NUM_X; ++x)
	{
		for (int y = 0; y < TILE_NUM_Y; ++y)
		{
			tile_[x][y]->Draw();
		}
	}

	const VECTOR cursorPos = CursorManager::GetInstance().GetPos();

	SearchTileIdxFromCursorPos(cursorPos);
}

void TileManager::ChangeTileToRoadFromClick(const VECTOR& _worldPos)
{
	Tile& clickedTile = *tile_[cursorTileIdxX_][cursorTileIdxY_];

	if(clickedTile.GetTileType()==TILE_TYPE::FREE&&clickedTile.IsPlaceable())
	{
		NavigationSystem& navigation = NavigationSystem::GetInstance();

		//ナビゲーションシステムに変更リクエスト
		const bool isRequest= navigation.RequestChangeTile(cursorTileIdxX_, cursorTileIdxY_);

		if (isRequest)
		{
			//タイル設定(今回と前回のリクエスト位置)
			const int prevRequestIdxX = navigation.GetPrevRequestChangeIdxX();
			const int prevRequestIdxY = navigation.GetPrevRequestChangeIdxY();

			SetTileState(cursorTileIdxX_, cursorTileIdxY_, TILE_TYPE::ROAD);
			SetTileState(prevRequestIdxX, prevRequestIdxY, TILE_TYPE::ROAD);

			//繋がった情報の更新
			navigation.SetConnectionInfo(true, prevRequestIdxX, prevRequestIdxY, cursorTileIdxX_, cursorTileIdxY_);

			//更新が終わったからprevの位置更新をしなければならない。改良しろ！！！
		}
	}
}

void TileManager::ChangeTileToFreeFromClick(const VECTOR& _worldPos)
{
	Tile& clickedTile = *tile_[cursorTileIdxX_][cursorTileIdxY_];

	NavigationSystem& navigation = NavigationSystem::GetInstance();

	if (clickedTile.GetTileType() == TILE_TYPE::ROAD && clickedTile.IsPlaceable())
	{
		SetTileState(cursorTileIdxX_, cursorTileIdxY_, TILE_TYPE::FREE);
		navigation.RemoveConnectionInfo(cursorTileIdxX_, cursorTileIdxY_);
	}
}

void TileManager::SetTileState(const int _x, const int _y, const TILE_TYPE _state)
{
	tileState_->SetTileState(_state, *tile_[_x][_y]);
}

void TileManager::SearchTileIdxFromCursorPos(const VECTOR& _screenPos)
{
	cursorPosAtWorld_ = Utility::VECTOR_INIT;
	cursorTileIdxX_ = -1;
	cursorTileIdxY_ = -1;

	if (IsCrossingScreenPosToPlanePos(_screenPos, cursorPosAtWorld_))
	{
		CheckCrossingPosIsInTileRange(cursorPosAtWorld_, cursorTileIdxX_, cursorTileIdxY_);
	}
}

void TileManager::InitPlacebleArea(void)
{
	//エリア中心位置(配列が０から始まるので-1)
	int areaHalfX = (TILE_NUM_X / 2) - 1;
	int areaHalfY = (TILE_NUM_Y / 2) - 1;

	//スタート位置(areaHalfXも範囲に含まれるのでその差分用で+1を行う)
	int areaStartX = (areaHalfX - (CAN_PLACE_TILE_NUM_X_GAME_START / 2)) + 1;
	int areaStartY = (areaHalfY - (CAN_PLACE_TILE_NUM_Y_GAME_START / 2)) + 1;

	//終了位置
	int areaEndX = areaHalfX + (CAN_PLACE_TILE_NUM_X_GAME_START / 2);
	int areaEndY = areaHalfY + (CAN_PLACE_TILE_NUM_Y_GAME_START / 2);

	//設置可能範囲の初期化
	for(int x= areaStartX; x <= areaEndX; ++x)
	{
		for(int y= areaStartY; y <= areaEndY; ++y)
		{
			tile_[x][y]->SetIsPlaceable(true);
			tileState_->SetTileState(TILE_TYPE::FREE, *tile_[x][y]);
		}
	}
}

const bool TileManager::IsCrossingScreenPosToPlanePos(const VECTOR& _screenPos, VECTOR& _planePos) const
{
	//スクリーン座標から平面座標に変換する(near/far)
	const VECTOR nearPos = ConvScreenPosToWorldPos({ _screenPos.x, _screenPos.y, 0.0f });
	const VECTOR farPos = ConvScreenPosToWorldPos({ _screenPos.x, _screenPos.y, 1.0f });

	//平面同士の距離(平行な時は処理を行わない)
	const VECTOR distance = VSub(farPos, nearPos);
	if (distance.z <= Utility::EPSILON_MIN)
	{
		return false;
	}

	float t = -nearPos.z / distance.z;

	//平面座標に変換
	_planePos = VGet(nearPos.x + distance.x * t, nearPos.y + distance.y * t, 0.0f);

	//変換できた
	return true;
}

const bool TileManager::CheckCrossingPosIsInTileRange(const VECTOR& _planePos, int& _x, int& _y) const
{
	//変換(スタート位置の差分を足して)
	int tileIdxX = static_cast<int>(_planePos.x+fabs(tileStartPosX_)) / GRIT_SIZE;
	int tileIdxY = static_cast<int>(_planePos.y+fabs(tileStartPosY_)) / GRIT_SIZE;

	//範囲外の場合
	if (tileIdxX < 0 || tileIdxX >= TILE_NUM_X || tileIdxY < 0 || tileIdxY >= TILE_NUM_Y)
	{
		//失敗
		return false;
	}

	//代入
	_x = tileIdxX;
	_y = tileIdxY;

	//成功
	return true;
}

TileManager::TileManager(void)
	:tileStartPosX_(0.0f)
	,tileStartPosY_(0.0f)
	,cursorPosAtWorld_({ 0.0f,0.0f,0.0f })
	,cursorTileIdxX_(-1)
	,cursorTileIdxY_(-1)
{
}

TileManager::~TileManager(void)
{
}

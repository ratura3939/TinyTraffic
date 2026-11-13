#include "../../../pch.h"
#include"Tile.h"
#include "TileState.h"

namespace {
	const int COLOR_FREE = 0x00ff00;	//フリー状態の色
	const int COLOR_ROAD = 0x0000ff;	//道路状態の色
	const int COLOR_HOME = 0xffa500;	//家状態の色
	const int COLOR_STORE = 0x9932cc;	//店状態の色
}


TileState::TileState(void)
{
}

TileState::~TileState(void)
{
}

void TileState::SetTileState(const TILE_TYPE& _tileType, Tile& _tile)
{
	//状態ごとの各種細かい設定
	switch (_tileType) {
	case TILE_TYPE::FREE:
		SetStateOfFree(_tile);
		break;
	case TILE_TYPE::ROAD:
		SetStateOfRoad(_tile);
		break;
	case TILE_TYPE::HOME:
		SetStateOfHome(_tile);
		break;
	case TILE_TYPE::STORE:
		SetStateOfStore(_tile);
		break;
	default:
		break;
	}

	//状態の設定
	_tile.SetTileType(_tileType);
}

void TileState::SetStateOfFree(Tile& _tile)
{
	_tile.SetColor(COLOR_FREE);

	//前の状態が道ならば
	if (_tile.GetTileType() == TILE_TYPE::ROAD) {
		//道情報の解除
		ReleaseStateOfRoad(_tile);
	}
}

void TileState::SetStateOfRoad(Tile& _tile)
{
	_tile.SetColor(COLOR_ROAD);
}

void TileState::SetStateOfHome(Tile& _tile)
{
	_tile.SetColor(COLOR_HOME);
}

void TileState::SetStateOfStore(Tile& _tile)
{
	_tile.SetColor(COLOR_STORE);
}

void TileState::ReleaseStateOfRoad(Tile& _tile)
{
}

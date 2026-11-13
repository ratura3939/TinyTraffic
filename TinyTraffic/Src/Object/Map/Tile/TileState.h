#pragma once
#include"TileType.h"

class Tile;

//タイルの状態変換用クラス
class TileState
{
public:
	TileState(void);
	~TileState(void);

	void SetTileState(const TILE_TYPE& _tileType, Tile& _tile);

private:
	//各種タイルの状態を設定する関数
	//設定
	void SetStateOfFree(Tile& _tile);
	void SetStateOfRoad(Tile& _tile);
	void SetStateOfHome(Tile& _tile);
	void SetStateOfStore(Tile& _tile);
	
	//解除
	void ReleaseStateOfRoad(Tile& _tile);	//道路状態からの解除(道路→フリーの時のみ発生)
};


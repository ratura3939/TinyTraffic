#pragma once
#include"TileType.h"

class Tile;

class TileState
{
public:
	TileState(void);
	~TileState(void);

	void SetTileState(const TILE_TYPE& _tileType,const Tile& _tile);

private:
	//各種タイルの状態を設定する関数
	//設定
	void SetStateOfFree(const Tile& _tile);
	void SetStateOfRoad(const Tile& _tile);
	void SetStateOfHome(const Tile& _tile);
	void SetStateOfStore(const Tile& _tile);
	
	//解除
	void ReleaseStateOfRoad(const Tile& _tile);	//道路状態からの解除(道路→フリーの時のみ発生)
};


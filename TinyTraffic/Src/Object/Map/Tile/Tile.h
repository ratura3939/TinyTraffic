#pragma once
#include "../../Common/ActorBase.h"
#include"TileType.h"

class Tile :
    public ActorBase
{
public:
    Tile(const VECTOR& _position);
    ~Tile(void)override;

    void Draw(void)override;
    void Release(void)override;

	void SetIsPlaceable(const bool _isPlaceable) { isPlaceable_ = _isPlaceable; }
	const bool IsPlaceable(void)const { return isPlaceable_; }

	void SetTileType(const TILE_TYPE& _tileType) { tileType_ = _tileType; }
    const TILE_TYPE& GetTileType(void)const { return tileType_; }

	void SetColor(const int _color) { color_ = _color; }

private:
    void DoLoad(void)override;
    void DoInit(void)override;
    void DoUpdate(void)override;

	TILE_TYPE tileType_;	//タイルの種類

	bool isPlaceable_;	//設置可能かどうか
	int color_;	//タイルの色
};


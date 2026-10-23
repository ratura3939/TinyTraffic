#pragma once
#include "../../Common/ActorBase.h"

class Tile :
    public ActorBase
{
public:
    //タイル種別
    enum class TILE_TYPE {
        NORMAL      //通常
        , ROAD       //道路
        , HOME       //家
        , STORE      //店
        , WATER      //水
        , MOUNTAIN   //山
        , MAX
    };

    Tile(const VECTOR& _position);
    ~Tile(void)override;

    void Draw(void)override;
    void Release(void)override;

	void SetIsPlaceable(const bool _isPlaceable) { isPlaceable_ = _isPlaceable; }
	const bool IsPlaceable(void)const { return isPlaceable_; }

private:
    void DoLoad(void)override;
    void DoInit(void)override;
    void DoUpdate(void)override;

	bool isPlaceable_;	//設置可能かどうか
};


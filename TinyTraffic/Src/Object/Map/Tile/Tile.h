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

    void Draw(void)override;
    void Release(void)override;

private:
    void DoLoad(void)override;
    void DoInit(void)override;
    void DoUpdate(void)override;
};


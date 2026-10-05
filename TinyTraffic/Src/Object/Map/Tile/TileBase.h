#pragma once
#include "../../Common/ActorBase.h"

class TileBase :
    public ActorBase
{
public:

    //タイル種別
    enum class TILE_TYPE {
        NORMAL      //通常
		,ROAD       //道路
        ,HOME       //家
        ,STORE      //店
        ,WATER      //水
        ,MOUNTAIN   //山
        ,MAX
    };

	TileBase(void);
    virtual ~TileBase(void)override;


};


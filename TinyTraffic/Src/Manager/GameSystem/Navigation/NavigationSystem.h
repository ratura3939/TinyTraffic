#pragma once
#include "../../../Common/Singleton.h"
#include"../../../Constans/GameRule.h"

class NavigationSystem :
    public Singleton<NavigationSystem>
{
    //シングルトン化のためにSingletonをフレンドに
    friend class Singleton<NavigationSystem>;

public:
	enum class NABIGATION_MAP
	{
		START
		,ROAD
		,GOAL
	};

	void Load(void)override;
	void Init(void)override;
	void Update(void);
	void Draw(void)const;

	bool RequestChangeTileToRoad(const int _x, const int _y);

private:
	NavigationSystem(void);
	~NavigationSystem(void)override;

	NABIGATION_MAP navigationMap_[TILE_NUM_X][TILE_NUM_Y];	//ナビゲーションマップ

	int prevRequestChangeToRoadTileIdxX_;	//前回道路へのリクエストがあったタイルIdxX
	int prevRequestChangeToRoadTileIdxY_;	//前回道路へのリクエストがあったタイルIdxY
};


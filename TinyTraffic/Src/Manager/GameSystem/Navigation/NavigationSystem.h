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

	struct NavigationMapData
	{
		NABIGATION_MAP mapType;
		bool connectFlag[NEIGHBOR_AREA_SIZE][NEIGHBOR_AREA_SIZE];	//接続フラグ(周囲とのフラグ)
	};

	void Load(void)override;
	void Init(void)override;
	void Update(void);
	void Draw(void)const;

	//タイルの変更許可取得
	bool RequestChangeTile(const int _x, const int _y);

	//接続情報の設定
	void SetConnectionInfo(const bool _isConnect, const int _targetX, const int _targetY, const int _neighborX, const int _neighborY);

	//接続情報の削除
	void RemoveConnectionInfo(const int _targetX, const int _targetY);

	const int GetPrevRequestChangeIdxX(void)const { return prevRequestChangeIdxX_; }
	const int GetPrevRequestChangeIdxY(void)const { return prevRequestChangeIdxY_; }

private:
	//隣接タイルの方向を取得
	Vector2 GetDirectionTargetToNeighbor(const int _targetX, const int _targetY, const int _neighborX, const int _neighborY)const;

	NavigationSystem(void);
	~NavigationSystem(void)override;

	NavigationMapData navigationMap_[TILE_NUM_X][TILE_NUM_Y];	//ナビゲーションマップ

	int prevRequestChangeIdxX_;	//前回道路へのリクエストがあったタイルIdxX
	int prevRequestChangeIdxY_;	//前回道路へのリクエストがあったタイルIdxY
};


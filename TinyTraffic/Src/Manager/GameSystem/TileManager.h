#pragma once
#include<memory>
#include"../../Common/Singleton.h"
#include"../../Constans/GameRule.h"
#include"../../Object/Map/Tile/TileType.h"

class Tile;
class TileState;

class TileManager :
    public Singleton<TileManager>
{
    //シングルトン化のためにSingletonをフレンドに
    friend class Singleton<TileManager>;

public:
    void Load(void)override;
    void Init(void)override;
    void Update(void);
    void Draw(void);

	void ChangeTileToRoadFromClick(const VECTOR& _worldPos);	//クリックした位置のタイルを道路に変更する
	void ChangeTileToFreeFromClick(const VECTOR& _worldPos);	//クリックした位置のタイルをフリーに変更する
	void SetTileState(const int x, const int y, const TILE_TYPE state);

	const float GetTileStartPosX(void)const { return tileStartPosX_; }
	const float GetTileStartPosY(void)const { return tileStartPosY_; }

	const VECTOR& GetCursorPosAtWorld(void)const { return cursorPosAtWorld_; }
	const int GetCursorTileIdxX(void)const { return cursorTileIdxX_; }
	const int GetCursorTileIdxY(void)const { return cursorTileIdxY_; }

	void SearchTileIdxFromCursorPos(const VECTOR& _screenPos);	//ワールド座標からタイルIdxを検索する

private:
	void InitPlacebleArea(void);	//設置可能範囲の初期化
	const bool IsCrossingScreenPosToPlanePos(const VECTOR& _screenPos, VECTOR& _planePos)const;	//スクリーン座標から平面座標に変換する(変換できたらtrue)
	const bool CheckCrossingPosIsInTileRange(const VECTOR& _planePos,int& _x, int& _y)const;	//平面座標のタイルイ位置がタイル範囲内かチェックする(範囲内であったらIdxを代入する)

    TileManager(void);
    ~TileManager(void)override;

	std::unique_ptr<Tile> tile_[TILE_NUM_X][TILE_NUM_Y];	//タイル
    std::unique_ptr<TileState> tileState_;

	float tileStartPosX_;	//タイルの開始位置X
	float tileStartPosY_;	//タイルの開始位置Y

	VECTOR cursorPosAtWorld_;	//カーソルのワールド座標
	int cursorTileIdxX_;	//カーソルのタイルIdxX
	int cursorTileIdxY_;	//カーソルのタイルIdxY
};


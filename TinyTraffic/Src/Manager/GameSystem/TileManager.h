#pragma once
#include<memory>
#include"../../Common/Singleton.h"
#include"../../Constans/GameRule.h"

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
    void Draw(void)const;

private:
    TileManager(void);
    ~TileManager(void)override;

	std::unique_ptr<Tile> tile_[TILE_NUM_X][TILE_NUM_Y];	//タイル
    std::unique_ptr<TileState> tileState_;
};


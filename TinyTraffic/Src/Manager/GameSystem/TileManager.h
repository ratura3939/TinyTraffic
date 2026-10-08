#pragma once
#include<memory>
#include"../../Common/Singleton.h"

class Tile;
class TileState;

class TileManager :
    public Singleton<TileManager>
{
    //シングルトン化のためにSingletonをフレンドに
    friend class Singleton<TileManager>;

public:
	static constexpr int TILE_NUM_X = 36;	//タイルのX方向の数
	static constexpr int TILE_NUM_Y = 20;	//タイルのY方向の数

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


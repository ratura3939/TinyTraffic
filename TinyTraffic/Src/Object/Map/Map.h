#pragma once
#include "../Common/ActorBase.h"
class Map :
    public ActorBase
{
public:
	//グリッド描画方向
	enum class GRID_DRAW_TYPE {
		GIRID_X
		,GRID_Y
		,MAX
	};

    Map(const int _mapImage);
    virtual ~Map(void);
    void Draw(void) override;
	void Release(void) override;

	//進行度から拡大率を設定する
	void SetScaleFromProgress(const float _progress);	

private:
    void DoLoad(void) override;
    void DoInit(void) override;
	void DoUpdate(void) override;

	void DrawGrid(void);	//グリッド描画
	void DrawGridLines(const VECTOR& _startPos, const VECTOR& _endPos, const int _drawNum, const GRID_DRAW_TYPE& _drawType);	//グリッド線描画

	int mapImage_;  //マップ画像
	float scale_;   //マップの拡大率
};


#pragma once
#include "../Common/ActorBase.h"
class Map :
    public ActorBase
{
public:
    Map(const int _mapImage);
    virtual ~Map(void);
    void Draw(void) override;
	void Release(void) override;

private:
    void DoLoad(void) override;
    void DoInit(void) override;
	void DoUpdate(void) override;

	void DrawGrid(void);	//グリッド描画

	int mapImage_;  //マップ画像
	float scale_;   //マップの拡大率
};


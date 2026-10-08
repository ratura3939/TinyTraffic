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

	int mapImage_;  //マップ画像
};


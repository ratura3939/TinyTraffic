#pragma once
#include"../Common/ActorBase.h"

class Cursor :
    public ActorBase
{
public:
    Cursor(void);
    ~Cursor(void)override;
    void Draw(void) override;
	void Release(void) override;

private:
    void DoLoad(void) override;
    void DoInit(void) override;
    void DoUpdate(void) override;
};


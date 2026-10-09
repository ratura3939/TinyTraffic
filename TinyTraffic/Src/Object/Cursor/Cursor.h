#pragma once
#include"../Common/ActorBase.h"

class Cursor :
    public ActorBase
{
public:
    Cursor(const float& _speed);
    ~Cursor(void)override;
    void Draw(void) override;
	void Release(void) override;

	void SetSpeed(const float& _speed) { speed_ = _speed; }

private:
    void DoLoad(void) override;
    void DoInit(void) override;
    void DoUpdate(void) override;

	float speed_;	//カーソルの移動速度
};


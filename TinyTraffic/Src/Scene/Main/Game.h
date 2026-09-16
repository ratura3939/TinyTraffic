#pragma once
#include "../SceneBase.h"
class Game :
    public SceneBase
{
	Game(void);
	~Game(void)override;

	void Init(void)override;
	void InitSound(void)override;
	void InitEffect(void)override;

	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;
	void Reset(void)override;
};


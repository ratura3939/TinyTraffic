#pragma once
#include<memory>
#include "../SceneBase.h"

class Map;

class Game :
    public SceneBase
{
public:
	Game(void);
	~Game(void)override;

	void Init(void)override;
	void InitSound(void)override;
	void InitEffect(void)override;

	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;
	void Reset(void)override;

private:
	std::unique_ptr<Map> map_;
};


#pragma once
#include<memory>
#include "../SceneBase.h"

class SelectBox;

class Title :
    public SceneBase
{
public:
    Title(void);
	~Title(void)override;

	void Init(void)override;
	void InitSound(void)override;
	void InitEffect(void)override;

	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;
	void Reset(void)override;

private:
	std::unique_ptr<SelectBox> startBox_;	//スタートボックス
	std::unique_ptr<SelectBox> exitBox_;	//終了ボックス
};


#pragma once
#include<string>
#include "Common/ActorBase.h"

class SelectBox :
    public ActorBase
{
public:
    SelectBox(void);
    ~SelectBox(void)override;
    void Draw(void) override;
	void Release(void) override;

	const bool& GetIsSelect(void)const { return isSelect_; }

private:
	void DoLoad(void) override;
	void DoInit(void) override;
	void DoUpdate(void) override;

	void CheckHitCursor(void);	//カーソルに当たっているかどうかをチェックする

	int width_;		//横幅
	int height_;	//縦幅

	bool isHitCursor_;	//カーソルに当たっているかどうか
	bool isSelect_;		//選択されているかどうか
	std::wstring text_;	//表示する文字列
};


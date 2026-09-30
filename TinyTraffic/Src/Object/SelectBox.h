#pragma once
#include<string>
#include "Common/ActorBase.h"

class SelectBox :
    public ActorBase
{
public:
	SelectBox(const VECTOR& _pos, const int _width, const int _height, const std::wstring& _text, const int _fontSize = 10);
    ~SelectBox(void)override;
    void Draw(void) override;
	void Release(void) override;

	const bool& GetIsSelect(void)const { return isSelect_; }

private:
	void DoLoad(void) override;
	void DoInit(void) override;
	void DoUpdate(void) override;

	void CheckHitCursor(void);	//カーソルに当たっているかどうかをチェックする
	void ShrinkBox(void);		//ボックスを縮小する
	void ExpandBox(void);		//ボックスを拡大する

	int width_;		//横幅
	int height_;	//縦幅

	float exRate_;	//拡大率
	int fontSize_;	//文字の大きさ
	bool isFinishChangeExRate_;	//拡大率の変更が終了したかどうか

	bool isHitCursor_;	//カーソルに当たっているかどうか
	bool isSelect_;		//選択されているかどうか
	std::wstring text_;	//表示する文字列
};


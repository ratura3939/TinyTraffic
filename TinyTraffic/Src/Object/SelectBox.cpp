#include "../pch.h"
#include "SelectBox.h"

namespace {
	const int BOX_COLOR = 0xb0c4de;	//通常カラー
	const int BOX_COLOR_SELECT = 0xffd700;	//被選択カラー
	const int TEXT_COLOR = 0xffffff;	//文字色
}

SelectBox::SelectBox(void)
{
}

SelectBox::~SelectBox(void)
{
}

void SelectBox::Draw(void)
{
	DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), width_, height_, isSelect_ ? BOX_COLOR_SELECT : BOX_COLOR, true);

	static const int TEXT_OFFSET = 10;	//文字の描画位置のオフセット 
	DrawFormatString(static_cast<int>(pos_.x) + TEXT_OFFSET, static_cast<int>(pos_.y) + TEXT_OFFSET, TEXT_COLOR, text_.c_str());
}

void SelectBox::Release(void)
{
}

void SelectBox::DoInit(void)
{
}

void SelectBox::DoUpdate(void)
{
	//カーソルとの当たり判定
	CheckHitCursor();
}

void SelectBox::CheckHitCursor(void)
{

}

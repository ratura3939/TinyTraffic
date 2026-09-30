#include "../pch.h"
#include"../Manager/Generic/InputManager.h"
#include"../Manager/GameSystem/CursorManager.h"
#include "SelectBox.h"

namespace {
	const int BOX_COLOR = 0xb0c4de;			//通常カラー
	const int BOX_COLOR_SELECT = 0xffd700;	//被選択カラー
	const int TEXT_COLOR = 0xffffff;		//文字カラー

	const float EX_RATE_MAX = 1.3f;	//拡大率の最大値
	const float EX_RATE_MIN = 1.0f;	//拡大率の最小値
	const float EX_RATE_ACC = 0.03f;	//拡大率の変化速度
}

SelectBox::SelectBox(const VECTOR& _pos, const int _width, const int _height, const std::wstring& _text, const int _fontSize)
	:width_(_width)
	,height_(_height)
	,exRate_(1.0f)
	,fontSize_(_fontSize)
	,isFinishChangeExRate_(true)
	,isHitCursor_(false)
	,isSelect_(false)
	,text_(_text)
{
	pos_ = _pos;
}

SelectBox::~SelectBox(void)
{
}

void SelectBox::Draw(void)
{
	int drawPosX = static_cast<int>(pos_.x);
	int drawPosY = static_cast<int>(pos_.y);

	//ボックスの描画
	DrawBox(drawPosX - static_cast<int>((width_ * exRate_) / 2.0f), drawPosY - static_cast<int>((height_ * exRate_) / 2.0f),
		drawPosX + static_cast<int>((width_ * exRate_) / 2.0f), drawPosY + static_cast<int>((height_ * exRate_) / 2.0f),
		isHitCursor_ ? BOX_COLOR_SELECT : BOX_COLOR,
		true);

	//座標位置の描画
	DrawCircle(drawPosX, drawPosY, 5, 0xff0000, true);

	//文字の描画
	static const int TEXT_OFFSET = 20;	//文字の描画位置のオフセット 
	DrawFormatString(drawPosX - TEXT_OFFSET, drawPosY, TEXT_COLOR, text_.c_str());
}

void SelectBox::Release(void)
{
}

void SelectBox::DoLoad(void)
{
}

void SelectBox::DoInit(void)
{
}

void SelectBox::DoUpdate(void)
{
	//カーソルとの当たり判定
	CheckHitCursor();

	//このボタンが選択されたとき
	if (isHitCursor_) {
		InputManager& input = InputManager::GetInstance();
		if (input.IsTriggerDown(InputManager::INPUT_COMMAND::ENTER))
		{
			isSelect_ = true;
		}
	}
	

	//ボックスの拡大縮小
	if (!isFinishChangeExRate_) {
		//カーソルがあたっているとき
		if (isHitCursor_) {
			//拡大する
			ExpandBox();
		}
		else {
			//縮小する
			ShrinkBox();
		}
	}
}

void SelectBox::CheckHitCursor(void)
{
	bool prevIsHitCursor = isHitCursor_;

	const VECTOR& cursorPos = CursorManager::GetInstance().GetPos();

	//矩形との当たり判定
	//描画上の各頂点
	const int boxLeft = static_cast<int>(pos_.x - (width_ * exRate_) / 2.0f);
	const int boxRight = static_cast<int>(pos_.x + (width_ * exRate_) / 2.0f);
	const int boxTop = static_cast<int>(pos_.y - (height_ * exRate_) / 2.0f);
	const int boxBottom = static_cast<int>(pos_.y + (height_ * exRate_) / 2.0f);

	if(cursorPos.x >= boxLeft && cursorPos.x <= boxRight &&
		cursorPos.y >= boxTop && cursorPos.y <= boxBottom)
	{
		isHitCursor_ = true;
	}
	else
	{
		isHitCursor_ = false;
	}

	//カーソルとの当たり判定が変化したとき
	if (isHitCursor_ != prevIsHitCursor)
	{
		//拡大率の変更が終了していない状態にする
		isFinishChangeExRate_ = false;
	}
}

void SelectBox::ShrinkBox(void)
{
	exRate_ -= EX_RATE_ACC;
	if (exRate_ <= EX_RATE_MIN)
	{
		exRate_ = EX_RATE_MIN;
		isFinishChangeExRate_ = true;
	}
}

void SelectBox::ExpandBox(void)
{
	exRate_ += EX_RATE_ACC;
	if (exRate_ >= EX_RATE_MAX)
	{
		exRate_ = EX_RATE_MAX;
		isFinishChangeExRate_ = true;
	}
}

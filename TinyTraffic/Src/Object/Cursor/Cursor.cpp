#include "../../pch.h"
#include"../../Application.h"
#include"../../Manager/Generic/InputManager.h"
#include "Cursor.h"

namespace {
	const int CURSOR_RADIUS = 10;	//カーソルの半径
	const int CURSOR_COLOR = 0xff0000;	//カーソルの色
}

Cursor::Cursor(const float& _speed)
	:speed_(_speed)
{
}

Cursor::~Cursor(void)
{
}

void Cursor::Draw(void)
{
	DrawCircle(static_cast<int>(pos_.x), static_cast<int>(pos_.y), CURSOR_RADIUS, CURSOR_COLOR, true);
	InputManager& input = InputManager::GetInstance();
	const auto& moveInput = input.GetMoveInput();

	DrawFormatString(50, 50, 0xffffff, L"MousePos: (%.2f, %.2f) \nInputMove: (%.2f, %.2f)", pos_.x, pos_.y, moveInput.x, moveInput.y);
}

void Cursor::Release(void)
{
}

void Cursor::DoLoad(void)
{
}

void Cursor::DoInit(void)
{
	pos_ = Application::GetInstance().GetWindowCenterPos();
}

void Cursor::DoUpdate(void)
{
	InputManager& input = InputManager::GetInstance();

	const auto& moveInput = input.GetMoveInput();

	//上下左右の移動
	if (input.IsPressed(InputManager::INPUT_COMMAND::UP)) {
		movedPos_.y -= speed_ * moveInput.y;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::DOWN)) {
		movedPos_.y += speed_ * moveInput.y;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::LEFT)) {
		movedPos_.x -= speed_ * moveInput.x;
	}
	if(input.IsPressed(InputManager::INPUT_COMMAND::RIGHT)) {
		movedPos_.x += speed_ * moveInput.x;
	}
}

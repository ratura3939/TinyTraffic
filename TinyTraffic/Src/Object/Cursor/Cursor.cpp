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
		movedPos_.y -= speed_;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::DOWN)) {
		movedPos_.y += speed_;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::LEFT)) {
		movedPos_.x -= speed_;
	}
	if(input.IsPressed(InputManager::INPUT_COMMAND::RIGHT)) {
		movedPos_.x += speed_;
	}
}

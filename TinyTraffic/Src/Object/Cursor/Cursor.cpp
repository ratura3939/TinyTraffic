#include "../../pch.h"
#include"../../Application.h"
#include"../../Manager/Generic/InputManager.h"
#include "Cursor.h"

namespace {
	const int CURSOR_RADIUS = 10;	//カーソルの半径
	const int CURSOR_COLOR = 0xff0000;	//カーソルの色
	const float CURSOR_SPEED = 5.0f;	//カーソルの移動速度
}

Cursor::Cursor(void)
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
	pos_ = { Application::GetInstance().GetWindowWidth() / 2.0f, Application::GetInstance().GetWindowHeight() / 2.0f, 0.0f };
}

void Cursor::DoUpdate(void)
{
	InputManager& input = InputManager::GetInstance();

	//上下左右の移動
	if (input.IsPressed(InputManager::INPUT_COMMAND::UP)) {
		movedPos_.y -= CURSOR_SPEED;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::DOWN)) {
		movedPos_.y += CURSOR_SPEED;
	}
	if (input.IsPressed(InputManager::INPUT_COMMAND::LEFT)) {
		movedPos_.x -= CURSOR_SPEED;
	}
	if(input.IsPressed(InputManager::INPUT_COMMAND::RIGHT)) {
		movedPos_.x += CURSOR_SPEED;
	}
}

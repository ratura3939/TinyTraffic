#include "../../pch.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include "Title.h"

Title::Title(void)
{
}

Title::~Title(void)
{
}

void Title::Init(void)
{
}

void Title::InitSound(void)
{
}

void Title::InitEffect(void)
{
}

void Title::Update(void)
{
}

void Title::Draw(void)
{
	DrawString(0, 0, L"TitleScene", 0xffffff);
	CursorManager::GetInstance().Draw();
}

void Title::Release(void)
{
}

void Title::Reset(void)
{
}

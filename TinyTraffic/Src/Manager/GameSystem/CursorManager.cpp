#include "../../pch.h"
#include"../../Object/Cursor/Cursor.h"
#include "CursorManager.h"

void CursorManager::Load(void)
{
	cursor_ = std::make_unique<Cursor>();
	//カーソルの読み込み
	cursor_->Load();
}

void CursorManager::Init(void)
{
	//カーソルの初期化
	cursor_->Init();
}

void CursorManager::SetPos(const VECTOR& _pos)
{
	cursor_->SetPos(_pos);
}

const VECTOR& CursorManager::GetPos(void) const
{
	return cursor_->GetPos();
}

#include "../../pch.h"
#include"../../Object/Cursor/Cursor.h"
#include "CursorManager.h"

namespace{
	const float CURSOR_DEFAULT_SPEED = 10.0f;	//カーソルのデフォルト速度
}

void CursorManager::Load(void)
{
	cursor_ = std::make_unique<Cursor>(CURSOR_DEFAULT_SPEED);
	//カーソルの読み込み
	cursor_->Load();
}

void CursorManager::Init(void)
{
	//カーソルの初期化
	cursor_->Init();
}

void CursorManager::Update(void)
{
	cursor_->Update();
}

void CursorManager::Draw(void)const
{
	cursor_->Draw();
}

void CursorManager::SetPos(const VECTOR& _pos)
{
	cursor_->SetPos(_pos);
}

const VECTOR& CursorManager::GetPos(void) const
{
	return cursor_->GetPos();
}

CursorManager::CursorManager(void)
{
}

CursorManager::~CursorManager(void)
{
}

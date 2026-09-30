#include "../../pch.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include "Game.h"

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::Init(void)
{
}

void Game::InitSound(void)
{
}

void Game::InitEffect(void)
{
}

void Game::Update(void)
{
	
}

void Game::Draw(void)
{
	DrawString(0, 0, L"GameScene", 0xffffff);

	//カーソルの描画
	CursorManager::GetInstance().Draw();
}

void Game::Release(void)
{
}

void Game::Reset(void)
{
}

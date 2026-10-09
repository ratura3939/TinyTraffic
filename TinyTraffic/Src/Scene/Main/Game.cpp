#include "../../pch.h"
#include"../../Manager/Generic/ResourceManager.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include"../../Object/Map/Map.h"
#include "Game.h"

Game::Game(void)
	:map_(nullptr)
{
	
}

Game::~Game(void)
{
	
}

void Game::Init(void)
{
	ResourceManager& resM = ResourceManager::GetInstance();
	resM.Init(SceneManager::SCENE_ID::GAME);

	map_ = std::make_unique<Map>(resM.Load(ResourceManager::SRC::TEST_MAP_1_IMG).handleId_);
	map_->Load();
	map_->Init();
}

void Game::InitSound(void)
{
}

void Game::InitEffect(void)
{
}

void Game::Update(void)
{
	map_->Update();
}

void Game::Draw(void)
{
	map_->Draw();

	//カーソルの描画
	CursorManager::GetInstance().Draw();

	DrawString(0, 0, L"GameScene", 0xffffff);
}

void Game::Release(void)
{
}

void Game::Reset(void)
{
}

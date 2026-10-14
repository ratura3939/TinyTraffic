#include "../../pch.h"
#include"../../Manager/Generic/ResourceManager.h"
#include"../../Manager/Generic/InputManager.h"
#include"../../Manager/Generic/SceneManager.h"
#include"../../Manager/Generic/Camera.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include"../../Object/Map/Map.h"
#include "Game.h"

namespace {
	const float CAMERA_POSITION_Z_GAME_START = -230.0f;	//カメラのZ座標(ゲーム開始時)
	const float CAMERA_POSITION_Z_GAME_END = -480.0f;	//カメラのZ座標(ゲーム終了時)
	const float CAMERA_ZOOM_OUT_SPEED = 0.5f;	//カメラのズームアウトスピード

	const float ZOOM_OUT_MILESTONE_INTERVAL = 0.25f;	//ズームアウトのマイルストーン
	const float ZOOM_OUT_MILESTONE_MAX = 1.0f;	//ズームアウトのマイルストーン最大値
}

Game::Game(void)
	:map_(nullptr)
	,isZoomOut_(false)
	,zoomOutProgress_(0.0f)
	,lastZoomOutMilestone_(0.0f)
{
	
}

Game::~Game(void)
{
	
}

void Game::Init(void)
{
	ResourceManager& resM = ResourceManager::GetInstance();
	resM.Init(SceneManager::SCENE_ID::GAME);

	Camera& camera = SceneManager::GetInstance().GetCamera();
	camera.ChangeMode(Camera::MODE::FIXED_POINT);
	camera.SetPos({ 0.0f, 0.0f, CAMERA_POSITION_Z_GAME_START });

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

	//カメラのズームアウト
	if (isZoomOut_) {
		ZoomOutCamera();
	}


	InputManager& inputM = InputManager::GetInstance();
	if (inputM.IsPressed(InputManager::INPUT_COMMAND::ENTER)) {
		isZoomOut_ = true;

		if (zoomOutProgress_ >= ZOOM_OUT_MILESTONE_MAX) {
			isZoomOut_ = false;
		}
	}
}

void Game::Draw(void)
{
	map_->Draw();

	//カーソルの描画
	CursorManager::GetInstance().Draw();
	
	//デバッグ情報
	DrawDebug();
}

void Game::Release(void)
{
}

void Game::Reset(void)
{
}

void Game::ZoomOutCamera(void)
{
	Camera& camera = SceneManager::GetInstance().GetCamera();

	//後退させる
	camera.MoveBackCamera(CAMERA_ZOOM_OUT_SPEED);

	//現在のカメラのZ座標
	float currentZ = camera.GetPos().z;

	//スタートからの移動量
	float currentMovementZ = fabs(currentZ) - fabs(CAMERA_POSITION_Z_GAME_START);

	//全体の移動量
	float totalMovementZ = fabs(CAMERA_POSITION_Z_GAME_END) - fabs(CAMERA_POSITION_Z_GAME_START);

	//進行度を更新
	zoomOutProgress_ = currentMovementZ / totalMovementZ;

	//マップへの適用
	map_->SetScaleFromProgress(zoomOutProgress_);

	//終了条件
	if (zoomOutProgress_ - lastZoomOutMilestone_ >= ZOOM_OUT_MILESTONE_INTERVAL)
	{
		lastZoomOutMilestone_ = zoomOutProgress_;
		isZoomOut_ = false;
	}
}

void Game::DrawDebug(void)
{

	DrawString(0, 0, L"GameScene", 0xffffff);

	auto& cameraPos = SceneManager::GetInstance().GetCamera().GetPos();

	DrawFormatString(0, 0, 0xff000, L"CameraPos:%.2f,%.2f,%.2f", cameraPos.x, cameraPos.y, cameraPos.z);
}

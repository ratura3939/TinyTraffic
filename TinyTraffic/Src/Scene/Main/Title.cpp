#include "../../pch.h"
#include"../../Application.h"
#include"../../Manager/Generic/SceneManager.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include"../../Object/SelectBox.h"
#include"Game.h"
#include "Title.h"

namespace {
	const VECTOR START_BOX_POS = { 400.0f,300.0f,0.0f };	//スタートボックスの座標
	const int START_BOX_WIDTH = 200;	//スタートボックスの横幅
	const int START_BOX_HEIGHT = 50;	//スタートボックスの縦幅
	const std::wstring START_BOX_TEXT = L"Start";	//スタートボックスの文字列


	const VECTOR EXIT_BOX_POS = { 400.0f,400.0f,0.0f };	//終了ボックスの座標
	const int EXIT_BOX_WIDTH = 150;	//終了ボックスの横幅
	const int EXIT_BOX_HEIGHT = 40;	//終了ボックスの縦幅
	const std::wstring EXIT_BOX_TEXT = L"Exit";	//終了ボックスの文字列
}

Title::Title(void)
	:startBox_(std::make_unique<SelectBox>(START_BOX_POS, START_BOX_WIDTH, START_BOX_HEIGHT, START_BOX_TEXT))
	,exitBox_(std::make_unique<SelectBox>(EXIT_BOX_POS, EXIT_BOX_WIDTH, EXIT_BOX_HEIGHT, EXIT_BOX_TEXT))
{
}

Title::~Title(void)
{
}

void Title::Init(void)
{
	startBox_->Load();
	startBox_->Init();

	exitBox_->Load();
	exitBox_->Init();
}

void Title::InitSound(void)
{
}

void Title::InitEffect(void)
{
}

void Title::Update(void)
{
	startBox_->Update();
	exitBox_->Update();

	//スタートボタンが選択されたとき
	if (startBox_->GetIsSelect()) {
		SceneManager::GetInstance().ChangeScene(std::make_shared<Game>());
	}

	//終了ボタンが選択されたとき
	if (exitBox_->GetIsSelect()) {
		//ゲームの終了
		Application::GetInstance().EndGame();
	}
}

void Title::Draw(void)
{
	DrawString(0, 0, L"TitleScene", 0xffffff);

	//選択肢の描画
	startBox_->Draw();
	exitBox_->Draw();

	//カーソルの描画
	CursorManager::GetInstance().Draw();
}

void Title::Release(void)
{
}

void Title::Reset(void)
{
}

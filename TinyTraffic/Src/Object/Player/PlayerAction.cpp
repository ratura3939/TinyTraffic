#include "../../pch.h"
#include"../../Manager/GameSystem/CursorManager.h"
#include"../../Manager/GameSystem/TileManager.h"
#include"../../Manager/Generic/InputManager.h"
#include "PlayerAction.h"

PlayerAction::PlayerAction(void)
{
}

PlayerAction::~PlayerAction(void)
{
}

void PlayerAction::Init(void)
{
}

void PlayerAction::Update(void)
{
	InputManager& inputM = InputManager::GetInstance();

	//押されているとき
	if (inputM.IsPressed(InputManager::INPUT_COMMAND::ENTER)) {
		TileManager::GetInstance().ChangeTileToRoadFromClick(ConvScreenPosToWorldPos(CursorManager::GetInstance().GetPos()));
	}

	//押されているとき
	if (inputM.IsPressed(InputManager::INPUT_COMMAND::CANCEL)) {
		TileManager::GetInstance().ChangeTileToFreeFromClick(ConvScreenPosToWorldPos(CursorManager::GetInstance().GetPos()));
	}
}

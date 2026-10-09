#include "../../pch.h"
#include"../../Application.h"
#include "Map.h"

namespace {
	const float SCALE_GAME_START = 4.0f;	//マップの初期拡大率
	const float SCALE_GAME_END = 1.7f;		//マップの最終拡大率

	const int GRIT_X_NUM = 36;	//グリッドの横の数
	const int GRIT_Y_NUM = 20;	//グリッドの縦の数
	const float GRIT_SIZE = 16.0f * SCALE_GAME_END;	//グリッドの大きさ(大きさは最終拡大率基準)
}

Map::Map(const int _mapImage)
    :mapImage_(_mapImage)
{
}

Map::~Map(void)
{
}

void Map::Draw(void)
{
	const VECTOR& centerPos = Application::GetInstance().GetWindowCenterPos();
	DrawRotaGraph(static_cast<int>(centerPos.x), static_cast<int>(centerPos.y), SCALE_GAME_END, 0.0f, mapImage_, false);

	DrawGrid();

}

void Map::Release(void)
{
}

void Map::DoLoad(void)
{
}

void Map::DoInit(void)
{
	scale_ = SCALE_GAME_START;
}

void Map::DoUpdate(void)
{
}

void Map::DrawGrid(void)
{
	const int halfGridX = GRIT_X_NUM / 2;
	const int halfGridY = GRIT_Y_NUM / 2;

	Application& app = Application::GetInstance();

	const VECTOR& worldCenterPos = ConvScreenPosToWorldPos(app.GetWindowCenterPos());


	const int startX = static_cast<int>(worldCenterPos.x) - halfGridX * GRIT_SIZE;
	const int startY = static_cast<int>(worldCenterPos.y) - halfGridY * GRIT_SIZE;
	
	int gridDrawPosX = startX;
	int gridDrawPosY = startY;

}

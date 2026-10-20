#pragma once

#pragma region Constans->GameCamera
static constexpr float CAMERA_POSITION_Z_GAME_START = -230.0f;	//カメラのZ座標(ゲーム開始時)
static constexpr float CAMERA_POSITION_Z_GAME_END = -480.0f;	//カメラのZ座標(ゲーム終了時)
static constexpr float CAMERA_ZOOM_OUT_SPEED = 0.5f;	//カメラのズームアウトスピード

static constexpr float ZOOM_OUT_MILESTONE_INTERVAL = 0.25f;	//ズームアウトのマイルストーン
static constexpr float ZOOM_OUT_MILESTONE_MAX = 1.0f;	//ズームアウトのマイルストーン最大値
#pragma endregion


#pragma region Constans->Map
static constexpr int TILE_NUM_X = 36;	//タイルの横の数
static constexpr int TILE_NUM_Y = 20;	//タイルの縦の数

static constexpr float MAP_SCALE_GAME_START = 4.0f;		//マップの初期拡大率
static constexpr float MAP_SCALE_GAME_END = 1.7f;		//マップの最終拡大率

static constexpr float GRIT_SIZE = 16.0f * MAP_SCALE_GAME_END;	//グリッドの大きさ(大きさは最終拡大率基準)


#pragma endregion

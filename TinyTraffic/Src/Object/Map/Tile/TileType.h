#pragma once

//地形種別
enum class TERRAIN_TYPE {
	NORMAL		//通常
	, WATER		//水
	, MOUNTAIN	//山
	, MAX
};

//タイル種別
enum class TILE_TYPE {
	FREE	//何もない
	,ROAD	//道路
	,HOME	//家
	,STORE	//店
	,MAX
};
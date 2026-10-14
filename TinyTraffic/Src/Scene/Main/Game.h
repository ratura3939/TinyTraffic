#pragma once
#include<memory>
#include "../SceneBase.h"

class Map;

class Game :
    public SceneBase
{
public:
	Game(void);
	~Game(void)override;

	void Init(void)override;
	void InitSound(void)override;
	void InitEffect(void)override;

	void Update(void)override;
	void Draw(void)override;
	void Release(void)override;
	void Reset(void)override;

private:
	void ZoomOutCamera(void);	//カメラのズームアウト

	void DrawDebug(void);	//デバッグ描画

	std::unique_ptr<Map> map_;
	bool isZoomOut_;	//ズームアウト中かどうか
	float zoomOutProgress_;	//ズームアウトの進行度(0.0f～1.0f)
	float lastZoomOutMilestone_;	//最後にズームアウトしたマイルストーン
};


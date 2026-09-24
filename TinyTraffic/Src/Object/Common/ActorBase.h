#pragma once
#include<DxLib.h>
#include<memory>
#include"../../Common/Quaternion.h"

class ActorBase
{
public:
	//初期化用
	static constexpr float INIT_MODEL_ROT = 180.0f;	//Unity形式のモデルの形を合わせる用

	//重力定数
	static constexpr float GRAVITY_POW = -0.98f;

	ActorBase(void);
	virtual ~ActorBase(void);

	void Load(void);
	void Init(void);
	void Update(void);
	virtual void Draw(void) = 0;
	virtual void Release(void) = 0;

	//位置設定
	void SetPos(const VECTOR& _pos);
	const VECTOR& GetPos(void)const;

	//移動後の位置設定
	void SetMovedPos(const VECTOR& _movedPos);
	const VECTOR& GetMovedPos(void)const;

protected:
	//派生クラス用
	virtual void DoLoad(void) = 0;		//読み込み
	virtual void DoInit(void) = 0;		//初期化
	virtual void DoUpdate(void) = 0;	//更新

	VECTOR pos_;		//座標
	VECTOR movedPos_;	//移動後座標
	VECTOR scl_;		//モデル大きさ
};


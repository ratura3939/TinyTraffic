#pragma once
#include<memory>
#include"../../Common/Singleton.h"

class Cursor;

class CursorManager
	: public Singleton<CursorManager>
{
	//シングルトン化のためにSingletonをフレンドに
	friend class Singleton<CursorManager>;

public:
	void Load(void)override;
	void Init(void)override;
	void Update(void);
	void Draw(void)const;

	void SetPos(const VECTOR& _pos);
	const VECTOR& GetPos(void)const;

private:
	CursorManager(void);
	~CursorManager(void)override;

	std::unique_ptr<Cursor> cursor_;	//カーソル
};


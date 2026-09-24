#include"../../pch.h"
#include"../../Utility/Utility.h"
#include "ActorBase.h"

ActorBase::ActorBase(void)
	: movedPos_(Utility::VECTOR_ZERO)
	, pos_(Utility::VECTOR_ZERO)
	, scl_(Utility::VECTOR_ONE)
{
}

ActorBase::~ActorBase(void)
{
}

void ActorBase::Load(void)
{
	DoLoad();
}

void ActorBase::Init(void)
{
	DoInit();
	movedPos_ = pos_;
}

void ActorBase::Update(void)
{
	//移動後の座標を影響
	pos_ = movedPos_;
	//派生クラスの更新処理
	DoUpdate();
}

void ActorBase::SetPos(const VECTOR& _pos)
{
	pos_ = _pos;
}

const VECTOR& ActorBase::GetPos(void) const
{
	return pos_;
}

void ActorBase::SetMovedPos(const VECTOR& _movedPos)
{
	movedPos_ = _movedPos;
}

const VECTOR& ActorBase::GetMovedPos(void)const
{
	return movedPos_;
}
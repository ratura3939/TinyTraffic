#pragma once
#include "../../../Common/Singleton.h"
#include"../../../Constans/GameRule.h"

class NavigationSystem :
    public Singleton<NavigationSystem>
{
    //シングルトン化のためにSingletonをフレンドに
    friend class Singleton<NavigationSystem>;

public:
	void Load(void)override;
	void Init(void)override;
	void Update(void);
	void Draw(void)const;

private:
	NavigationSystem(void);
	~NavigationSystem(void)override;


};


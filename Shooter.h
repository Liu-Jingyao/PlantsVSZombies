#pragma once
#include "Plant.h"
#include "Animation.h"
#include "PeaBullet.h"

#pragma comment(lib,"Winmm.lib")
 class Shooter: public Plant
{
public:
	Shooter(int  as, int  ms, int  po_x, int  po_y, int hp, int p, int b);
	virtual ~Shooter() = 0;
	virtual void update();						// 植物更新	
private:
	int bulletType;								// 子弹类型，1表示豌豆子弹,2表示寒冰子弹,3表示水球
};
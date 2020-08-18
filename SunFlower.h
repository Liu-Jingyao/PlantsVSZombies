#pragma once
#include "Plant.h"
/*
模块名 : 向日葵类
文件名 :Plant.h
相关文件 : Plant.h,Object.h,Animation.h
文件实现功能 : 实现了向日葵的动画状态、坐标和价格、血量的初始化
*/
class SunFlower: public Plant
{
public:
	SunFlower(int as, int ms, int po_x, int po_y);
	~SunFlower();
	virtual void update();							// 向日葵产阳光
	static int getPlantPrice();
private:
	static const int plantPrice;
};


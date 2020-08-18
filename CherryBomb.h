#pragma once
#include "Plant.h"
/*
模块名 : 樱桃炸弹类
文件名 :CherryBomb.h
相关文件 : Plant.h,Object.h,Animation.h
文件实现功能 : 实现了向日葵的动画状态、坐标和价格、血量的初始化
*/
class CherryBomb :public Plant
{
public:
	static const Sound bombSound;			
	CherryBomb(int as, int ms, int po_x, int po_y);
	~CherryBomb();
	virtual void update();							//樱桃炸弹消失
	static int getPlantPrice();							
private:
	static const int plantPrice;
};
#pragma once
#include "Plant.h"
class WallNut : public Plant
{
public:
	WallNut(int as, int ms, int po_x, int po_y);
	~WallNut();
	virtual void update();							// ���տ�������
	static int getPlantPrice();
private:
	static const int plantPrice;
};


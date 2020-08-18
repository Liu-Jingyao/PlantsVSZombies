#pragma once
#include "Plant.h"
class WallNut : public Plant
{
public:
	WallNut(int as, int ms, int po_x, int po_y);
	~WallNut();
	virtual void update();							// 向日葵产阳光
	static int getPlantPrice();
private:
	static const int plantPrice;
};


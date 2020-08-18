#pragma once
#pragma once
#include "Shooter.h"
class SnowPea : public Shooter
{
public:
	SnowPea(int  as, int  ms, int  po_x, int  po_y);
	static int getPlantPrice();
private:
	static const int plantPrice;
};

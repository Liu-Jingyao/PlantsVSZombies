#pragma once
#include "Shooter.h"
class PeaShooter : public Shooter
{
public:
	PeaShooter(int  as, int  ms, int  po_x, int  po_y);
	static int getPlantPrice();
private:
	static const int plantPrice;
};


#include "SnowPea.h"

const int SnowPea::plantPrice = 175;

SnowPea::SnowPea(int as, int ms, int po_x, int po_y) :Shooter(as, ms, po_x, po_y, 300, 100, 2)
{
	Animation::loadAnimation("Plant\\SnowPea\\", 7,true);
}

int SnowPea::getPlantPrice() {
	return plantPrice;
}
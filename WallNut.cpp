#include "WallNut.h"
#include "globalVariables.h"

const int WallNut::plantPrice = 50;


WallNut::WallNut(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 4000, 50)
{
	Animation::loadAnimation("Plant\\WallNut\\", 8, true);					//º”‘ÿœÚ»’ø˚Õº∆¨
}

WallNut::~WallNut()
{
}

void WallNut::update()
{
	Plant::update();
}

int WallNut::getPlantPrice() {
	return plantPrice;
}

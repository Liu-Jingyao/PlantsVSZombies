#include "SunFlower.h"
#include "globalVariables.h"

const int SunFlower::plantPrice = 50;


SunFlower::SunFlower(int as, int ms, int po_x, int po_y) :Plant(as , ms , po_x , po_y, 300, 50)
{
	Animation::loadAnimation("Plant\\SunFlower\\", 18);					//º”‘ÿœÚ»’ø˚Õº∆¨
}

SunFlower::~SunFlower()
{
}

void SunFlower::update()
{
	Plant::update();

	if (!moveStatus && animationStatus) {
		workCounter = (workCounter + 1) % 100;
		if (!workCounter) {
			sunshineNum += 50;
		}
	}
}

int SunFlower::getPlantPrice() {
	return plantPrice;
}

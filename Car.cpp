#include "Car.h"

int Car::BaseHp = 15;
Car::Car(int as, int ms, int po_x, int po_y) :Shooter(1, 0, po_x, po_y, 300, 100, 3)
{
	Animation::loadAnimation("Plant\\Car\\",1,1);
}

Car::~Car()
{
}
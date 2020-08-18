#include "BucketheadZombie.h"

BucketheadZombie::BucketheadZombie(int as, int ms, int po_x, int po_y):Zombie(as, ms, -2, po_x, po_y, 370, 89, "BucketheadZombie")
{
	Animation::loadAnimation("Zombie//BucketheadZombie//", 8, true);
	randomAnimation();
}

BucketheadZombie::~BucketheadZombie()
{
}

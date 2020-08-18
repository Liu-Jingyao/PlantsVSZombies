#include "BasicZombie.h"

BasicZombie::BasicZombie(int as, int ms, int po_x, int po_y):Zombie(as, ms, -3, po_x, po_y, 270, 89, "BasicZombie")
{
	Animation::loadAnimation("Zombie//BasicZombie//", 8);
	randomAnimation();
}
BasicZombie::~BasicZombie() {}

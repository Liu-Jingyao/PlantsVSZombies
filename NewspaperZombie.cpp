#include "NewspaperZombie.h"

NewspaperZombie::NewspaperZombie(int as, int ms, int po_x, int po_y) :Zombie(as, ms, -2, po_x, po_y, 150, 89, "NewspaperZombie")
{
	Animation::loadAnimation("Zombie//NewspaperZombie//", 8, true);
	randomAnimation();
}

NewspaperZombie::~NewspaperZombie()
{
}

#pragma once
#include "Zombie.h"
class NewspaperZombie :public Zombie
{
public:
	NewspaperZombie(int as = 0, int ms = 0, int po_x = 0, int po_y = 0);
	~NewspaperZombie();
};


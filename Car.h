#pragma once
#include "Shooter.h"

//С����
class Car:public Shooter
{
public:
	Car(int  as, int  ms, int  po_x, int  po_y);
	~Car();
	static int BaseHp;
};


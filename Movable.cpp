#include "Movable.h"

Movable::Movable(int s, int vx, int vy):moveStatus(s), speed_x(vx), speed_y(vy)
{
}

Movable::~Movable()
{
}

void Movable::move(int &x, int &y)
{
	switch (moveStatus) {
	case 0:
		break;
	case 1:
		x += speed_x;
		y += speed_y;
		break;
	case 2:
		x = m.x - 30;
		y = m.y - 30;
		break;
	}
}

void Movable::setMoveStatus(int s)
{
	moveStatus = s;
}

void Movable::setSpeed_x(int v)
{
	speed_x = v;
}

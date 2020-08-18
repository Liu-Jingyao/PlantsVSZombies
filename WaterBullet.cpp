#include "WaterBullet.h"

WaterBullet::WaterBullet(int po_x, int po_y) :Bullet(po_x, po_y, 5, "waterBullet.png", 3, "Bullet_bk.jpg")
{
}

WaterBullet::~WaterBullet()
{
}

void WaterBullet::show()
{
	staMapping.put(position_x, position_y-10);
}

#pragma once
#include "Bullet.h"
class WaterBullet : public Bullet
{
public:
	WaterBullet(int po_x, int po_y);
	~WaterBullet();
	void show();							// �ӵ���ʾ����
};


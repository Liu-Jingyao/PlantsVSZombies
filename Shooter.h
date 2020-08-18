#pragma once
#include "Plant.h"
#include "Animation.h"
#include "PeaBullet.h"

#pragma comment(lib,"Winmm.lib")
 class Shooter: public Plant
{
public:
	Shooter(int  as, int  ms, int  po_x, int  po_y, int hp, int p, int b);
	virtual ~Shooter() = 0;
	virtual void update();						// ֲ�����	
private:
	int bulletType;								// �ӵ����ͣ�1��ʾ�㶹�ӵ�,2��ʾ�����ӵ�,3��ʾˮ��
};
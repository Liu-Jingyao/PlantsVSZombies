#pragma once
#include "Plant.h"
/*
ģ���� : ���տ���
�ļ��� :Plant.h
����ļ� : Plant.h,Object.h,Animation.h
�ļ�ʵ�ֹ��� : ʵ�������տ��Ķ���״̬������ͼ۸�Ѫ���ĳ�ʼ��
*/
class SunFlower: public Plant
{
public:
	SunFlower(int as, int ms, int po_x, int po_y);
	~SunFlower();
	virtual void update();							// ���տ�������
	static int getPlantPrice();
private:
	static const int plantPrice;
};


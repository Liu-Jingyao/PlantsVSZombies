#pragma once
#include "Plant.h"
/*
ģ���� : ӣ��ը����
�ļ��� :CherryBomb.h
����ļ� : Plant.h,Object.h,Animation.h
�ļ�ʵ�ֹ��� : ʵ�������տ��Ķ���״̬������ͼ۸�Ѫ���ĳ�ʼ��
*/
class CherryBomb :public Plant
{
public:
	static const Sound bombSound;			
	CherryBomb(int as, int ms, int po_x, int po_y);
	~CherryBomb();
	virtual void update();							//ӣ��ը����ʧ
	static int getPlantPrice();							
private:
	static const int plantPrice;
};
#pragma once
#include "Object.h"
#include "Animation.h"
#include "Image.h"
#include "Sound.h"
#include "Movable.h"

/*
ģ���� : ֲ����
�ļ��� : Plant.h
����ļ� : �����ļ���Object.h,Animation.h,Movable.h,�����ļ���Sunflower.h��Peashooter.h
�ļ�ʵ�ֹ��� : ֲ�︸��,������֡���ֲ��������ʾ�����º���
*/
class Plant :public Object, public Animation, public Movable
{
public:
	static Sound plantSound;
	Plant(int  animationstatus, int  movestatus, int  po_x, int  po_y, int  hp, int  p);
	virtual ~Plant() = 0;									//����������
	virtual int getPrice() const;
	virtual void setPrice(int price);
	virtual void show();
	virtual void update();
protected:
	int workCounter = 0;									//����������
	int price = 0;											//�۸�
};


#pragma once
#include "Zombie.h"
#include"Object.h"
#include"Animation.h"
#include"Movable.h"
/*
ģ���� : ������ʬ��
�ļ��� : BasicZombie.h
����ļ� : �����ļ���Object.h,Animation.h,Movable.h,Zombie.h
�ļ�ʵ�ֹ��� : ��ʼ����ʬѪ�����ٶ�δ��ʼ���������ػ�����ʬͼƬ
*/
class BasicZombie : public Zombie
{
public:
	BasicZombie(int as = 0, int ms = 0 , int po_x = 0, int po_y = 0);
	~BasicZombie();
};


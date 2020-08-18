#pragma once
#include "globalvariables.h"

/*
ģ���� : �˶���
�ļ��� : Movable.h
����ļ� : Movable.cpp
�ļ�ʵ�ֹ��� :��Ϊ��ʬ���ӵ��ࡢֲ����ĸ��࣬����ƶ�״̬���ƶ��ٶȣ������ṩ�����˶�״̬������Ӧ�˶����µĹ��ܡ�
ע������ǵü�ʱ
*/

class Movable
{
public:
	void setMoveStatus(int s);		// �ƶ�״̬set����
	void setSpeed_x(int v);
protected:
	Movable(int s = 0, int vx = 0, int vy = 0);		// ��Σ��ƶ�״̬���������ٶȣ��������ٶȣ�Ŀǰ�ò�����
	~Movable();
	void move(int &x, int &y);				// �ƶ�����������update������һ����
	int moveStatus;									// �ƶ�״̬��0��ֹ��1ֱ���ƶ���2������ꣻ
	int speed_x;									// �������ٶ�
	int speed_y;									// �������ٶ�
};


#pragma once
#include "Object.h"
#include "Animation.h"
#include "Movable.h"
#include "Sound.h"
#include "Image.h"
/*
ģ���� : ��ʬ��
�ļ��� : Zombie.h
����ļ� : �����ļ���Object.h,Animation.h,Movable.h,�����ļ���BasicZombie.h
�ļ�ʵ�ֹ��� : ��ʬ���࣬��ʾ��������º���
*/
class Zombie :public Object, public Animation, public Movable
{
public:
	static const Sound eatSound;
	static int killNum;
	Zombie(int as, int ms, int  vx , int po_x, int po_y, int  health, int atk, std::string type);
	~Zombie();
	void show();
	void update();
	int getAttack() const;
	void setAttack(int attack);
	std::string getType();
	void setslowDown(int slowdown);
private:
	int attack;
	std::string type;
	bool slowDown = 0;						//1��ʾ�����٣�0��ʾδ������
	int workCounter = 0;
};


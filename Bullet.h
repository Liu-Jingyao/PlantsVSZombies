#pragma once
#include "Sound.h"
#include "Image.h"
#include "Object.h"
#include "Movable.h"
#include "Animation.h"
#include<conio.h>
#include <graphics.h>
#pragma comment(lib,"Winmm.lib")

/*
 *  Bullet �㶹�ӵ�������
 *  �ļ�����Bullet.h
 *  ����ļ���Shot.cpp
 */

class Bullet : public Object, Movable
{
public:
	static const Sound hitSound;			//���н�ʬ����
	Bullet(int  x, int  y, int atk, const Image other, int bt, const Image other_bk = "1.jpg");		// ���캯�� �������ӵ�����
	void update();						    // �ӵ�λ�ø��º���
	void show();							// �ӵ���ʾ����
	int getAttack() const;
	void setAttack(int attack);
	int getbulletType();
private:
	int attack;
	int bulletType;							//1Ϊ��ͨ�㶹��2Ϊ�����㶹
};


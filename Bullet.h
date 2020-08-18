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
 *  Bullet 豌豆子弹类声明
 *  文件名：Bullet.h
 *  相关文件：Shot.cpp
 */

class Bullet : public Object, Movable
{
public:
	static const Sound hitSound;			//击中僵尸声音
	Bullet(int  x, int  y, int atk, const Image other, int bt, const Image other_bk = "1.jpg");		// 构造函数 参数：子弹坐标
	void update();						    // 子弹位置更新函数
	void show();							// 子弹显示函数
	int getAttack() const;
	void setAttack(int attack);
	int getbulletType();
private:
	int attack;
	int bulletType;							//1为普通豌豆，2为寒冰豌豆
};


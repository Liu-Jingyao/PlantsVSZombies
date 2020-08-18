#pragma once
#include "globalvariables.h"

/*
模块名 : 运动类
文件名 : Movable.h
相关文件 : Movable.cpp
文件实现功能 :作为僵尸、子弹类、植物类的父类，存放移动状态、移动速度，对外提供根据运动状态做出相应运动更新的功能。
注意事项：记得及时
*/

class Movable
{
public:
	void setMoveStatus(int s);		// 移动状态set函数
	void setSpeed_x(int v);
protected:
	Movable(int s = 0, int vx = 0, int vy = 0);		// 入参：移动状态，横坐标速度，纵坐标速度（目前用不到）
	~Movable();
	void move(int &x, int &y);				// 移动函数，子类update函数的一部分
	int moveStatus;									// 移动状态，0静止，1直线移动，2跟随鼠标；
	int speed_x;									// 横坐标速度
	int speed_y;									// 纵坐标速度
};


#pragma once
#include "Zombie.h"
#include"Object.h"
#include"Animation.h"
#include"Movable.h"
/*
模块名 : 基本僵尸类
文件名 : BasicZombie.h
相关文件 : 父类文件：Object.h,Animation.h,Movable.h,Zombie.h
文件实现功能 : 初始化僵尸血量（速度未初始化），加载基本僵尸图片
*/
class BasicZombie : public Zombie
{
public:
	BasicZombie(int as = 0, int ms = 0 , int po_x = 0, int po_y = 0);
	~BasicZombie();
};


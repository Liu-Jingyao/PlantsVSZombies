#pragma once
#include "Object.h"
#include "Animation.h"
#include "Movable.h"
#include "Sound.h"
#include "Image.h"
/*
模块名 : 僵尸类
文件名 : Zombie.h
相关文件 : 父类文件：Object.h,Animation.h,Movable.h,子类文件：BasicZombie.h
文件实现功能 : 僵尸父类，显示函数与更新函数
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
	bool slowDown = 0;						//1表示被减速，0表示未被减速
	int workCounter = 0;
};


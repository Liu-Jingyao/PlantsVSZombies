#pragma once
#include "Object.h"
#include "Animation.h"
#include "Image.h"
#include "Sound.h"
#include "Movable.h"

/*
模块名 : 植物类
文件名 : Plant.h
相关文件 : 父类文件：Object.h,Animation.h,Movable.h,子类文件：Sunflower.h，Peashooter.h
文件实现功能 : 植物父类,点击音乐、种植音乐与显示、更新函数
*/
class Plant :public Object, public Animation, public Movable
{
public:
	static Sound plantSound;
	Plant(int  animationstatus, int  movestatus, int  po_x, int  po_y, int  hp, int  p);
	virtual ~Plant() = 0;									//虚析构函数
	virtual int getPrice() const;
	virtual void setPrice(int price);
	virtual void show();
	virtual void update();
protected:
	int workCounter = 0;									//工作计数器
	int price = 0;											//价格
};


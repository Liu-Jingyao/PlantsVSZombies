#pragma once
#include "Image.h"

/*
模块名 : 实体类
文件名 : Object.h
相关文件 : Image.h
文件实现功能 :作为植物类，僵尸类，子弹类和阳光类的父类，存储了贴图、血量、位置与存在的信息，
				并且提供了四种初始化方法（对两个贴图的成员变量的四种初始化方法），和各个
				变量的get、set函数
*/

class Object
{
	public:		
		Object(int po_x , int po_y , int hp=0 , const Image other = Image("1.jpg"), const Image other_bk = Image("1.jpg"));												//四种初始化方式初始化成员函数staMapping和staMapping_bk

		int getHealthPoint();
		void setHealthPoint(int hp);
														//血量的get和set函数
		int getPozition_x() const;
		void setPozition_x(int po_x);
														//坐标x的get和set函数
		int getPozition_y() const;
		void setPozition_y(int po_y);
				
		virtual ~Object();							    //虚析构函数

		virtual void update() = 0;
		virtual void show() = 0;

	protected:
		int healthPoint;								//实体类的血量，其中子弹类不存在血量
		int position_x;
		int position_y;									//实体类的位置（x、y坐标）
		Image staMapping;								//静态贴图
		Image staMapping_bk;							//静态遮罩图
};
#include "Object.h"



Object::Object(int po_x , int po_y, int hp ,const Image other, const Image other_bk)
	: staMapping(other), staMapping_bk(other_bk), healthPoint(hp), position_x(po_x), position_y(po_y) {}

int Object::getHealthPoint() 
		{ return this->healthPoint; }
					
void Object::setHealthPoint(int hp) 
		{ healthPoint = hp; }
											//血量的get、set函数
int Object::getPozition_x() const
		{ return this->position_x; }

void Object::setPozition_x(int po_x)
		{ position_x = po_x; }

//坐标x的get和set函数

int Object::getPozition_y() const
	{ return this->position_y; }
											//坐标x的get、set函数

void Object::setPozition_y(int po_y) 
		{ position_y = po_y; }

Object::~Object()
{
}



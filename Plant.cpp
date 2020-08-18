#pragma once
#include "Plant.h"
#include <string>

Sound Plant::plantSound("Plant.mp3");

Plant::Plant(int animationstatus, int movestatus, int po_x, int po_y, int hp, int p) : Animation(animationstatus), Movable(movestatus), Object(po_x, po_y, hp), price(p)
{

}

void Plant::show()
{
	Animation::play(Object::position_x, Object::position_y);											//·â×°playº¯Êý
}

void Plant::update()
{
	move(position_x, position_y);
	animationUpdate();
}
int Plant::getPrice() const
{
    return price;
}

void Plant::setPrice(int price)
{
    this->price = price;
}

Plant::~Plant() {

}


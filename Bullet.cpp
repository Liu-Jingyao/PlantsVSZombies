#include "Bullet.h"


const Sound Bullet::hitSound("BulletHitZombie.mp3");
Bullet::Bullet(int  x, int  y, int atk, const Image other,int bt, const Image other_bk) :Object(x,y,0, other, other_bk),Movable(1,50,0), attack(atk), bulletType(bt) {
}


void Bullet::update()
{
	move(position_x, position_y);
}

void Bullet::show()
{
	if (staMapping.getType()=="jpg") {
		staMapping_bk.put(position_x, position_y, NOTSRCERASE);
		staMapping.put(position_x, position_y, SRCINVERT);
	}
	else {
		staMapping.put(position_x, position_y);			
	}
}


int Bullet::getAttack() const
{
    return attack;
}

void Bullet::setAttack(int attack)
{
    this->attack = attack;
}

int Bullet::getbulletType()
{
	return this->bulletType;
}

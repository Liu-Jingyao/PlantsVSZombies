#include "Zombie.h"

const Sound Zombie::eatSound("eatingPlants.mp3");
int Zombie:: killNum = 0;


Zombie::Zombie(int as, int ms, int vx ,int po_x, int po_y, int health, int atk, std::string t):Object(po_x, po_y, health), Animation(as),Movable(ms, vx, 0), attack(atk), type(t) 
{
}

Zombie::~Zombie() {}

void Zombie::show()
{
	if (type == "BasicZombie") {
		Animation::play(Object::position_x, Object::position_y - 35);			//��װplay����
	}
	else {
		Animation::play(Object::position_x+35, Object::position_y - 30);
	}
}

void Zombie::update()
{
	move(position_x, position_y);
	animationUpdate();
	if (slowDown == 1)
	{
		if (workCounter == 0) {
			speed_x = speed_x / 2;						//��һ�α�����ʱ�ٶȼ���
			attack /= 2;
		}
		workCounter = 1700;								//��ʱ10s
		if (workCounter == 0)
		{
			speed_x = speed_x * 2;							//���ٽ����ٶȻظ�
			attack *= 2;
			slowDown = 0;
		}
	}
	
	if (workCounter != 0)
		workCounter--;
}

int Zombie::getAttack() const
{
    return attack/5;
}

void Zombie::setAttack(int attack)
{
    this->attack = attack;
}

std::string Zombie::getType()
{
	return type;
}

void Zombie::setslowDown(int slowdown)
{
	this->slowDown = slowdown;
}
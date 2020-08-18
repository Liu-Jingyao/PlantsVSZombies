#include "Shooter.h"
#include "globalVariables-objects.h"
#include <cstdio>
#include "IcePeaBullet.h"
#include "Waterbullet.h"

Shooter::Shooter(int  as, int  ms, int  po_x, int  po_y, int hp, int p, int b):Plant(as, ms, po_x, po_y, hp, p), bulletType(b) {
}

Shooter::~Shooter()
{
}

void Shooter::update()
{
	Plant::update();

	if(!moveStatus && animationStatus){
		bool hasZombie = false;			// 前方是否有僵尸
		for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
			if (map_y.at((*iterZ)->getPozition_y())== map_y.at(position_y) && (*iterZ)->getPozition_x() >= position_x - 10 && (*iterZ)->getPozition_x()<=Width-100) {
				hasZombie = true;
			}
		}
		if (hasZombie && (!workCounter)) {
			switch (bulletType) {
			case 1:
				bullet.push_back(new PeaBullet(position_x, position_y + 5));
				break;
			case 2:
				bullet.push_back(new IcePeaBullet(position_x, position_y + 5));
				break;
			case 3:
				bullet.push_back(new WaterBullet(position_x, position_y + 5));
			}
			workCounter = 8;
		}
		if (workCounter)				// 豌豆发射采用判断同行僵尸+倒计时制；
			workCounter--;				// 当倒计时为零且前方有僵尸，发射豌豆；开始新的倒计时；
		    							// 当倒计时为零且前方无僵尸，保持倒计时为零直到前方出现僵尸；
	}
}

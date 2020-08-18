#include "globalvariables-objects.h"

void close() {
	for (std::vector<Plant*>::iterator iter = plant.begin(); iter != plant.end(); iter++) {
		delete (*iter);
	}
	if (plantFollowMouse) {
		delete plantFollowMouse;
	}
	for (std::vector<Bullet*>::iterator iter = bullet.begin(); iter != bullet.end(); iter++) {
		delete (*iter);
	}
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); iter++) {
		delete (*iter);
	}
	for (std::vector<Car*>::iterator iter = car.begin(); iter != car.end(); iter++) {
		delete (*iter);
	}
}
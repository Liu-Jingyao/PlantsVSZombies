#include <graphics.h>
#include<stdio.h>
#include "Sun.h"
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include <typeinfo>
#include "globalvariables.h"
#include "BasicZombie.h"
#include "NewsPaperZombie.h"
#include "globalVariables-objects.h"
#pragma comment(lib,"Winmm.lib")

void updateZombies();
void updatePlants();
void updateCars();
void updateShots();
void bulletsHitZombies();
void zomiesEatPlants();
void playSound1();

// һ�ָ���ֻ����һ����Ч���Ա�Ǻ���������Ҫ���ŵ�����
bool has_hit = false;	// ��־���ָ����Ƿ����ӵ����н�ʬ
bool has_eat = false;	// ��־���ָ����Ƿ��н�ʬ��ֲ��

// �������޹صĸ���
void updateWithoutInput()
{
	has_hit = false;
	has_eat = false;

	// ����̫��
	Sun::getSun()->update();									

	// ���½�ʬ
	updateZombies();

	// ����ֲ��
	updatePlants();

	// ����С��
	updateCars();

	// �����ӵ�
	updateShots();

	// �ӵ���ʬ	
	bulletsHitZombies();

	// ��ʬ��ֲ��
	zomiesEatPlants();

	// ������Ч
	playSound1();

	// ��Ҫ���ӳ�
	Sleep(170);

	// �ж���Ϸʧ��
	if (zombie.empty()) {
		gameFlag = 1;
	}
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); ) {
		if ((*iter)->getPozition_x() < 0) {		// ������ʬ�����н�ʬԽ�����ߣ���ʬ��ʧ������Ѫ����һ
			Zombie::killNum++;
			delete (*iter);
			iter = zombie.erase(iter);
			Car::BaseHp--;
		} else {
			iter++;
		}
		if ((Zombie::killNum >= rankingList[9] && Car::BaseHp <= 0) ) {
			gameFlag = 1;
		}
		if (Zombie::killNum < rankingList[9] && Car::BaseHp <= 0) {
			gameFlag = -1;
		}
	}
	return;
}

void updateZombies() {
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); ) {
		(*iter)->update();													// �������½�ʬ����

		if ((*iter)->getHealthPoint() <= 0)									// �ж���ʬ�Ƿ����������������Ƴ���̬����
		{
			if ((*iter)->getType() == "BasicZombie") {
				Zombie::killNum++;
				delete (*iter);
				iter = zombie.erase(iter);
			}
			else {
				BasicZombie* newBody = new BasicZombie(1, 1, (*iter)->getPozition_x()+20, (*iter)->getPozition_y());
				if ((*iter)->getType() == "NewspaperZombie") {
					newBody->setSpeed_x(-5);
					newBody->setAttack(100);
				}
				delete (*iter);
				iter = zombie.erase(iter);
				zombie.push_back(newBody);
			}
		}
		else {
			iter++;
		}
	}
}
void updatePlants() {
	for (std::vector<Plant*>::iterator iter = plant.begin(); iter != plant.end();) {
		(*iter)->update();													 // ��������ֲ�����
		
		if ((*iter)->getHealthPoint() <= 0) {									 // �ж�ֲ���Ƿ񱻳Ե��������Ե����Ƴ���̬����
			map[((*iter)->getPozition_y() - PY) / sizehigh][((*iter)->getPozition_x() - PX) / sizewidth] = false;
			delete (*iter);
			iter = plant.erase(iter);
		}
		else {
			iter++;
		}
	}
	if (plantFollowMouse)													 // ���¸�������ֲ��
		plantFollowMouse->update();
}

void updateCars()
{
	for (std::vector<Car*>::iterator iter = car.begin(); iter != car.end();) {
		(*iter)->update();													 // ��������С������
		iter++;
	}
}

void updateShots() {
	for (std::vector<Bullet*>::iterator iter = bullet.begin(); iter != bullet.end(); ) {
		(*iter)->update();													  // ���������ӵ�����

		if ((*iter)->getPozition_x() > Width) {							  // �ж��ӵ��������������Ƴ���̬���飨��ʧ��
			delete (*iter);
			iter = bullet.erase(iter);
		}
		else {
			if ((*iter)->getbulletType() == 3)
			{
				(*iter)->setAttack((15 - Car::BaseHp) * 3 + 5);						//С��������ӵ������Ѫ�����ٹ�������ǿ
			}
			iter++;
		}
	}
}
void bulletsHitZombies() {
	// ������ʬ���ӵ��ж��ӵ����н�ʬ
	for (std::vector<Zombie *>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
		for (std::vector<Bullet *>::iterator iterB = bullet.begin(); iterB != bullet.end(); ) {
			// ���ӵ��ͽ�ʬͬһ�����ڻ��з�Χ������Ϊ����
			if (map_y.at((*iterB)->getPozition_y() - 5) == map_y.at((*iterZ)->getPozition_y()) && (*iterB)->getPozition_x() >= (*iterZ)->getPozition_x() + 35 && (*iterB)->getPozition_x() <= (*iterZ)->getPozition_x() + 100) {
				(*iterZ)->setHealthPoint((*iterZ)->getHealthPoint()-((*iterB)->getAttack()));	// ��ʬ��Ѫ
				if ((*iterB)->getbulletType() == 2)
				{
					(*iterZ)->setslowDown(1);
				}																				//���߼��������㶹���ٽ�ʬ
				delete (*iterB);															    // �ӵ��Ƴ���̬���飨��ʧ��
				iterB = bullet.erase(iterB);								
				has_hit = true;
			} else {
				iterB++;
			}
		}
	}
}

void zomiesEatPlants() {
	// ������ʬ��ֲ���ж���ʬ��ֲ��

	for (std::vector<Plant*>::iterator iterP = plant.begin(); iterP != plant.end(); iterP++) {
		for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
			if (map_y.at((*iterP)->getPozition_y()) == map_y.at((*iterZ)->getPozition_y()) && ((*iterZ)->getPozition_x() > (*iterP)->getPozition_x() + 10) && ((*iterZ)->getPozition_x() < (*iterP)->getPozition_x() + 30)) {
				has_eat = 1;
				(*iterZ)->setMoveStatus(0);														// ��ʬ��ֲ���ڼ䲻��
				(*iterP)->setHealthPoint((*iterP)->getHealthPoint() - ((*iterZ)->getAttack())); // ֲ���Ѫ 
			}
		}

		if ((*iterP)->getHealthPoint() <= 0) {													
			for (std::vector<Zombie*>::iterator iterZ = zombie.begin(); iterZ != zombie.end(); iterZ++) {
				if (map_y.at((*iterP)->getPozition_y()) == map_y.at((*iterZ)->getPozition_y()) && ((*iterZ)->getPozition_x() > (*iterP)->getPozition_x() + 10) && ((*iterZ)->getPozition_x() < (*iterP)->getPozition_x() + 30)) {											// ���Ե�����ʬ�ָ��ƶ�
						(*iterZ)->setMoveStatus(1);
				}
				
			}
		}
	}
}
void playSound1() {
	// ���ű��θ��µ���Ч����ҧ�������ڻ�����
	if (has_eat) {
		jpmusic1->close();
		jpmusic1 = &(Zombie::eatSound);
		jpmusic1->play();
	} else if (has_hit) {
		jpmusic1->close();
		jpmusic1 = &(Bullet::hitSound);
		jpmusic1->play();
	}
}
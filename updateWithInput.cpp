#include <graphics.h>
#include<stdio.h>
#include "Sun.h"
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include "PeaShooter.h"
#include "SunFlower.h"
#include "WallNut.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "GameScene.h"
#include "globalvariables.h"
#include "globalVariables-objects.h"

void selectPlant();
void plantPlant();
void giveupPlant();
void catchSun();
void playSound2();

// һ�ָ���ֻ����һ����Ч���Ա�Ǻ���������Ҫ���ŵ�����
bool has_select = false;		// ��־���ָ����Ƿ���ֲ�ﱻѡ��
bool has_plant = false;			// ��־���ָ����Ƿ���ֲ�ﱻ��ֲ
bool has_catch = false;			// ��־���ָ����Ƿ������ⱻ��׽

void updateWithInput() 
{
	has_select = false;
	has_plant = false;
	has_catch = false;

	while (MouseHit()) {					
		m = GetMouseMsg();
		if (m.uMsg != WM_LBUTTONDOWN) {				// �����Ч���������������
			continue;
		}

		// ��������̫������ʰȡ̫��
		if ((m.x >= Sun::getSun()->getPozition_x()) && (m.x < Sun::getSun()->getPozition_x() + 100) && (m.y > Sun::getSun()->getPozition_y()) && (m.y < Sun::getSun()->getPozition_y() + 100)) {
			catchSun();
			break;						// break��ֹ���غϵ�Ԫ�ر�һ���� 
		}

		// ��������ֲ������
		if ((m.x >= 95) && (m.x < 385) && (m.y >= 10) && (m.y < 80)) {
			if (!plantFollowMouse) {	// ����ǰû��ѡ��ֲ���ѡ��ֲ��
				selectPlant();
			}
			else {
				giveupPlant();			// ����ǰ�Ѿ�ѡ��ֲ����ֲ��Ż�ȥ
			}
			break;
		}

		// ����ǰ��ѡ��ֲ���ҵ���ڲ�ƺ�ڣ�����ֲֲ��
		if(plantFollowMouse && (m.x > PX + sizewidth * 0) && (m.x < PX + sizewidth * (size2 + 1)) && (m.y > PY + sizehigh * 0) && (m.y < PY + sizehigh * (size1 + 1))) {
			plantPlant();
			break;
		}
	}

	// ���ű��ָ�����Ч
	playSound2();
}

void selectPlant() {
	// ��ǰû��ѡ��ֲ�ѡ��ֲ��
	has_select = true;
	// ���㵽�㶹���ֿ�Ƭ��Ǯ�㹻
	if (sunshineNum >= PeaShooter::getPlantPrice() && (m.x >= 95) && (m.x < 145) && (m.y >= 10) && (m.y < 80)) {
		plantFollowMouse = new PeaShooter(0, 2, m.x - 30, m.y - 30);
	}
	// ���㵽���տ���Ƭ��Ǯ�㹻
	else if (sunshineNum >= SunFlower::getPlantPrice() && (m.x >= 155) && (m.x < 205) && (m.y >= 10) && (m.y < 80)) {
		plantFollowMouse = new SunFlower(0, 2,m.x - 30, m.y - 30);
	}
	else if (sunshineNum >= WallNut::getPlantPrice() && (m.x >= 215) && (m.x < 265) && (m.y >= 10) && (m.y < 80)) {
		plantFollowMouse = new WallNut(0, 2, m.x - 30, m.y - 30);
	}
	// ���㵽�������ֿ�Ƭ����Ǯ�㹻
	else if (sunshineNum >= SnowPea::getPlantPrice() && (m.x >= 275) && (m.x < 325) && (m.y >= 10) && (m.y < 80)) {
		plantFollowMouse = new SnowPea(0, 2, m.x - 30, m.y - 30);
	}
	// ���㵽ӣ��ը����Ƭ����Ǯ�㹻
	else if (sunshineNum >= CherryBomb::getPlantPrice() && (m.x >= 335) && (m.x < 385) && (m.y >= 10) && (m.y < 80)) {
		plantFollowMouse = new CherryBomb(0, 2, m.x - 30, m.y - 30);
	}
}

void plantPlant() {
	// ��ǰ����ѡ�е�ֲ�����ֲ��

	bool is_find = 0;													// �����û���ҵ���Ӧ�Ĳ�ƺ��
	for (int i = 0; i < size1 && !is_find; i++) {
		for (int j = 0; j < size2 && !is_find; j++) {
			if ((m.x > PX + sizewidth * j) && (m.x < PX + sizewidth * (j + 1)) && (m.y > PY + sizehigh * i) && (m.y < PY + sizehigh * (i + 1))) {
				// ���ҵ���Ӧ�Ĳ�ƺ�飬�����ֲ��
				if (!map[i][j]) {
					plantFollowMouse->setPozition_x(PX + sizewidth * j);	// �趨x����
					plantFollowMouse->setPozition_y(PY + sizehigh * i);		// �趨y����
					plantFollowMouse->setMoveStatus(0);					// �趨�˶�״̬Ϊ��ֹ
					plantFollowMouse->setAnimationStatus(1);				// �趨����״̬Ϊ��̬
					plant.push_back(plantFollowMouse);						// ����ֲ�ﶯ̬����
					sunshineNum = sunshineNum - plantFollowMouse->getPrice();			// ������Ӧ������

					map[i][j] = true;
					has_plant = true;
					is_find = 1;
					plantFollowMouse = NULL;								// plantFollowMouse�л�Ϊδѡ��ֲ��ⲽ����Ҫ��
				}
				
			}
		}
	}
}

void catchSun() {
	//����̫����̫���������ɣ�������50
	has_catch = true;
	Sun::getSun()->setPozition_x(rand() % (Width - 100)) ;
	Sun::getSun()->setPozition_y(-400);
	sunshineNum = sunshineNum + 50;
}

void giveupPlant() { // ������ֲ
	plantFollowMouse = NULL;
}

void playSound2() {
	if (has_select) {
		jpmusic2->close();
		jpmusic2 = &(GameScene::getGameScene()->clickCardSound);
		jpmusic2->play();
	}
	else if (has_plant) {
		jpmusic2->close();
		jpmusic2 = &(Plant::plantSound);
		jpmusic2->play();
	}
	else if (has_catch) {
		jpmusic2->close();
		jpmusic2 = &(Sun::catchSound);
		jpmusic2->play();
	}
}
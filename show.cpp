#include <graphics.h>
#include<stdio.h>
#include "Sun.h"
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "StartScene.h"
#include "GameScene.h"
#include "LoseScene.h"
#include "WinScene.h"
#include "globalvariables.h"
#include "globalVariables-objects.h"

// ������ʾ����
void show()
{
	GameScene::getGameScene()->RunScene();	// ������Ϸ����

	for (std::vector<Plant *>::iterator iter = plant.begin(); iter != plant.end(); iter++)
		(*iter)->show();					// ������ʾ����ֲ��
	if(plantFollowMouse) plantFollowMouse->show();

	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); iter++)
		(*iter)->show();					// ������ʾ���н�ʬ

	for (std::vector<Bullet *>::iterator iter = bullet.begin(); iter != bullet.end(); iter++)
		(*iter)->show();					// ������ʾ�����ӵ�

	for (std::vector<Car*>::iterator iter = car.begin(); iter != car.end(); iter++)
		(*iter)->show();					// ������ʾ����С��

	Sun::getSun()->show();					// ��ʾ̫��

	{										// ��ʾ��������������
	outtextxy(30, 65, stringToTCHAR(std::to_string(sunshineNum)));
 	outtextxy(690, 30, stringToTCHAR(std::to_string(Car::BaseHp))); 
	}

	FlushBatchDraw();					    // ������Ԫ��ͬʱ�����ڴ�����
}
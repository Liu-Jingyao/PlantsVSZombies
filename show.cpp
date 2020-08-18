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

// 画面显示函数
void show()
{
	GameScene::getGameScene()->RunScene();	// 运行游戏界面

	for (std::vector<Plant *>::iterator iter = plant.begin(); iter != plant.end(); iter++)
		(*iter)->show();					// 遍历显示所有植物
	if(plantFollowMouse) plantFollowMouse->show();

	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); iter++)
		(*iter)->show();					// 遍历显示所有僵尸

	for (std::vector<Bullet *>::iterator iter = bullet.begin(); iter != bullet.end(); iter++)
		(*iter)->show();					// 遍历显示所有子弹

	for (std::vector<Car*>::iterator iter = car.begin(); iter != car.end(); iter++)
		(*iter)->show();					// 遍历显示所有小车

	Sun::getSun()->show();					// 显示太阳

	{										// 显示阳光数、敌人数
	outtextxy(30, 65, stringToTCHAR(std::to_string(sunshineNum)));
 	outtextxy(690, 30, stringToTCHAR(std::to_string(Car::BaseHp))); 
	}

	FlushBatchDraw();					    // 将以上元素同时绘制在窗口上
}
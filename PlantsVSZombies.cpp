#include <graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include "globalvariables.h"
#include "globalVariables-objects.h"
#include "StartScene.h"
#include "GameScene.h"
#include "LoseScene.h"
#include "WinScene.h"

#pragma comment(lib,"Winmm.lib")

extern void startup();                  
extern void show();								
extern void updateWithoutInput();
extern void updateWithInput();
extern void close();
extern void writeRankingList(int score);
extern void debugMode();

int main()
{

	startup();									// 全局变量初始化

	StartScene::getStartScene()->RunScene();    // 运行欢迎界面

	debugMode();

	// 每轮更新约170ms
	while (!gameFlag) {							// 判断游戏是否结束
		show();								    // 显示画面
		updateWithoutInput();					// 与输入无关的更新
		updateWithInput();				    	// 与输入有关的更新
	}

	close();									// 释放占用内存

	GameScene::getGameScene()->closeBGM();		// 关闭游戏音乐

	writeRankingList(Zombie::killNum);

	if (gameFlag == -1) {						// 运行结果画面
		LoseScene::getLoseScene()->RunScene();
	} else {
		WinScene::getWinScene()->RunScene();
	}

	return 0;
}


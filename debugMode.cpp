#include <graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "BasicZombie.h"
#include "globalvariables.h"
#include "globalVariables-objects.h"
#include "StartScene.h"
#include "GameScene.h"
#include "LoseScene.h"
#include "WinScene.h"

void debugMode() {
	sunshineNum = 100000;
	for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end(); iter++) {
		(*iter)->setSpeed_x(-20);
	}
}
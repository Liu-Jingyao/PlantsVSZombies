#pragma once

/*
 *  全局对象声明头文件
 *  文件名：globalVariables-objects.h
 *  相关文件：startup.cpp
 */

#include <vector>
#include "Sound.h"
#include "Plant.h"
#include "Scene.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Car.h"
#pragma comment(lib,"Winmm.lib")

extern const Sound* jpmusic1;                        // updateWithOutInput上一次播放的音乐
extern const Sound* jpmusic2;                        // updateWithInput上一次播放的音乐

extern std::vector<Zombie *>zombie;                  // 僵尸动态数组
extern std::vector<Bullet*>bullet;                   // 子弹动态数组
extern std::vector<Plant *>plant;                    // 植物指针动态数组
extern std::vector<Car*>car;						 //小车指针动态数组

extern Plant* plantFollowMouse;                      // 跟随鼠标移动的植物，为NULL时表示当前没有植物被选中
#pragma once

/*
 *  ȫ�ֶ�������ͷ�ļ�
 *  �ļ�����globalVariables-objects.h
 *  ����ļ���startup.cpp
 */

#include <vector>
#include "Sound.h"
#include "Plant.h"
#include "Scene.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Car.h"
#pragma comment(lib,"Winmm.lib")

extern const Sound* jpmusic1;                        // updateWithOutInput��һ�β��ŵ�����
extern const Sound* jpmusic2;                        // updateWithInput��һ�β��ŵ�����

extern std::vector<Zombie *>zombie;                  // ��ʬ��̬����
extern std::vector<Bullet*>bullet;                   // �ӵ���̬����
extern std::vector<Plant *>plant;                    // ֲ��ָ�붯̬����
extern std::vector<Car*>car;						 //С��ָ�붯̬����

extern Plant* plantFollowMouse;                      // ��������ƶ���ֲ�ΪNULLʱ��ʾ��ǰû��ֲ�ﱻѡ��
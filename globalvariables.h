#pragma once

/*  
 *  ȫ�ֱ�������ͷ�ļ�
 *  �ļ�����globalVariables.h
 *  ����ļ���startup.cpp
 */


#include <map>
#include <vector>
#include <graphics.h>
#include<conio.h>
#include <string>

#define Carnum  5//С����
#define plantnum 20//ֲ����
#define Zombienum 18//��ʬ��
#define sizewidth 80 //�����ƺ�ߴ�
#define sizehigh 100 
#define size1 5		//��ƺ����
#define size2 9
#define PY 85//��ƫ����
#define PX 45//��ƫ����
#define High 600 // ��Ϸ����ߴ�
#define Width 800


extern bool map[5][9];
extern int rankingList[11];
extern int sunshineNum;                      // ������
extern int gameFlag ;                   // ��Ϸ״̬��-1Ϊ�䡢0Ϊ��Ϸ�С�1ΪӮ
extern int zombie_x[Zombienum];         // ԭ�����и���ʬ��ʼλ��
extern int zombie_y[Zombienum]; 
extern MOUSEMSG m;

extern std::map<int, int> map_x;        // ֲ���x����->��ƺ���� ��ӳ��
extern std::map<int, int> map_y;        // ֲ��/��ʬ��y����->��ƺ����  ��ӳ��
extern const TCHAR* stringToTCHAR(const std::string& str);
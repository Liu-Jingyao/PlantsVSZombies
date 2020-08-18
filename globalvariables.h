#pragma once

/*  
 *  全局变量声明头文件
 *  文件名：globalVariables.h
 *  相关文件：startup.cpp
 */


#include <map>
#include <vector>
#include <graphics.h>
#include<conio.h>
#include <string>

#define Carnum  5//小车数
#define plantnum 20//植物数
#define Zombienum 18//僵尸数
#define sizewidth 80 //单块草坪尺寸
#define sizehigh 100 
#define size1 5		//草坪块数
#define size2 9
#define PY 85//上偏移量
#define PX 45//左偏移量
#define High 600 // 游戏画面尺寸
#define Width 800


extern bool map[5][9];
extern int rankingList[11];
extern int sunshineNum;                      // 阳光数
extern int gameFlag ;                   // 游戏状态：-1为输、0为游戏中、1为赢
extern int zombie_x[Zombienum];         // 原代码中各僵尸初始位置
extern int zombie_y[Zombienum]; 
extern MOUSEMSG m;

extern std::map<int, int> map_x;        // 植物的x坐标->草坪列数 的映射
extern std::map<int, int> map_y;        // 植物/僵尸的y坐标->草坪行数  的映射
extern const TCHAR* stringToTCHAR(const std::string& str);
#pragma once
#include"globalvariables.h"
#include<conio.h>
#include <graphics.h>
#include "Image.h"
#include "Sound.h"
#include "Object.h"
#pragma comment(lib,"Winmm.lib")

/*
 *  Sun 太阳类声明
 *  文件名：Sun.h
 *  相关文件：Sun.cpp
 */

class Sun : public Object
{
public:
	static Sun* getSun();		// 单例设计：场景中只有一个太阳
	static const Sound catchSound;
	void update();				// 太阳坐标更新
	void show();				    // 太阳显示
private: 
	Sun();
	static Image img_sun;		// 太阳贴图
	static Image img_sun1;		// 太阳贴图遮罩层
	int sun_v;
};


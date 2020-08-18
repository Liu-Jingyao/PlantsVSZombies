#pragma once
#include"globalvariables.h"
#include<conio.h>
#include <graphics.h>
#include "Image.h"
#include "Sound.h"
#include "Object.h"
#pragma comment(lib,"Winmm.lib")

/*
 *  Sun ̫��������
 *  �ļ�����Sun.h
 *  ����ļ���Sun.cpp
 */

class Sun : public Object
{
public:
	static Sun* getSun();		// ������ƣ�������ֻ��һ��̫��
	static const Sound catchSound;
	void update();				// ̫���������
	void show();				    // ̫����ʾ
private: 
	Sun();
	static Image img_sun;		// ̫����ͼ
	static Image img_sun1;		// ̫����ͼ���ֲ�
	int sun_v;
};


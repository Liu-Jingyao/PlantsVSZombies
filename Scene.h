#pragma once
#include "globalvariables.h"
#include<conio.h>
#include <graphics.h>
#include "Image.h"
#include "Sound.h"
#include <string>
#pragma comment(lib,"Winmm.lib")

/*
 *  Scene �����������
 *  �ļ�����Scene.h
 *  ����ļ���Scene.cpp, *Scene.h
 */

class Scene  
{
    public:
        Scene(const std::string& bk, const std::string& mc);
        virtual ~Scene()=0;
        virtual void RunScene() const = 0;   
    protected:
        Image background;                       //����ͼƬ
        const Sound BGM;                              //BGM
};


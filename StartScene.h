#pragma once
#include "Scene.h"

/*
 *  StartScene ʧ�ܽ���������
 *  �ļ�����StartScene.h
 *  ����ļ���Scene.h, StartScene.cpp
 */
class StartScene :public Scene 
{
public:
	static const StartScene* getStartScene();
	virtual void RunScene() const;
	virtual ~StartScene();
private:
	StartScene();
};


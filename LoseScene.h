#pragma once
#include "Scene.h"

/*
 *  LoseScene ʧ�ܽ���������
 *  �ļ�����LoseScene.h
 *  ����ļ���Scene.h, LoseScene.cpp
 */
class LoseScene :public Scene
{
public:
	static const LoseScene* getLoseScene();
	virtual void RunScene() const;
	virtual ~LoseScene();
private:
	LoseScene();
};


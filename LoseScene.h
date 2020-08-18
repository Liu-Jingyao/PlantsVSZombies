#pragma once
#include "Scene.h"

/*
 *  LoseScene 失败界面类声明
 *  文件名：LoseScene.h
 *  相关文件：Scene.h, LoseScene.cpp
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


#pragma once
#include "Scene.h"

/*
 *  StartScene 失败界面类声明
 *  文件名：StartScene.h
 *  相关文件：Scene.h, StartScene.cpp
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


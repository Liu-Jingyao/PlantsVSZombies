#pragma once
#include "Scene.h"
#include <string>

/*
 *  GameScene 游戏场景类声明
 *  文件名：GameScene.h
 *  相关文件：Scene.h, GameScene.cpp
 */
class GameScene :public Scene
{
public:
	// 单例设计，隐藏构造函数；
	// 外部只能使用get函数调用一个内部定义的静态对象，从而保证了保证此类有且仅有有一个对象。
	void closeBGM() const;
	static const Sound clickCardSound;
	static const GameScene* getGameScene();
	virtual void RunScene() const;
	virtual ~GameScene();
protected:
	GameScene();
	Image kuang;			//植物栏
	Image jiangshitupian;	//“基地血量”图片
	Image shootercard;		//射手卡片
	Image flowercard;		//向日葵卡片
	Image nutcard;			//坚果卡片
	Image snowpea;			//寒冰射手卡片
	Image cherrybomb;		//樱桃炸弹卡片
};


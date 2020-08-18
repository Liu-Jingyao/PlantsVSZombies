#pragma once
#include "Scene.h"
#include <string>

/*
 *  GameScene ��Ϸ����������
 *  �ļ�����GameScene.h
 *  ����ļ���Scene.h, GameScene.cpp
 */
class GameScene :public Scene
{
public:
	// ������ƣ����ع��캯����
	// �ⲿֻ��ʹ��get��������һ���ڲ�����ľ�̬���󣬴Ӷ���֤�˱�֤�������ҽ�����һ������
	void closeBGM() const;
	static const Sound clickCardSound;
	static const GameScene* getGameScene();
	virtual void RunScene() const;
	virtual ~GameScene();
protected:
	GameScene();
	Image kuang;			//ֲ����
	Image jiangshitupian;	//������Ѫ����ͼƬ
	Image shootercard;		//���ֿ�Ƭ
	Image flowercard;		//���տ���Ƭ
	Image nutcard;			//�����Ƭ
	Image snowpea;			//�������ֿ�Ƭ
	Image cherrybomb;		//ӣ��ը����Ƭ
};


#include "GameScene.h"

const Sound GameScene::clickCardSound(std::string("Clickcard.mp3"));

const GameScene* GameScene::getGameScene()
{
	static const GameScene instance;
	return &instance;
}

void GameScene::closeBGM() const
{ 
	BGM.close();
}

GameScene::GameScene() :Scene("lawn.jpg", "playing.mp3")
, shootercard("card//PeaShooterCard.jpg")
, flowercard("card//SunFlowerCard.jpg")
, nutcard("card//WALLnUTcARD.png")
, kuang("kuang.png")
, jiangshitupian("ZombiesRemaining.jpg")
, snowpea("card//snowShooterCard.png")
, cherrybomb("card//CherryBomb.png")
{
}

void GameScene::RunScene() const	// ������Ϸ����
{									
		background.put(0, 0);		// ��ʾ��Ϸ����
		BGM.playRepeatedly();		// ������Ϸ����
		kuang.put(0, 0);			// ��ʾֲ����
		jiangshitupian.put(590, 0); // ��ʾ��ʣ�ཀྵʬ����
		shootercard.put(95, 10);	// ��ʾ���ֿ�Ƭ
		flowercard.put(155, 10);	// ��ʾ���տ���Ƭ
		nutcard.put(215, 10);
		snowpea.put(275, 10);		// ��ʾ�������ֿ�Ƭ
		cherrybomb.put(335, 10);	// ��ʾӣ��ը����Ƭ
}

GameScene::~GameScene()
{
}



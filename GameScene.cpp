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

void GameScene::RunScene() const	// 运行游戏界面
{									
		background.put(0, 0);		// 显示游戏画面
		BGM.playRepeatedly();		// 播放游戏音乐
		kuang.put(0, 0);			// 显示植物栏
		jiangshitupian.put(590, 0); // 显示“剩余僵尸数”
		shootercard.put(95, 10);	// 显示射手卡片
		flowercard.put(155, 10);	// 显示向日葵卡片
		nutcard.put(215, 10);
		snowpea.put(275, 10);		// 显示寒冰射手卡片
		cherrybomb.put(335, 10);	// 显示樱桃炸弹卡片
}

GameScene::~GameScene()
{
}



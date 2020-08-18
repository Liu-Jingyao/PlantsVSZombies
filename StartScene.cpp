#include "StartScene.h"

const StartScene* StartScene::getStartScene() {
	static const StartScene instance;
	return &instance;
}

StartScene::StartScene():Scene("startScene.jpg", "StartMusic.mp3"){
}

void StartScene::RunScene() const {			
	// œ‘ æª∂”≠ΩÁ√ÊÕº∆¨
	background.put(0, 0);
	outtextxy(30, 65, _T("≈≈––∞Ò"));
	for (int i = 0; i < 10; i++) {
		outtextxy(30, 65+(i+1)*20, stringToTCHAR(std::to_string(rankingList[i])));
	}
	FlushBatchDraw();					   

	// ≤•∑≈±≥æ∞“Ù¿÷
	BGM.playRepeatedly();

	do {
		m = GetMouseMsg(); 
	} while (m.uMsg != WM_LBUTTONDOWN);		//ºÏ≤‚ Û±Í◊Ûº¸µ„ª˜

	BGM.close();							//πÿ±’BGM
}

StartScene::~StartScene()
{
}

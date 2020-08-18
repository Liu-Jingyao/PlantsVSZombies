#include "LoseScene.h"

const LoseScene* LoseScene::getLoseScene() {
	static const LoseScene instance;
	return &instance;
}

LoseScene::LoseScene() :Scene("lose.jpg", "lose.mp3") {
}

void LoseScene::RunScene() const {	
	background.put(0, 0);
	outtextxy(300, 300, _T("µ√∑÷Œ¥…œ∞Ò£°"));
	BGM.play();
	FlushBatchDraw();
	system("pause");
}

LoseScene::~LoseScene()
{
}

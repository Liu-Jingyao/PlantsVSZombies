#include "WinScene.h"

const WinScene* WinScene::getWinScene() {
	static const WinScene instance;
	return &instance;
}

WinScene::WinScene() :Scene("win.jpg", "win.mp3") {
}

void WinScene::RunScene() const {
	background.put(0, 0);
	outtextxy(300, 300, _T("µ√∑÷…œ∞Ò£¨πßœ≤£°"));
	BGM.play();
	FlushBatchDraw();
	system("pause");
}

WinScene::~WinScene()
{
}
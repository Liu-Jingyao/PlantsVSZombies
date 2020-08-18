#include "StartScene.h"

const StartScene* StartScene::getStartScene() {
	static const StartScene instance;
	return &instance;
}

StartScene::StartScene():Scene("startScene.jpg", "StartMusic.mp3"){
}

void StartScene::RunScene() const {			
	// ��ʾ��ӭ����ͼƬ
	background.put(0, 0);
	outtextxy(30, 65, _T("���а�"));
	for (int i = 0; i < 10; i++) {
		outtextxy(30, 65+(i+1)*20, stringToTCHAR(std::to_string(rankingList[i])));
	}
	FlushBatchDraw();					   

	// ���ű�������
	BGM.playRepeatedly();

	do {
		m = GetMouseMsg(); 
	} while (m.uMsg != WM_LBUTTONDOWN);		//������������

	BGM.close();							//�ر�BGM
}

StartScene::~StartScene()
{
}

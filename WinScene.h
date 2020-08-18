#pragma once
#include "Scene.h"
class WinScene :public Scene
{
public:
	static const WinScene* getWinScene();
	virtual void RunScene() const;
	virtual ~WinScene();
private:
	WinScene();
};


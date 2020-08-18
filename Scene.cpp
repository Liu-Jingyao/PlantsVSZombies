#include "Scene.h"

Scene::Scene(const std::string& bk, const std::string& mc):background(bk),BGM(mc)
{
}

Scene::~Scene() {}		//纯虚析构函数在基类也要实现


#pragma once
#include <vector>
#include <string>
#include "Image.h"
#pragma comment(lib,"Winmm.lib")

/*
模块名 : 动画类
文件名 : Animation.h
相关文件 : Animation.cpp
文件实现功能 :作为植物、僵尸类的基类，存放动画帧图，对外提供自动更新、显示动画帧图的功能。
用法示例：
		class Plant : public Object, public Movable, public Animation 
		{
			...
			void show() {
				Animation::show(position_x, position_y);
			}
		}

		class PeaShooter : public Plant
		{
			PeaShooter(...)...{
				loadImages（"Plant\\PeaShooter\\", 12）；
			}

		}
注意事项：	请在最下一级子类（如向日葵类）的构造函数中调用loadAnimation
			请注意path参数的格式，如豌豆射手动画路径为"images\\Plant\\PeaShooter\\1.jpg"...
			则path应填写"Plant\\PeaShooter\\"
*/

class Animation
{
public:
	int getAnimationStatus() const;			    // 动画状态的get、set函数
	void setAnimationStatus(int animationStatus);
	void randomAnimation();
protected:

	Animation(int s = 0, bool png = 0);			// 初始化函数，入参为动画状态和“是否为png格式”
	void animationUpdate();					    // 动画更新，可自动区分静态/动态
	int animationStatus = 0;					// 动画状态，0 静态，1 动态
	std::vector<Image> Images;					// 动画帧vector
	std::vector<Image> BackImages;				// 遮罩帧vector
	std::vector<Image>::iterator ImageIter;		// 动画迭代器
	std::vector<Image>::iterator BackImageIter;	// 动画遮罩层迭代器
	bool is_loadItertor = 0;					// 是否已加载迭代器
	bool is_loadAnimation = 0;					// 是否已加载动画
	bool is_png;								//! 动画是否为png格式

	void loadAnimation(const std::string& path, int n, bool png = 0); // 动画数组加载
	void play(int x, int y);				    // 动画显示函数，被子类无参show函数包含，由子类提供坐标
};

#include "Animation.h"
#include <ctime>

Animation::Animation(int s, bool png):animationStatus(s),is_png(png)
{
}

void Animation::animationUpdate()
{
	if (!is_loadItertor) {
		ImageIter = Images.begin();
		if (!is_png) BackImageIter = BackImages.begin();
		is_loadItertor = 1;
	}

	ImageIter++;
	if (!is_png) BackImageIter++;
	if (ImageIter == Images.end()) {
		ImageIter = Images.begin();
		BackImageIter = BackImages.begin();
	}
}

void Animation::play(int x, int y)
{
	if (!is_loadItertor) {
		ImageIter = Images.begin();
		if(!is_png) BackImageIter = BackImages.begin();
		is_loadItertor = 1;
	}

	if (!is_png){
		switch (animationStatus) {
		case 0:
			BackImages.begin()->put(x, y, NOTSRCERASE);
			Images.begin()->put(x, y, SRCINVERT);
			break;
		case 1:
			BackImageIter->put(x, y, NOTSRCERASE);
			ImageIter->put(x, y, SRCINVERT);
			break;
		}
	} else {
		switch (animationStatus) {
		case 0:
			Images.begin()->put(x, y);
			break;
		case 1:
			ImageIter->put(x, y);
			break;
		}
	}
	
}

// ! path是images文件夹下的相对路径
void Animation::loadAnimation(const std::string& path, int n, bool png)
{
	is_png = png;
	if (!is_loadAnimation) {														// 加载图片，只加载一次
		if (!is_png) {
			for (int i = 0; i < n; i++) {
				//自动填写图片名
				Images.push_back(Image(path + std::to_string(i + 1) + ".jpg"));
				BackImages.push_back(Image(path + std::to_string(i + 1) + "_bk.jpg"));
			}
		} else {
			for (int i = 0; i < n; i++) {
				//自动填写图片名
				Images.push_back(Image(path + std::to_string(i + 1) + ".png"));
			}
		}
		is_loadAnimation = 1;
	}
}


int Animation::getAnimationStatus() const
{
    return animationStatus;
}

void Animation::setAnimationStatus(int animationStatus)
{
    this->animationStatus = animationStatus;
}

void Animation::randomAnimation()
{
	if (!is_loadItertor) {
		ImageIter = Images.begin();
		if (!is_png) BackImageIter = BackImages.begin();
		is_loadItertor = 1;
	}
	srand((unsigned)time(0));
	int r = rand() % 20;
	for (int i = 0; i < r; i++) {
		ImageIter++;
		if (!is_png) BackImageIter++;
		if (ImageIter == Images.end()) {
			ImageIter = Images.begin();
			BackImageIter = BackImages.begin();
		}
	}
}



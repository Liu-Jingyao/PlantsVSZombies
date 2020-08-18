#pragma once
#include<conio.h>
#include <graphics.h>
#include <string>
#pragma comment(lib,"Winmm.lib")

// 声音类，用声音文件名初始化，封装了声音的打开、播放、循环播放、关闭功能

extern const TCHAR* stringToTCHAR(const std::string& str);

class Sound
{
public:
	Sound(const std::string &name);
	void play() const;
	void playRepeatedly() const;
	void close() const;
private:
	std::string soundName;
};


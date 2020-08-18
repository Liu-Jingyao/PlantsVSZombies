#pragma once
#include<conio.h>
#include <graphics.h>
#include <string>
#pragma comment(lib,"Winmm.lib")

// �����࣬�������ļ�����ʼ������װ�������Ĵ򿪡����š�ѭ�����š��رչ���

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


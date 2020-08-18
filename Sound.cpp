#include "Sound.h"

Sound::Sound(const std::string& name):soundName(name)
{
	
}

void Sound::play() const
{
	mciSendString(stringToTCHAR(("open musics/" + soundName)), NULL, 0, 0); //ע�������ļ�����musicsĿ¼��
	mciSendString(stringToTCHAR("play musics/" + soundName), NULL, 0, 0);
}

void Sound::playRepeatedly() const
{
	mciSendString(stringToTCHAR("open musics/" + soundName), NULL, 0, 0); //ע�������ļ�����musicsĿ¼��
	mciSendString(stringToTCHAR("play musics/" + soundName + " repeat"), NULL, 0, 0);
}

void Sound::close() const
{
	mciSendString(stringToTCHAR("stop musics/" + soundName), NULL, 0, 0);
	mciSendString(stringToTCHAR("close musics/" + soundName), NULL, 0, 0);
}

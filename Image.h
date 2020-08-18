#pragma once
#include<conio.h>
#include <graphics.h>
#include <string>
#include <map>
#pragma comment(lib,"Winmm.lib")

// ͼƬ�࣬��ͼƬ�ļ�����ʼ������װ��IMAGE���load, put����
// ��֮ǰ�İ汾�����˸Ľ�

extern const TCHAR* stringToTCHAR(const std::string& str);

class Image
{
public:
	Image();
	Image (const std::string &name);
	Image(const char name[]);
	Image(const Image& other);
	~Image();
	void put (int x, int y) const;
	void put (int x, int y, const DWORD& t) const;
	void setName(const std::string& name);
	void load();
	Image & operator= (const Image& other);
	std::string getType() const;
private:
	std::string imageName = "\0";
	IMAGE* pimage;
	bool loadFlag = 0;
	void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg) const;
	std::string type;
};


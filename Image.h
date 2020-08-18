#pragma once
#include<conio.h>
#include <graphics.h>
#include <string>
#include <map>
#pragma comment(lib,"Winmm.lib")

// 图片类，用图片文件名初始化，封装了IMAGE类的load, put函数
// 对之前的版本做出了改进

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


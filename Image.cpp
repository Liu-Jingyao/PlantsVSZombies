#include "Image.h"

Image::Image()
{
	pimage = new IMAGE();
}

Image::Image(const std::string& name):imageName(name){
	pimage = new IMAGE();
	load();
}

Image::Image(const char name[]):imageName(name)
{
	pimage = new IMAGE();
	load();
}

Image::Image(const Image& other)
{
	pimage = new IMAGE();
	if (this == &other || other.imageName == "\0") {
		return;
	}
	imageName = other.imageName;
	load();
}

Image::~Image()
{
	delete pimage;
}

void Image::put(int x, int y) const
{
	if (type == "jpg")
		putimage(x, y, pimage);
	if (type == "png")
		transparentimage(NULL, x, y, pimage);
}

void Image::put(int x, int y, const DWORD& t) const
{
	putimage(x, y, pimage, t);
}

void Image::setName(const std::string& name)
{
	imageName = name;
	load();
}

void Image::load()
{
	type = imageName.substr(imageName.length() - 3, 3);
	if (!loadFlag) {
		loadimage(pimage, stringToTCHAR("images\\" + imageName));
		loadFlag = 1;
	}
}

Image& Image::operator=(const Image& other)
{
	if (this == &other || other.imageName == "\0") {
		return *this;
	}
	imageName = other.imageName;
	load();
	return *this;
}

std::string Image::getType() const
{
	return type;
}

void Image::transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg) const
{
	// 变量初始化
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// 处理超出下边界
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// 处理超出左边界
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// 处理超出上边界

	// 修正贴图起始位置
	dst += dst_width * y + x;

	// 实现透明贴图
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// 源值已经乘过了透明系数
			int sg = ((src[ix] & 0xff00) >> 8);		// 源值已经乘过了透明系数
			int sb = src[ix] & 0xff;				// 源值已经乘过了透明系数
			int dr = ((dst[ix] & 0xff0000) >> 16);
			int dg = ((dst[ix] & 0xff00) >> 8);
			int db = dst[ix] & 0xff;

			dst[ix] = ((sr + dr * (255 - sa) / 255) << 16)
				| ((sg + dg * (255 - sa) / 255) << 8)
				| (sb + db * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}



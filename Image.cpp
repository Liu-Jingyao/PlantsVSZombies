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
	// ������ʼ��
	DWORD* dst = GetImageBuffer(dstimg);
	DWORD* src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth());
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());

	// ������ͼ��ʵ�ʳ���
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width;		// �������ұ߽�
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height;	// �������±߽�
	if (x < 0) { src += -x;				iwidth -= -x;	x = 0; }				// ��������߽�
	if (y < 0) { src += src_width * -y;	iheight -= -y;	y = 0; }				// �������ϱ߽�

	// ������ͼ��ʼλ��
	dst += dst_width * y + x;

	// ʵ��͸����ͼ
	for (int iy = 0; iy < iheight; iy++)
	{
		for (int ix = 0; ix < iwidth; ix++)
		{
			int sa = ((src[ix] & 0xff000000) >> 24);
			int sr = ((src[ix] & 0xff0000) >> 16);	// Դֵ�Ѿ��˹���͸��ϵ��
			int sg = ((src[ix] & 0xff00) >> 8);		// Դֵ�Ѿ��˹���͸��ϵ��
			int sb = src[ix] & 0xff;				// Դֵ�Ѿ��˹���͸��ϵ��
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



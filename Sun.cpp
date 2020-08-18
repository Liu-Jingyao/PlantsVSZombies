#include "Sun.h"

const Sound Sun::catchSound("ClickSun.mp3");
Image Sun::img_sun;
Image Sun::img_sun1;

Sun* Sun::getSun()
{
	static Sun instance;
	return &instance;
}
void Sun::update()
{
	position_y = position_y + sun_v;
	if (Sun::getSun()->position_y > 700)//太阳出框，重新生成
	{
		Sun::getSun()->position_x = rand() % (Width - 100);
		Sun::getSun()->position_y = -200;
	}
}
void Sun::show()
{
	img_sun.put(position_x, position_y, NOTSRCERASE);
	img_sun1.put(position_x, position_y, SRCINVERT);
}
Sun::Sun() :Object(400,0),sun_v(5) {
	img_sun1.setName("Sun.jpg");
	img_sun.setName("Sun_bk.jpg");
}

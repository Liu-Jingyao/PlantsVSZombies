#include "CherryBomb.h"
#include "globalVariables.h"
#include "globalVariables-objects.h"

const Sound CherryBomb::bombSound("BombVoice.mp3");
const int CherryBomb::plantPrice = 150;


CherryBomb::CherryBomb(int as, int ms, int po_x, int po_y) :Plant(as, ms, po_x, po_y, 300, 150)
{
	Animation::loadAnimation("Plant\\CherryBomb\\", 9,true);					//º”‘ÿ”£Ã“’®µØÕº∆¨
}

CherryBomb::~CherryBomb()
{
}

void CherryBomb::update()
{
	Plant::update();

	if (moveStatus==0 && animationStatus==1)
	{
		workCounter--;							//◊º±∏
		if (workCounter == -4) {
			bombSound.close();
		}
		if (workCounter==-5) 
		{
			bombSound.play();
			healthPoint = 0;											//”£Ã“’®µØ—™¡ø÷√Œ™0
			for (std::vector<Zombie*>::iterator iter = zombie.begin(); iter != zombie.end();) 
			{
				if ( ( (*iter)->getPozition_x()- this->getPozition_x() )<= 120 &&  ( (*iter)->getPozition_x()- this->getPozition_x()) >= -120 &&  ( (*iter)->getPozition_y()- this->getPozition_y() ) <= 150 && ( (*iter)->getPozition_y()- this->getPozition_y( )) >= - 150)
				{
					Zombie::killNum++;
					delete (*iter);
					iter = zombie.erase(iter);
				} else {
					iter++;
				}
			}
		}
	}
}

int CherryBomb::getPlantPrice() {
	return plantPrice;
}

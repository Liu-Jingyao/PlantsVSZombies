#include "globalVariables.h"
#include "globalVariables-objects.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "BasicZombie.h"
#include "BucketheadZombie.h"
#include "NewspaperZombie.h"

// ȫ�ֱ�����ȫ�ֶ����壨ע�ͼ�����ȫ�ֱ���ͷ�ļ���
bool map[5][9];
int sunshineNum = 100;		
int gameFlag = 0;	
int zombie_x[Zombienum] = { 800,1300,1500,2000,2100,2500,2800,3300,3400,3600,3500,3700,3550,3800,3900,3500,3700,3600 };
int zombie_y[Zombienum] = { 80,150,250,80,350,450,150,250,450,350,80,250,150,350,450,250,350,450 };  // ��ʬλ��
int car_x[Carnum] = { 1,1,1,1,1 };
int car_y[Carnum] = { 85,185,285,385,485 };
std::vector<Zombie *>zombie;
std::vector<Bullet *>bullet;
std::vector<Plant*> plant;
std::vector<Car*> car;
std::map<int, int> map_x;
std::map<int, int> map_y;
Plant* plantFollowMouse = NULL;
MOUSEMSG m;
const Sound* jpmusic1 = &(Bullet::hitSound);
const Sound* jpmusic2 = &(Bullet::hitSound);

extern void loadRankingList();

// ȫ�ֱ�����ȫ�ֶ����ʼ��
void startup() {

	memset(map, 0, sizeof(map));

	loadRankingList();

	// ��ʬװ�뽩ʬָ������
	zombie.push_back(new BasicZombie(1, 1, zombie_x[0], zombie_y[0]));
	for (int i = 0; i < Zombienum; i++) {
		Zombie* tmp;
		if (i < 12) {
			tmp = new BasicZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		else {
			tmp = new NewspaperZombie(1, 1, zombie_x[i], zombie_y[i]);
		}
		
		zombie.push_back(tmp);
	}

	// С��װ��С��ָ������
	for (int i = 0; i < Carnum; i++) {
		car.push_back(new Car(1, 0, car_x[i], car_y[i]));
	}

	// ��������������ƺ��/������ӳ�䣬���������жϱ����Ƿ��н�ʬ
	for (int i = 0; i < size1; i++)						// ����ֲ�������굽��ƺ������ӳ��
		map_y.insert(std::pair<int, int>(PY + sizehigh * i, i));
	for (int j = 0; j < size2; j++)						// ����ֲ������굽��ƺ������ӳ��
		map_x.insert(std::pair<int, int>(PX + sizewidth * j, j));
	map_y.insert(std::pair<int, int>(80, 0));			// ���彩ʬ�����굽��ƺ������ӳ��
	map_y.insert(std::pair<int, int>(150, 1));
	map_y.insert(std::pair<int, int>(250, 2));
	map_y.insert(std::pair<int, int>(350, 3));
	map_y.insert(std::pair<int, int>(450, 4));

	// ����ͼ�δ���
	initgraph(Width, High);							   // ��ʼ��ͼ�δ���
	HWND hWnd = GetHWnd();							   // ��ȡ���ھ��
	SetWindowText(hWnd, _T("ֲ���ս��ʬ"));			   // �趨����������ֲ���ս��ʬ��
	BeginBatchDraw();								   //����������ͼģʽ
}
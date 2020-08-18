#include "globalVariables.h"
#include "globalVariables-objects.h"
#include "Shooter.h"
#include "SunFlower.h"
#include "BasicZombie.h"
#include "BucketheadZombie.h"
#include "NewspaperZombie.h"

// 全局变量、全局对象定义（注释见两个全局变量头文件）
bool map[5][9];
int sunshineNum = 100;		
int gameFlag = 0;	
int zombie_x[Zombienum] = { 800,1300,1500,2000,2100,2500,2800,3300,3400,3600,3500,3700,3550,3800,3900,3500,3700,3600 };
int zombie_y[Zombienum] = { 80,150,250,80,350,450,150,250,450,350,80,250,150,350,450,250,350,450 };  // 僵尸位置
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

// 全局变量、全局对象初始化
void startup() {

	memset(map, 0, sizeof(map));

	loadRankingList();

	// 僵尸装入僵尸指针数组
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

	// 小车装入小车指针数组
	for (int i = 0; i < Carnum; i++) {
		car.push_back(new Car(1, 0, car_x[i], car_y[i]));
	}

	// 定义坐标数到草坪行/列数的映射，方便射手判断本行是否有僵尸
	for (int i = 0; i < size1; i++)						// 定义植物纵坐标到草坪行数的映射
		map_y.insert(std::pair<int, int>(PY + sizehigh * i, i));
	for (int j = 0; j < size2; j++)						// 定义植物横坐标到草坪列数的映射
		map_x.insert(std::pair<int, int>(PX + sizewidth * j, j));
	map_y.insert(std::pair<int, int>(80, 0));			// 定义僵尸纵坐标到草坪行数的映射
	map_y.insert(std::pair<int, int>(150, 1));
	map_y.insert(std::pair<int, int>(250, 2));
	map_y.insert(std::pair<int, int>(350, 3));
	map_y.insert(std::pair<int, int>(450, 4));

	// 定义图形窗口
	initgraph(Width, High);							   // 初始化图形窗口
	HWND hWnd = GetHWnd();							   // 获取窗口句柄
	SetWindowText(hWnd, _T("植物大战僵尸"));			   // 设定窗口名：“植物大战僵尸”
	BeginBatchDraw();								   //开启批量绘图模式
}
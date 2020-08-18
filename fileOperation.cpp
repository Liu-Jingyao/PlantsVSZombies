#include <fstream>
#include <iostream>
#include <algorithm>
#include "globalvariables.h"

int rankingList[11];

void cleanRankingList() {
	using namespace std;
	ofstream out;
	out.open("rankinglist.dat", ios::out | ios::binary);
	int x = 0;
	for (int i = 0; i < 10; i++)
		out.write((const char*)(&x), sizeof(int));
	out.close();
}

void loadRankingList() {
	using namespace std;
	ifstream in;
	ofstream out;
	in.open("rankinglist.dat", ios::in | ios::binary);
	if (!in.is_open()) {
		cerr << "´æµµ´ò¿ªÊ§°Ü";
		exit(0);
	}
	for (int i = 0; i < 10; i++) {
		in.read((char*)(rankingList + i), sizeof(int));
		if (in.eof())
		{
			in.close();
			cleanRankingList();
			in.open("rankinglist.dat", ios::in | ios::binary);
			break;
		}
	}
	in.close();
}

void writeRankingList(int score) {
	using namespace std;
	ofstream out;
	out.open("rankinglist.dat", ios::out | ios::binary);
	rankingList[10] = score;
	sort(rankingList, rankingList + 11, greater<int>());
	for (int i = 0; i < 10; i++) {
		out.write((const char*)(rankingList + i), sizeof(int));
	}
	out.close();
}


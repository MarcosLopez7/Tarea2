#include "Villager.h"

Villager::Villager(int px, int py, string n, bool t) : Character(px, py, n, t) {
	food = 0;
	srand((int)time(NULL));
}

void Villager::setFood(int f) {
	food = f;
}

int Villager::getFood() {
	return food;
}


void Villager::doSomething(int **b) {
		
	
	
}


bool Villager::detectInjuredFriendWarrior(int b[N][N], vector<Character> c) {

	for (int i = 0; i < 8; ++i) {
		if (team && sensor[i][0] == WT) {
			for (int j = 0; j < c.size(); ++j) {
				if (c[j].getPositionX() == sensor[i][1] && c[j].getPositionY() && c[j].getHealt() < 100) {
					return true;
				}
			}
		}
		else if (!team && sensor[i][0] == WF) {
			for (int j = 0; j < c.size(); ++j) {
				if (c[j].getPositionX() == sensor[i][1] && c[j].getPositionY() && c[j].getHealt() < 100) {
					return true;
				}
			}
		}
	}

	return false;

}

bool Villager::detectFood() {

	for (int i = 0; i < 8; ++i) {
		if (sensor[i][0] == FOOD) {
			return true;
		}
	}

	return false;

}

void Villager::moveRandom() {
	/*
	while (true) {

		int xp = rand() % 3 - 1;
		int yp = rand() % 3 - 1;

		if ((xp != 0 || yp != 0) && )
	}
	*/
}

Villager::~Villager()
{
}
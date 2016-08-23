#include "Character.h"

Character::Character(int px, int py, string n, bool t) {
	positionX = px;
	positionY = py;
	name = n;
	team = t;
	healt = 100;
	dead = false;
}

string Character::getName() {
	return name;
}

int Character::getPositionX() {
	return positionX;
}

int Character::getPositionY() {
	return positionY;
}

bool Character::getTeam() {
	return team;
}

int Character::getHealt() {
	return healt;
}

bool Character::getDead() {
	return dead;
}

void Character::setDead(bool d) {
	dead = d;
}

void Character::detect(int **b) {

	sensor[0][0] = b[positionX - 1][positionY + 1]; sensor[0][1] = positionX - 1; sensor[0][2] = positionY + 1;
	sensor[1][0] = b[positionX][positionY + 1]; sensor[1][1] = positionX; sensor[1][2] = positionY + 1;
	sensor[2][0] = b[positionX + 1][positionY + 1]; sensor[2][1] = positionX + 1; sensor[2][2] = positionY + 1;
	sensor[3][0] = b[positionX + 1][positionY]; sensor[3][1] = positionX + 1; sensor[3][2] = positionY + 1;
	sensor[4][0] = b[positionX + 1][positionY - 1]; sensor[4][1] = positionX + 1; sensor[4][2] = positionY - 1;
	sensor[5][0] = b[positionX][positionY - 1]; sensor[5][1] = positionX; sensor[5][2] = positionY - 1;
	sensor[6][0] = b[positionX - 1][positionY - 1]; sensor[6][1] = positionX - 1; sensor[6][2] = positionY - 1;
	sensor[7][0] = b[positionX - 1][positionY]; sensor[7][1] = positionX - 1; sensor[7][2] = positionY;

}

void Character::run(int **b) {

	while (true) {

		int xp = rand() % 3 - 1;
		int yp = rand() % 3 - 1;

		if ((xp != 0 || yp != 0) && (b[positionX + xp][positionY + yp] == EMPTY)) {
			if (team) {
				b[positionX + xp][positionY + yp] = VT;
				b[positionX][positionY] = EMPTY;
				positionX += xp;
				positionY += yp;
				detect(b);
				if (!detectEnemyWarrior())
					break;
			}
			else if (!team) {
				b[positionX + xp][positionY + yp] = VF;
				b[positionX][positionY] = EMPTY;
				positionX += xp;
				positionY += yp;
				break;
				detect(b);
				if (!detectEnemyWarrior())
					break;
			}
		}
	}

};

bool Character::detectEnemyWarrior() {

	for (int i = 0; i < 8; ++i) {
		if (!team && sensor[i][0] == WT) {
			return true;
		} else if (team && sensor[i][0] == WF) {
			return true;
		}
	}

	return false;

}

void Character::setHealt(int h) {
	healt = h;
}

Character *Character::getCharacterByPosition(vector<Character *> *c, int x, int y) {

	for (int i = 0; i < c->size(); i++) {
		if (x == c->at(i)->getPositionX() && y == c->at(i)->getPositionY()) {
			return c->at(i);
		}
	}

	return NULL;
}

Character::~Character()
{
}
#include "Character.h"

Character::Character(int px, int py, string n, bool t) {
	positionX = px;
	positionY = py;
	name = n;
	team = t;
	healt = 100;
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

void Character::detect(int b[N][N]) {

	sensor[0][0] = b[positionX - 1][positionY + 1]; sensor[0][1] = positionX - 1; sensor[0][2] = positionY + 1;
	sensor[1][0] = b[positionX][positionY + 1]; sensor[1][1] = positionX; sensor[1][2] = positionY + 1;
	sensor[2][0] = b[positionX + 1][positionY + 1]; sensor[2][1] = positionX + 1; sensor[2][2] = positionY + 1;
	sensor[3][0] = b[positionX + 1][positionY]; sensor[3][1] = positionX + 1; sensor[3][2] = positionY + 1;
	sensor[4][0] = b[positionX + 1][positionY - 1]; sensor[4][1] = positionX + 1; sensor[4][2] = positionY - 1;
	sensor[5][0] = b[positionX][positionY - 1]; sensor[5][1] = positionX; sensor[5][2] = positionY - 1;
	sensor[6][0] = b[positionX - 1][positionY - 1]; sensor[6][1] = positionX - 1; sensor[6][2] = positionY - 1;
	sensor[7][0] = b[positionX - 1][positionY]; sensor[7][1] = positionX - 1; sensor[7][2] = positionY;

}

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

Character::~Character()
{
}
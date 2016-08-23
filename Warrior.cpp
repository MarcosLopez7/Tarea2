#include "Warrior.h"

Warrior::Warrior(int px, int py, string n, bool t) : Character(px, py, n, t) { }

void Warrior::doSomething(int **b, vector<Character *> *c) {

	if (!dead) {
		if (detectEnemy()) {
			attack(b, c);
		}
		else if (healt < 100) {
			dropTrail(b);
			cout << name << " Dejo rastro por estar herido\n";
		}
		else {
			moveRandom(b);
			cout << name << " se movio aleatoreamente\n";
		}
	}
	else
		cout << name << " esta muerto\n";

}

bool Warrior::detectEnemy() {

	for (int i = 0; i < 8; ++i) {
		if (!team && (sensor[i][0] == WT || sensor[i][0] == VT)) {
			return true;
		} else if (team && (sensor[i][0] == WF || sensor[i][0] == VF)) {
			return true;
		}
	}

	return false;
}

void Warrior::attack(int **b, vector<Character *> *c) {

	for (int i = 0; i < 8; ++i) {
		if (!team && (sensor[i][0] == VT || sensor[i][0] == WT)) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() == sensor[i][2]) {
					int numberAttack = rand() % 100;
					c->at(j)->setHealt(c->at(j)->getHealt() - numberAttack);
					cout << name << " ha atacado a " << c->at(j)->getName() << " y le ha quitado " << numberAttack << " de vida\n";
					if (c->at(j)->getHealt() <= 0) {
						c->at(j)->setDead(true);
						b[c->at(j)->getPositionX()][c->at(j)->getPositionY()] = EMPTY;
						cout << c->at(j)->getName() << " ha sido eliminado\n";
					}
					else if (sensor[i][0] == VT) {
						c->at(j)->run(b);
					}
				}
			}

			
			
		}
		else if (team && (sensor[i][0] == VF || sensor[i][0] == WF)) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() == sensor[i][2]) {
					int numberAttack = rand() % 100;
					c->at(j)->setHealt(c->at(j)->getHealt() - numberAttack);
					cout << name << " ha atacado a " << c->at(j)->getName() << " y le ha quitado " << numberAttack << " de vida\n";
					if (c->at(j)->getHealt() <= 0) {
						c->at(j)->setDead(true);
						b[c->at(j)->getPositionX()][c->at(j)->getPositionY()] = EMPTY;
						cout << c->at(j)->getName() << " ha sido eliminado\n";
					}
					else if (sensor[i][0] == VF) {
						c->at(j)->run(b);
					}
				}
			}
		}
	}

}

void Warrior::dropTrail(int **b) {

	while (true) {

		int xp = rand() % 3 - 1;
		int yp = rand() % 3 - 1;

		if ((xp != 0 || yp != 0) && (b[positionX + xp][positionY + yp] == EMPTY)) {
			if (team) {
				b[positionX + xp][positionY + yp] = WT;
				b[positionX][positionY] = TRAIL;
				positionX += xp;
				positionY += yp;
				break;
			}
			else if (!team) {
				b[positionX + xp][positionY + yp] = WF;
				b[positionX][positionY] = TRAIL;
				positionX += xp;
				positionY += yp;
				break;
			}
		}
	}

}

void Warrior::moveRandom(int **b) {

	int cont = 0;

	while (true) {

		int xp = rand() % 3 - 1;
		int yp = rand() % 3 - 1;

		if ((xp != 0 || yp != 0) && (b[positionX + xp][positionY + yp] == EMPTY)) {
			if (team) {
				b[positionX + xp][positionY + yp] = WT;
				b[positionX][positionY] = EMPTY;
				positionX += xp;
				positionY += yp;
				break;
			}
			else if (!team) {
				b[positionX + xp][positionY + yp] = WF;
				b[positionX][positionY] = EMPTY;
				positionX += xp;
				positionY += yp;
				break;
			}
		}

		if (cont >= 9) break;
		cont++;
	}

}

Warrior::~Warrior()
{
}

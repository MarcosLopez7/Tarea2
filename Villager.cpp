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


void Villager::doSomething(int **b, vector<Character *> *c) {
		
	if (!dead) {
		if (detectEnemyWarrior()) {
			//esperar que el guerrero lo ataque para que hulla, si es que no lo mata	
		}
		else if (food > 0 && detectInjuredFriendWarrior(b, c)) {
			food--;
			heal(c);
		}
		else if (food > 0 && healt < 100) {
			food--;
			healt += 50;
			cout << name << " se curo con una comida y tiene 50 de vida mas\n";
		}
		else if (food > 0 && detectTrail()) {
			moveToTrail(b);
			cout << name << " fue por un rastro de un guerrero herido\n";
		}
		else if (detectFood()) {
			food++;
			deleteFood(b);
			cout << name << " recolecto comida\n";
		}
		else {
			moveRandom(b);
			cout << name << " Se movio aleatoreamente\n";
		}
	}
	else {
		cout << name << " esta muerto\n";
	}
}

void Villager::heal(vector<Character *> *c) {
	food--;

	for (int i = 0; i < 8; ++i) {
		if (team && sensor[i][0] == WT) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() && c->at(j)->getHealt() < 100) {
					c->at(j)->setHealt(c->at(j)->getHealt() + 50);
					cout << name << " sano a " << c->at(j)->getName() << " con 50 de vida\n";
					break;
				}
			}
		}
		else if (!team && sensor[i][0] == WF) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() && c->at(j)->getHealt() < 100) {
					c->at(j)->setHealt(c->at(j)->getHealt() + 50);
					cout << name << " sano a " << c->at(j) << " con 50 de vida\n";
					break;
				}
			}
		}
	}

}

bool Villager::detectInjuredFriendWarrior(int **b, vector<Character *> *c) {

	for (int i = 0; i < 8; ++i) {
		if (team && sensor[i][0] == WT) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() && c->at(j)->getHealt() < 100) {
					return true;
				}
			}
		}
		else if (!team && sensor[i][0] == WF) {
			for (int j = 0; j < c->size(); ++j) {
				if (c->at(j)->getPositionX() == sensor[i][1] && c->at(j)->getPositionY() && c->at(j)->getHealt() < 100) {
					return true;
				}
			}
		}
	}

	return false;

}

void Villager::collect(int **b) {

	for (int i = 0; i < 8; i++) {
		if (sensor[i][0] == FOOD) {
			food++;
			b[sensor[i][1]][sensor[i][2]] = EMPTY;
			break;
		}
	}
}

void Villager::deleteFood(int **b) {
	for (int i = 0; i < 8; ++i) {
		if (sensor[i][0] == FOOD) {
			b[sensor[i][1]][sensor[i][2]] = EMPTY;
		}
	}
}

bool Villager::detectFood() {

	for (int i = 0; i < 8; ++i) {
		if (sensor[i][0] == FOOD) {
			return true;
		}
	}

	return false;
}

bool Villager::detectTrail() {

	for (int i = 0; i < 8; ++i) {
		if (sensor[i][0] == TRAIL) {
			return true;
		}
	}

	return false;
}

void Villager::moveToTrail(int **b) {
	
	for (int i = 0; i < 8; ++i) {
		if (sensor[i][0] == TRAIL) {
			b[positionX][positionY] = EMPTY;
			positionX = sensor[i][1];
			positionY = sensor[i][2];
			if (team) {
				b[positionX][positionY] = VT;
			} else {
				b[positionX][positionY] = VF;
			}

			break;
		}
	}

}



void Villager::moveRandom(int **b) {

	int cont = 0;

	while (true) {

		int xp = rand() % 3 - 1;
		int yp = rand() % 3 - 1;

		if ((xp != 0 || yp != 0) && (b[positionX + xp][positionY + yp] == EMPTY)) {
			if (team) {
				b[positionX + xp][positionY + yp] = VT;
				b[positionX][positionY] = EMPTY;
				positionX += xp;
				positionY += yp;
				break;
			}
			else if (!team) {
				b[positionX + xp][positionY + yp] = VF;
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

Villager::~Villager()
{
}
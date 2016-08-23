#include "World.h"

World::World() {

	characters = new vector<Character *>;

	board = (int **)malloc(sizeof(int *) * N);
	for  (int i = 0; i < N; ++i) {
		board[i] = (int *)malloc(sizeof(int *) * N);
	}
}

void World::init() {

	srand((int)time(NULL));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
				board[i][j] = OBSTACLE;
			} else {
				int randNumber = (rand() % 100) + 1;

				if (FOOD_PORCENTAGE >= randNumber) {
					board[i][j] = FOOD;
				} else if (randNumber >= 100 - OBSTACLE_PORCENTAGE) {
					board[i][j] = OBSTACLE;
				} else {
					board[i][j] = EMPTY;
				}
			}
		}
	}

	for (int i = 0; i < (VILLAGERS_NUMBER * 2) + (WARRIORS_NUMBER * 2); i++) {

		int randNumForX = 0;
		int randNumForY = 0;

		do {

			randNumForX = rand() % (N - 1) + 1;
			randNumForY = rand() % (N - 1) + 1;

			if (board[randNumForX][randNumForY] == EMPTY) {
				ostringstream oss;
				if (VILLAGERS_NUMBER > i) {
					oss << (i + 1);
					characters->push_back(new Villager(randNumForX, randNumForY, "AF" + oss.str(), false));
					board[randNumForX][randNumForY] = VF;
				} else if (2 * VILLAGERS_NUMBER > i && i >= VILLAGERS_NUMBER) {
					oss << (i - VILLAGERS_NUMBER + 1);
					characters->push_back(new Villager(randNumForX, randNumForY, "AT" + oss.str(), true));
					board[randNumForX][randNumForY] = VT;
				} else if (WARRIORS_NUMBER + (2 * VILLAGERS_NUMBER) > i && i >= 2 * VILLAGERS_NUMBER) {
					oss << (i - (VILLAGERS_NUMBER * 2) + 1);
					characters->push_back(new Warrior(randNumForX, randNumForY, "GF" + oss.str(), false));
					board[randNumForX][randNumForY] = WF;
				} else {
					oss << (i - (VILLAGERS_NUMBER * 2) - WARRIORS_NUMBER + 1);
					characters->push_back(new Warrior(randNumForX, randNumForY, "GT" + oss.str(), true));
					board[randNumForX][randNumForY] = WT;
				}

				
				break;
			}

		} while (true);
		
	}

	print();
}

void World::run() {

	int cont = 0;

	while (!detectFalseLost() && !detectTrueLost()) {

		for (int i = 0; i < characters->size(); i++) {
			characters->at(i)->detect(board);
		}

		for (int i = 0; i < (VILLAGERS_NUMBER * 2) + (WARRIORS_NUMBER * 2); i++) {
			characters->at(i)->doSomething(board, characters);
		}

		system("pause");

		print();
	}

	if (detectFalseLost()) {
		cout << "El equipo True gano\n";
	}
	else {
		cout << "El equipo False gano\n";
	}
}

void World::print() {

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			if (WT >= board[i][j] && board[i][j] >= VF) {
				for (int k = 0; k < characters->size(); ++k) {
					if (i == characters->at(k)->getPositionX() && j == characters->at(k)->getPositionY()) {
						cout << " " << characters->at(k)->getName();
						break;
					}
				}
			}
			else {
				cout << "  " << board[i][j] << " ";
			}
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "0 = casilla vacia\n";
	cout << "1 = comida\n";
	cout << "2 = obstaculo\n";
	cout << "3 = rastro de guerrero herido\n";
	cout << "A = aldeano\n";
	cout << "G = guerrero\n";
	cout << "T = equipo True\n";
	cout << "F = equipo False\n";

}

bool World::detectFalseLost() {
	
	int deads = 0;

	for (int i = 0; i < VILLAGERS_NUMBER; ++i) {
		if (characters->at(i)->getDead()) {
			deads++;
		}
	}

	if (deads == VILLAGERS_NUMBER) {
		return true;
	} else {
		return false;
	}

}

bool World::detectTrueLost() {
	
	int deads = 0;

	for (int i = VILLAGERS_NUMBER; i < VILLAGERS_NUMBER * 2; ++i) {
		if (characters->at(i)->getDead()) {
			deads++;
		}
	}

	if (deads == VILLAGERS_NUMBER) {
		return true;
	}
	else {
		return false;
	}

}

World::~World() {
	for (int i = N - 1; i >= 0; --i) {
		free(board[i]);
	}

	free(board);
	delete characters;
}
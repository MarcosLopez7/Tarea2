#pragma once
#include <string>
#include <ctime>
#include "Character.h"

using namespace std;

class Warrior : public Character
{
public:
	Warrior(int, int, string, bool);
	~Warrior();

	void attack(int **, vector<Character *> *);
	void dropTrail(int **);
	void doSomething(int **, vector<Character *> *);

private:
	void moveRandom(int **);
	bool detectEnemy();

};
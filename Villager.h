#pragma once
#include "Character.h"
#include <string>
#include <ctime>

using namespace std;

class Villager: public Character
{
public:

	Villager(int, int, string, bool);
	~Villager();

	void heal(vector<Character *> *);
	void collect(int **);
	int getFood();
	void setFood(int);
	void doSomething(int **, vector<Character *> *);
	
private:

	int food;
	bool detectInjuredFriendWarrior(int **, vector<Character *> *);
	bool detectFood();
	bool detectTrail();
	void moveRandom(int **);
	void moveToTrail(int **);
	void deleteFood(int **);
};


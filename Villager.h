#pragma once
#include "Character.h"
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Villager: public Character
{
public:

	Villager(int, int, string, bool);
	~Villager();

	void run();
	void heal();
	void collect();
	void eat();
	virtual void doSomething(int [N][N], vector<Character>);
	
private:

	int food;
	bool detectInjuredFriendWarrior(int [N][N], vector<Character>);
	bool detectFood();
	void moveRandom();

};

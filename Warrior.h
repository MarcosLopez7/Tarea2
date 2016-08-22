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

	void attack();
	void eat();
	void dropTrail();
	void doSomething(int **);

private:
	int positionX;
	int positionY;
	int healt;
	string name;

};
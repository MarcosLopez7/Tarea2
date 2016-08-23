#pragma once
#include <windows.h>
#include "Warrior.h"
#include "Villager.h"
#include <sstream>
#include <conio.h>

#define WARRIORS_NUMBER 5
#define VILLAGERS_NUMBER 5
#define FOOD_PORCENTAGE 12
#define OBSTACLE_PORCENTAGE 5

class World
{
public:
	World();
	~World();
	void init();
	void run();

private:
	
	int **board;
	vector<Character *> *characters;

	void print();
	bool detectFalseLost();
	bool detectTrueLost();

};

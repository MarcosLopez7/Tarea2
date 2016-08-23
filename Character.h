#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <iostream>

#define N 30
#define EMPTY 0
#define FOOD 1
#define OBSTACLE 2
#define TRAIL 3
#define VF 4
#define VT 5
#define WF 6
#define WT 7

using namespace std;

class Character
{
public:
	Character(int, int, string, bool);
	~Character();

	void detect(int **);
	void setHealt(int);
	int getPositionX();
	int getPositionY();
	bool getTeam();
	int getHealt();
	string getName();
	bool getDead();
	void setDead(bool);
	void run(int **);
	bool detectEnemyWarrior();
	void virtual doSomething(int **, vector<Character *> *) = 0;

protected:
	int positionX;
	int positionY;
	int healt;
	string name;
	bool team;
	bool dead;
	int sensor[8][3];
	Character *getCharacterByPosition(vector<Character *> *, int, int);
};


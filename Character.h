#pragma once
#include <string>
#include <ctime>

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

	void explore();
	void detect(int [N][N]);
	int getPositionX();
	int getPositionY();
	bool getTeam();
	int getHealt();
	string getName();

protected:
	int positionX;
	int positionY;
	int healt;
	string name;
	bool team;
	int sensor[8][3];
	bool detectEnemyWarrior();

	virtual void doSomething(int b[N][N]);
};


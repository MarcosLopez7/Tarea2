#include "World.h"

int main() {

	World *world = new World;
	world->init();
	delete world;

	system("pause");
	return 0;
}
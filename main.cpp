#include "World.h"

int main() {

	World *world = new World;
	world->init();
	world->run();
	delete world;

	system("pause");
	return 0;
}
#include "Wolf.h"

Wolf::Wolf() : Animal()
{
	setSpecies("W");
	setPosition(Position(0, 0));
	setLiveLength(20);
	setPower(8);
	setPowerToReproduce(16);
	setInitiative(5);
}

Wolf::Wolf(Position position) : Wolf()
{
	setPosition(position);
}

void Wolf::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}

Organism* Wolf::clone()
{
	return this;
}

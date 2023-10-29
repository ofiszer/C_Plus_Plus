#include "Grass.h"

Grass::Grass() : Plant()
{
	setSpecies("G");
	setPosition(Position(0, 0));
	setLiveLength(5);
	setPower(1);
	setPowerToReproduce(2);
	setInitiative(1);
}

Grass::Grass(Position position) : Grass()
{
	setPosition(position);
}

Organism* Grass::clone()
{
	return this;
}

void Grass::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}
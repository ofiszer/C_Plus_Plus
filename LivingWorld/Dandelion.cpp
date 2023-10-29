#include "Dandelion.h"

Dandelion::Dandelion() : Plant()
{
	setSpecies("D");
	setPosition(Position(0, 0));
	setLiveLength(6);
	setPower(0);
	setPowerToReproduce(2);
	setInitiative(0);
}

Dandelion::Dandelion(Position position) : Dandelion()
{
	setPosition(position);
}

Organism* Dandelion::clone()
{
	return this;
}

void Dandelion::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}
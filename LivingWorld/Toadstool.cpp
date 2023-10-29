#include "Toadstool.h"

Toadstool::Toadstool() : Plant()
{
	setSpecies("T");
	setPosition(Position(0, 0));
	setLiveLength(12);
	setPower(0);
	setPowerToReproduce(4);
	setInitiative(0);
}

Toadstool::Toadstool(Position position) : Toadstool()
{
	setPosition(position);
}

Organism* Toadstool::clone()
{
	return this;
}

void Toadstool::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}
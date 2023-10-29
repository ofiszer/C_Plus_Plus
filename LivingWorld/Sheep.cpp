#include "Sheep.h"

Sheep::Sheep() : Animal()
{
	setSpecies("S");
	setPosition(Position(0, 0));
	setLiveLength(10);
	setPower(3);
	setPowerToReproduce(6);
	setInitiative(3);
}

void Sheep::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}

//void Sheep::move(Position* position)
//{
//	setPosition(*position);
//}

Sheep::Sheep(Position position) : Sheep()
{
	setPosition(position);
}

Organism* Sheep::clone()
{
	return this;
}
#include "Animal.h"

Animal::Animal() : Organism()
{
	setSpecies("A");
}

void Animal::move(int dx, int dy)
{
	setPosition(Position(dx, dy));
}

void Animal::move(Position* position)
{
	setPosition(*position);
}
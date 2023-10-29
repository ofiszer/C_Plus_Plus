#pragma once
#include "Animal.h"

using namespace std;

class Wolf : public Animal
{
public:
	Wolf();
	Wolf(Position position);
	Organism* clone() override;
	virtual void move(int dx, int dy) override;
};

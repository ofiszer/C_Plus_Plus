#include "Organism.h"
#include "World.h"
#include <fstream>

Organism::Organism(int power, Position position, int liveLength, int initiative, int powerToReproduce)
{
	setPower(power);
	setPosition(position);
	setLiveLength(liveLength);
	setInitiative(initiative);
	setPowerToReproduce(powerToReproduce);
}


Organism::Organism(const Organism& other)
{
	setPower(other.power);
	setPosition(other.position);
	setLiveLength(other.liveLength);
	setInitiative(other.initiative);
	setPowerToReproduce(other.powerToReproduce);
	setSpecies(other.species);
	this->ancestors = other.ancestors;
	this->selfLifeInfo = other.selfLifeInfo;
}
Organism::~Organism(){}

string Organism::getSpecies()
{
	return this->species;
}

void Organism::setSpecies(string species)
{
	this->species = species;
}

Position Organism::getPosition()
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

int Organism::getLiveLength()
{
	return this->liveLength;
}

void Organism::setLiveLength(int liveLength)
{
	this->liveLength = liveLength;
}

int Organism::getPower()
{
	return this->power;
}

void Organism::setPower(int power)
{
	this->power = power;
}
int Organism::getPowerToReproduce()
{
	return this->powerToReproduce;
}

void Organism::setPowerToReproduce(int powerToReproduce)
{
	this->powerToReproduce = powerToReproduce;
}

int Organism::getInitiative()
{
	return this->initiative;
}

void Organism::setInitiative(int initiative)
{
	this->initiative = initiative;
}

AncestorHistory* Organism::getSelfLifeInfo()
{
	return this->selfLifeInfo;
}

void Organism::setSelfLifeInfo(AncestorHistory* organismInfo)
{
	this->selfLifeInfo = organismInfo;
}

vector<AncestorHistory*> Organism::getancestors()
{
	return this->ancestors;
}

void Organism::addAncestor(AncestorHistory* organismInfo)
{
	this->ancestors.push_back(organismInfo);
}

void Organism::setancestors(vector<AncestorHistory*> ancestors)
{
	this->ancestors = ancestors;
}

bool Organism::canReproduce()
{
	return this->power >= this->powerToReproduce;
}

string Organism::printancestors()
{
	string result = "\nAncestors life info:\n";

	for (AncestorHistory* ancestor : ancestors)
	{
		result += ancestor->toString() + "\n";
	}
	return result;
}

string Organism::toString()
{
	return "{ species: " + this->getSpecies() +
		", power: " + to_string(getPower()) +
		", position: " + getPosition().toString() + 
		", initiative: " + to_string(getInitiative()) +
		", power to reproduce: " + to_string(getPowerToReproduce()) + "}";
}


string Organism::printSelfInfo()
{
	return this->getSelfLifeInfo()->toString();
}

void Organism::serialize(fstream& my_file)
{
	int data;
	data = this->getPower();
	my_file.write((char*)&data, sizeof(int));
	data = this->getPosition().getX();
	my_file.write((char*)&data, sizeof(int));
	data = this->getPosition().getY();
	my_file.write((char*)&data, sizeof(int));
	string s_data = this->getSpecies();
	int s_size = s_data.size();
	my_file.write((char*)&s_size, sizeof(int));
	my_file.write(s_data.data(), s_data.size());
}

Organism* Organism::deserialize(fstream& my_file)
{
	int power, result;
	my_file.read((char*)&result, sizeof(int));
	this->setPower(result);

	int pos_x;
	my_file.read((char*)&result, sizeof(int));
	pos_x = (int)result;
	int pos_y;
	my_file.read((char*)&result, sizeof(int));
	pos_y = (int)result;
	Position pos{ pos_x, pos_y };
	this->setPosition(pos);

	int s_size;
	my_file.read((char*)&result, sizeof(int));
	s_size = (int)result;

	string species;
	species.resize(s_size);
	my_file.read((char*)&species[0], s_size);

	this->setSpecies(species);
	return this;
}
#include "World.h"
#include <fstream>
#include <iostream>
#include <algorithm>

World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}
World::~World() {}

string World::getOrganismFromPosition(int x, int y)
{
	for (Organism* org : organisms)
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
			return org->getSpecies();
	return "";
}

//string World::getOrganismFromPosition(int x, int y)
//{
//	for (auto& org : organisms)
//		if (org.getPosition().getX() == x && org.getPosition().getY() == y)
//			return org.getSpecies();
//	return "";
//}

bool World::isPositionOnWorld(int x, int y)
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}


bool World::isPositionFree(Position position) {
	return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
}

vector<Position> World::getVectorOfFreePositionsAround(Position position)
{
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for (int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) &&
				isPositionOnWorld(pos_x + x, pos_y + y))
			{
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
		[this](Position pos) { return !isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}
vector<Position> World::getVectorOfBusyPositionsAround(Position position)
{
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for (int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) &&
				isPositionOnWorld(pos_x + x, pos_y + y))
			{
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
		[this](Position pos) { return isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}


Position* World::getRandomNeighboringPosition(Organism* organism)
{
	vector<Position> newPositions;
	int numberOfNewPositions;
	int randomIndex;
	srand(time(0));

	newPositions = getVectorOfFreePositionsAround(organism->getPosition());
	numberOfNewPositions = newPositions.size();
	if (numberOfNewPositions == 0) return nullptr;
	randomIndex = rand() % numberOfNewPositions;
	Position* newPosition = new Position(newPositions[randomIndex]);
	return newPosition;
}


int World::getWorldX()
{
	return this->worldX;
}


void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY()
{
	return this->worldY;
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn()
{
	return this->turn;
}

void World::addOrganism(Organism* organism)	//tu s¹ dodawane organizmy
{
	AncestorHistory* info = new AncestorHistory(this->getTurn());
	ancestorsHistory.push_back(info);
	AncestorHistory* selfInfo = ancestorsHistory.back();
	organism->setSelfLifeInfo(selfInfo);
	this->organisms.push_back(organism);
}

void World::reproduce(Organism* parent)
{
	Position* position = getRandomNeighboringPosition(parent);
	if (position == nullptr) return;
	AncestorHistory* info = new AncestorHistory(this->getTurn());
	ancestorsHistory.push_back(info);
	AncestorHistory* selfInfo = ancestorsHistory.back();
	Organism* organism = parent->clone();
	organism->setSelfLifeInfo(selfInfo);
	organism->addAncestor(parent->getSelfLifeInfo());
	organism->setPosition(*position);
	this->organisms.push_back(organism);
	parent->setPower(parent->getPower() / 2);
}

void World::killOrganism(Organism* organism)
{
	organism->getSelfLifeInfo()->setDeathTurn(this->getTurn());
	for (auto it = organisms.begin(); it != organisms.end(); ++it)
	{
		if ((*it) == organism){
			organisms.erase(it);
			break;
		}
	}
}

void World::makeTurn()
{
	Position* newPosition;
	vector<Organism*> organismsToReproduce;
	vector<Organism*> organismsToDie;

	sortWorld();

	for (Organism* org : organisms){
		if (org->getLiveLength() <= 0)
		{
			organismsToDie.push_back(org);	// umiera
			continue;
		}
		cout << org->getSpecies();

		org->setPower(org->getPower() + 1);
		org->setLiveLength(org->getLiveLength() - 1);

		if (org->canReproduce()) organismsToReproduce.push_back(org); // czy mo¿e siê rozmna¿aæ


		
		newPosition = getRandomNeighboringPosition(org); // pozycja
		if (newPosition != nullptr)
		{
			org->move(newPosition);
		}
	}

	for (Organism* org : organismsToDie)
	{
		killOrganism(org);
	}
	for (Organism* org : organismsToReproduce)
	{
		reproduce(org);
	}

	turn++;
}



void World::sortWorld() {
	sort(organisms.begin(), organisms.end(),
		[](Organism* org1, Organism* org2)
		{
			if (org1->getInitiative() != org2->getInitiative())
			{
				return org1->getInitiative() > org2->getInitiative();
			}
			return org1->getPower() > org2->getPower();
		});
}


//void World::writeWorld(string fileName)
//{
//	/*fstream my_file;
//	my_file.open(fileName, ios::out | ios::binary);
//	if (my_file.is_open()) {
//		my_file.write((char*)&this->worldX, sizeof(int));
//		my_file.write((char*)&this->worldY, sizeof(int));
//		my_file.write((char*)&this->turn, sizeof(int));
//		int orgs_size = this->organisms.size();
//		my_file.write((char*)&orgs_size, sizeof(int));
//		for (int i = 0; i < orgs_size; i++) {
//			int data;
//			data = this->organisms[i].getPower();
//			my_file.write((char*)&data, sizeof(int));
//			data = this->organisms[i].getPosition().getX();
//			my_file.write((char*)&data, sizeof(int));
//			data = this->organisms[i].getPosition().getY();
//			my_file.write((char*)&data, sizeof(int));
//			string s_data = this->organisms[i].getSpecies();
//			int s_size = s_data.size();
//			my_file.write((char*)&s_size, sizeof(int));
//			my_file.write(s_data.data(), s_data.size());
//		}
//		my_file.close();
//	}*/
//}
//void World::readWorld(string fileName)
//{
//	/*fstream my_file;
//	my_file.open(fileName, ios::in | ios::binary);
//	if (my_file.is_open()) {
//		int result;
//		my_file.read((char*)&result, sizeof(int));
//		this->worldX = (int)result;
//		my_file.read((char*)&result, sizeof(int));
//		this->worldY = (int)result;
//		my_file.read((char*)&result, sizeof(int));
//		this->turn = (int)result;
//		my_file.read((char*)&result, sizeof(int));
//		int orgs_size = (int)result;
//		vector<Organism> new_organisms;
//		for (int i = 0; i < orgs_size; i++) {
//			int power;
//			my_file.read((char*)&result, sizeof(int));
//			power = (int)result;
//
//			int pos_x;
//			my_file.read((char*)&result, sizeof(int));
//			pos_x = (int)result;
//			int pos_y;
//			my_file.read((char*)&result, sizeof(int));
//			pos_y = (int)result;
//			Position pos{ pos_x, pos_y };
//
//			int s_size;
//			my_file.read((char*)&result, sizeof(int));
//			s_size = (int)result;
//
//			string species;
//			species.resize(s_size);
//			my_file.read((char*)&species[0], s_size);
//
//			Organism org(power, pos);
//			org.setSpecies(species);
//			new_organisms.push_back(org);
//		}
//		this->organisms = new_organisms;
//		my_file.close();
//	}*/
//}


string World::toString()
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY) {
		for (int wX = 0; wX < getWorldX(); ++wX) {
			spec = getOrganismFromPosition(wX, wY);
			if (spec != "")
				result += spec;
			else
				result += separator;
		};
		result += "\n";
	}

	return result;
}

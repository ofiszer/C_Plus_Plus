#pragma once
#include <vector>
#include <ctime>
#include "Organism.h"
#include "AncestorHistoryclass.h"

using namespace std;

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism*> organisms;
	vector<AncestorHistory*> ancestorsHistory;
	char separator = '.';

	string getOrganismFromPosition(int x, int y);
	bool isPositionOnWorld(int x, int y);
	bool isPositionFree(Position position);

public:
	World(int worldX, int worldY);
	World() : World(6, 6) {};
	~World();

	int getWorldX();
	void setWorldX(int worldX);
	int getWorldY();
	void setWorldY(int worldY);

	int getTurn();

	void addOrganism(Organism* organism);
	void reproduce(Organism* parent);
	void killOrganism(Organism* organism);

	vector<Position> getVectorOfFreePositionsAround(Position position);
	vector<Position> getVectorOfBusyPositionsAround(Position position);
	Position* getRandomNeighboringPosition(Organism* organism);

	void makeTurn();
	void sortWorld();

	//void writeWorld(string fileName);
	//void readWorld(string fileName);

	string toString();
};
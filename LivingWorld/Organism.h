#pragma once
#include <string>
#include <vector>
#include "Position.h"
#include "AncestorHistoryclass.h"
#include <memory>

using namespace std;

class Organism
{
private:
	AncestorHistory* selfLifeInfo = 0;
	vector<AncestorHistory*> ancestors;
	string species = "O";
	Position position = Position(0, 0);
	int liveLength = 2;
	int power = 0;
	int powerToReproduce = 1;
	int initiative = 0;

public:
	Organism(int power, Position position, int liveLength, int initiative, int powerToReproduce);
	Organism(const Organism& other);
	Organism() {};
	~Organism();

	string getSpecies();
	void setSpecies(string species);
	Position getPosition();
	void setPosition(Position position);
	int getLiveLength();
	void setLiveLength(int liveLength);
	int getPower();
	void setPower(int power);


	int getPowerToReproduce();
	void setPowerToReproduce(int powerToReproduce);
	int getInitiative();
	void setInitiative(int initiative);

	AncestorHistory* getSelfLifeInfo();
	void setSelfLifeInfo(AncestorHistory* organismInfo);
	vector<AncestorHistory*> getancestors();
	void addAncestor(AncestorHistory* organismInfo);
	void setancestors(vector<AncestorHistory*> ancestors);

	bool canReproduce();

	string toString();
	string printSelfInfo();
	string printancestors();
	virtual void move(int dx, int dy) = 0;
	virtual void move(Position* position) = 0;
	virtual Organism* clone() = 0;

	virtual void serialize(fstream& file);
	virtual Organism* deserialize(fstream& file);
};
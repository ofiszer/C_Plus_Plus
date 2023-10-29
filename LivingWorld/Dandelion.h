#pragma once
#include "Plant.h"

using namespace std;

class Dandelion : public Plant
{
public:
    /*Dandelion(int power, Position position, int initiative, int livelength, AncestorHistory ancestorHistory);

    virtual int getPower() override { return Dandelion::getPower(); };
    virtual void setPower(int power) override {};
    virtual Position getPosition() override { return Dandelion::getPosition(); };
    virtual void setPosition(Position position) override {};
    virtual string getSpecies() override { return Dandelion::getSpecies(); };
    virtual void setSpecies(string spec) override {};
    virtual int getInitiative() const  override { return Dandelion::getInitiative(); };
    virtual void setInitiative(int initiative)  override {};
    virtual AncestorHistory getAncestorHistory()  override { return Dandelion::getAncestorHistory(); };
    virtual void setAncestorHistory(AncestorHistory ancestorHistory)  override {};

    virtual string toString() override { return Dandelion::toString(); };

    virtual void serialize(ofstream& file) override;
    virtual void deserialize(ifstream& file) override;*/

    //Dandelion() {};

    std::vector<Position*> getNeighboringPosition() { // zwraca pusty wektor pozycji
        return std::vector<Position*>();
    }
	Dandelion();
	Dandelion(Position position);
	Organism* clone() override;
    virtual void move(int dx, int dy) override;
};

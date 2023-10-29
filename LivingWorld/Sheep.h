#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal
{
public:
	Sheep();
    //virtual int getPower() override { return Sheep::getPower(); };
    //virtual void setPower(int power) override {};
    //virtual Position getPosition() override { return Sheep::getPosition(); };
    //virtual void setPosition(Position position) override {};
    //virtual string getSpecies() override { return Sheep::getSpecies(); };
    //virtual void setSpecies(string spec) override {};
    //virtual int getInitiative() const  override { return Sheep::getInitiative(); };
    //virtual void setInitiative(int initiative) override {};
    //int getLiveLength() const  override { return Sheep::getLiveLength(); };
    //virtual void setLiveLength(int livelength) override {}
    //virtual AncestorHistory getAncestorHistory() override { return Sheep::getAncestorHistory(); };
    //virtual void setAncestorHistory(AncestorHistory ancestorHistory) override {};

    //virtual string toString() override { return Sheep::toString(); };
	Sheep(Position position);
	Organism* clone() override;
	virtual void move(int dx, int dy) override;
};

#pragma once
#include "Plant.h"

using namespace std;

class Grass : public Plant
{
public:
	Grass();

    //virtual int getPower() override { return Grass::getPower(); };
    //virtual void setPower(int power) override {};
    //virtual Position getPosition() override { return Grass::getPosition(); };
    //virtual void setPosition(Position position) override {};
    //virtual string getSpecies() override { return Grass::getSpecies(); };
    //virtual void setSpecies(string spec) override {};
    //virtual int getInitiative() const  override { return Grass::getInitiative(); };
    //virtual void setInitiative(int initiative)  override {};
    //int getLiveLength() const  override { return Plant::getLiveLength(); };
    //virtual void setLiveLength(int livelength) override {}
    //virtual AncestorHistory getAncestorHistory() override { return Grass::getAncestorHistory(); };
    //virtual void setAncestorHistory(AncestorHistory ancestorHistory)  override {};
	Grass(Position position);
	Organism* clone() override;
	virtual void move(int dx, int dy) override;
};

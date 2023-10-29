#pragma once
#include "Organism.h"

using namespace std;

class Plant : public virtual Organism
{
public:
	Plant();

    //virtual int getPower() override { return Organism::getPower(); };
    //virtual void setPower(int power) override {};
    //virtual Position getPosition() override { return Organism::getPosition(); };
    //virtual void setPosition(Position position) override {};
    //virtual string getSpecies() override { return Organism::getSpecies(); };
    //virtual void setSpecies(string spec) override {};
    //virtual int getInitiative() const  override { return Organism::getInitiative(); };
    //virtual void setInitiative(int initiative)  override {};
    //virtual int getLiveLength() const  override { return Organism::getLiveLength(); };
    //virtual void setLiveLength(int livelength)  override {};
    //virtual AncestorHistory getAncestorHistory()  override { return Organism::getAncestorHistory(); };
    //virtual void setAncestorHistory(AncestorHistory ancestorHistory)  override {};

	virtual void move(int dx, int dy) = 0;
	virtual void move(Position* position) override;
};
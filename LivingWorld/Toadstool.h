#pragma once
#include "Plant.h"

using namespace std;

class Toadstool : public Plant
{
public:

    //Toadstool(int power, Position position, int initiative, AncestorHistory ancestorHistory);
    /*virtual int getPower() override { return Toadstool::getPower(); };
    virtual void setPower(int power) override {};
    virtual Position getPosition() override { return Toadstool::getPosition(); };
    virtual void setPosition(Position position) override {};
    virtual string getSpecies() override { return Toadstool::getSpecies(); };
    virtual void setSpecies(string spec) override {};
    virtual int getInitiative() const  override { return Toadstool::getInitiative(); };
    virtual void setInitiative(int initiative)  override {};
    virtual AncestorHistory getAncestorHistory()  override { return Toadstool::getAncestorHistory(); };
    virtual void setAncestorHistory(AncestorHistory ancestorHistory)  override {};*/
    //string toString() const;    //nowy



	Toadstool();
	Toadstool(Position position);
	Organism* clone() override;



	virtual void move(int dx, int dy) override;
};

#include "AncestorHistoryclass.h"

AncestorHistory::AncestorHistory(int birthTurn)
{
	setBirthTurn(birthTurn);
};

AncestorHistory::AncestorHistory(const AncestorHistory& other)
{
	birthTurn = other.birthTurn;
	deathTurn = other.deathTurn;
}

int AncestorHistory::getBirthTurn()
{
	return this->birthTurn;
}

void AncestorHistory::setBirthTurn(int birthTurn)
{
	this->birthTurn = birthTurn;
}

int AncestorHistory::getDeathTurn()
{
	return this->deathTurn;
}

void AncestorHistory::setDeathTurn(int deathTurn)
{
	this->deathTurn = deathTurn;
}

string AncestorHistory::toString()
{
	return "Birth turn:" + to_string(this->getBirthTurn()) + ", death turn:" + to_string(this->getDeathTurn());
}
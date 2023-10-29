#pragma once
#include <vector>
#include <string>

using namespace std;
//
//class AncestorHistory {
//private:
//    vector<pair<int, int>> ancestors;
//    int birthTurns;
//    int deathTurns;
//
//public:
//    AncestorHistory(int birthTurns, int deathTurns);
//    AncestorHistory() : birthTurns(-1), deathTurns(-1) {}
//
//    void addAncestor(int x, int y);
//    vector<pair<int, int>> getAncestors();
//
//    AncestorHistory(int birthTurns);
//
//    int getBirthTurns();
//    void setBirthTurns(int turns);
//    int getDeathTurns();
//    void setDeathTurns(int turns);
//
//    string toString();
//};


class AncestorHistory
{
private:
	int birthTurn = 0;
	int deathTurn = -1;
	//vector<pair<int, int>> ancestors; // wektor do przechowywania wielu przodków

public:
	AncestorHistory() {};
	AncestorHistory(int birthTurn);
	AncestorHistory(const AncestorHistory& other);

	int getBirthTurn();
	void setBirthTurn(int birthTurn);
	int getDeathTurn();
	void setDeathTurn(int birthTurn);

	string toString();

	/*double distance(AncestorHistory ancestorHistory);
	void move(int dx, int dy);*/
};

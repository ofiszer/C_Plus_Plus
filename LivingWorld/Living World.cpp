// Living World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "AncestorHistoryclass.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Toadstool.h"
#include "Sheep.h"
#include "Wolf.h"



using namespace std;

int main()
{
	// Position 
	//Position p1;
	//Position p2{ 1, 1 };
	//Position p3{ -3, -5 };

	//cout << p1.toString() << endl;
	//cout << p2.toString() << endl;
	//cout << p3.toString() << endl;

	//AncestorHistory ancestorHistory1{ 3, 5 };	// nowa historia przodków
	//AncestorHistory ancestorHistory2{ -1, -2 };	// nowa historia przodków

	//cout << ancestorHistory1.toString() << " ancestorHistory1" << endl;
	//cout << ancestorHistory2.toString() << " ancestorHistory2" << endl;
	//cout << p1.distance(p2) << endl;
	//p2.move(4, 6);
	//cout << p2.toString() << endl;

	// Organism
	//Organism org1;
	//Animal org1;
	//ancestorHistory.addAncestor(0);		// nowy przodek
	//ancestorHistory1.addAncestor(3, 5);	// nowy przodek/ stara wersja AncestorHistory z pliku Organism.h
	//Organism org2{ 10, p2, 3, ancestorHistory1 };	// organizm org2 z przodkami
	//Animal org2(10, p2, 3, 5, ancestorHistory1);
	//org2.getAncestorHistory().addAncestor(2, 3);
	//org2.getAncestorHistory().addAncestor(1, 5);
	//Organism org2{ 10, p2 };

	//cout << org1.toString() << endl;
	//cout << org2.toString() << endl;
	//org1.move(2, 3);
	//cout << org1.toString() << endl;

	// Plant & Animal
	//ancestorHistory.addAncestor(0);		// nowy przodek
	//ancestorHistory2.addAncestor(4, 7);	// nowy przodek/ stara wersja AncestorHistory z pliku Organism.h
	//Plant plant{ 3, p3, 4, ancestorHistory2 };
	//Grass g1;// { 3, p3, ancestorHistory2 };
	//Animal animal{ 5, p2, 3, 6, ancestorHistory1 };
	//Plant plant2;
	//Animal animal2;

	//cout << plant.toString() << endl;
	//cout << animal.toString() << endl;
	//cout << plant2.toString() << endl;
	//cout << animal2.toString() << endl;
	//plant.move(3, 4);
	//cout << plant.toString() << endl;
	//animal.move(1, 2);
	//cout << animal.toString() << endl;

	// World test
	World world;
	Position posP1{ 4, 5 };
	Position posP2{ 5, 4 };
	Position posW3{ 3, 2 };
	Position posW4{ 2, 3 };
	Position posW5{ 6, 6 };
	Position posW6{ 1, 1 };

	// World test
	//World world;
	//Position posP1{ 4, 5 };
	//Plant plantW1{ 3, posP1 };
	//Position posP2{ 5, 4 };
	//Plant plantW2{ 3, posP2 };

	//Position posW2{ 3, 2 };
	//Animal animalW1{ 6, posW2 };
	//Position posW3{ 2, 3 };
	//Animal animalW2{ 6, posW3 };

	Grass g1 = Grass(posP1);
	Grass g2 = Grass(posP2);
	Toadstool t1 = Toadstool(posW3);
	Sheep s1 = Sheep(posW4);
	Wolf w1 = Wolf(posW6);


	world.addOrganism(&g1);
	world.addOrganism(&g2);
	world.addOrganism(&t1);
	world.addOrganism(&s1);
	world.addOrganism(&w1);


	//auto sheep1 = Organism:createOrganism
	//world.addOrganism(&plantW1);
	//world.addOrganism(&plantW2);
	//world.addOrganism(&animalW1);
	//world.addOrganism(&animalW2);



	//auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));

	//for (auto pos : positions)
	//	cout << pos.toString() << endl;

	// Tura 0
	cout << world.toString() << endl;

	// Tura 1
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 2
	world.makeTurn();
	cout << world.toString() << endl;

	//world.writeWorld("world.bin");

	// Tura 3
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 4
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 5
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 6
	world.makeTurn();
	cout << world.toString() << endl;



	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

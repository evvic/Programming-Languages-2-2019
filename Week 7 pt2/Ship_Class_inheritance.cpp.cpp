#include "CruiseShip.h"
#include "CargoShip.h"
#include "Ship.h"
#include <iostream>
#include <string>

//class Ship inheritance
//finding nemo bruh

using namespace std;

const int ships = 4;

virtual istream& operator>>(istream& stream, Ship& other)
{
	string name, year;


	cout << "\nName: ";
	cin >> name;
	other.setName(name);

	cout << "\nYear: ";
	cin >> year;
	other.setYear(year);

	cout << endl;

	return stream;

}

virtual istream& operator>>(istream& stream, CargoShip& other)
{
	string name, year;

	int c;

	cout << "\nName: ";
	cin >> name;
	other.setName(name);

	cout << "\nYear: ";
	cin >> year;
	other.setYear(year);

	cout << "\nCapacity: ";
	cin >> c;
	other.setCapacity(c);

	cout << endl;

	return stream;

}

int main() {

	Ship* butts[ships] =
	{
		new Ship("Mayflower", "1620"),
		new CruiseShip("Norweigan", "2003", 8000),
		new CargoShip("CargoTec", "2008", 75000),
		new CruiseShip("Carnival", "1995", 6500)
	};

	//'virtual' is needed when calling printShip() so it compiles when it is called, not when built
	//important for when overloading class functions when it gets messy like this (in an array of Ship pointers lol
	for (int i = 0; i < ships; i++) {
		butts[i]->PrintShip(); //MUST USE 'virtual' IN FUNCTION DEFINITION
		cout << endl;
	}


}
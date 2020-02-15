#include "CruiseShip.h"
#include "CargoShip.h"
#include "Ship.h"
#include <iostream>
#include <string>

//class Ship inheritance
//finding nemo bruh

using namespace std;

const int ships = 4;

istream& operator>>(istream& stream, Ship& other)
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

istream& operator>>(istream& stream, CargoShip& other)
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

	for (int i = 0; i < ships; i++) {
		butts[i]->PrintShip(); //HOW CAN I GET THIS TO CALL THE DERIVED NON-OVERIDDEN FUNCTION??? only calls Ship (base) class member function
		cout << endl;
	}


}
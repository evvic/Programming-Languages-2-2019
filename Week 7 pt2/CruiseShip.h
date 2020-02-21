#pragma once
#include <iostream>
#include "Ship.h"

using namespace std;

class CruiseShip :
	public Ship
{
private:
	int passengers; //max passengers
public:
	CruiseShip() : Ship() {
		passengers = 0;
	}
	CruiseShip(string n, string y, int p) : Ship(n, y) {
		passengers = p;
	}

	void setPassengers(int p) {
		passengers = p;
	}

	void setFax() {

		string n, y;

		cout << "\nName: ";
		cin >> n;
		setName(n);

		cout << "\nYear: ";
		cin >> y;
		setYear(y);

		cout << "\nMax Passengers: ";
		cin >> passengers;

		cout << endl;
	}

	int getPassengers() {
		return passengers;
	}

	virtual void PrintShip() {
		cout << getName() << ", " << passengers << " passengers";
	}
};

#pragma once
#include "Ship.h"
#include <iostream>

using namespace std;

class CargoShip : public Ship
{
private:
	int capacity; //cargo capacity in tonnage
public:
	CargoShip() : Ship() {
		capacity = 0;
	}
	CargoShip(string n, string y, int c) : Ship(n, y) {
		capacity = c;
	}

	void setCapacity(int c) {
		capacity = c;
	}

	void setFax() {

		string n, y;

		cout << "\nName: ";
		cin >> n;
		setName(n);

		cout << "\nYear: ";
		cin >> y;
		setYear(y);

		cout << "\nCapacity: ";
		cin >> capacity;

		cout << endl;
	}

	int getCapacity() {
		return capacity;
	}

	virtual void PrintShip() {
		cout << getName() << ", " << capacity << " tonnage capacity";
	}
};
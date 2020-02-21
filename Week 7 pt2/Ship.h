#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ship
{
private:
	string name;
	string year;
public:
	Ship() { name = ""; year = ""; }
	Ship(string n, string y) {
		name = n;
		year = y;
	}

	void setName(string n) {
		name = n;
	}
	void setYear(string y) {
		year = y;
	}

	void setFax() {

		cout << "\nName: ";
		cin >> name;

		cout << "\nYear: ";
		cin >> year;

		cout << endl;
	}

	string getName() {
		return name;
	}
	string getYear() {
		return year;
	}



	virtual void PrintShip() { //virtual is like a templte
		cout << name << ", " << year;
	}
};
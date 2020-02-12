#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	string name;
	int idNumber;
	string department;
	string position;
public:
	Employee(string n, int id, string d, string p) {
		name = n;
		idNumber = id;
		department = d;
		position = p;
	}
	Employee(string n, int id) {
		name = n;
		idNumber = id;
		department = "";
		position = "";
	}
	Employee() {
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}

	void setName(string n) {
		name = n;
	}
	void setId(int id) {
		idNumber = id;
	}
	void setDepartment(string d) {
		department = d;
	}
	void setPosition(string p) {
		position = p;
	}

	string getName() {
		return name;
	}
	int getId() {
		return idNumber;
	}
	string getDepartment() {
		return department;
	}
	string getPosition() {
		return position;
	}

};

int main() {

	Employee swag[3];

	Employee first("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee second("Mark Jones", 39119, "IT", "Programmer");
	Employee third("Joy Rogers", 81774, "Manufactoring", "Engineer");

	swag[0] = first;
	swag[1] = second;
	swag[2] = third;

	for (int i = 0; i < 3; i++) {
		cout << swag[i].getName() << ' ' << swag[i].getId() << ' ' << swag[i].getDepartment() << ' ' << swag[i].getPosition() << endl;
	}
}

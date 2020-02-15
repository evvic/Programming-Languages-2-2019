#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
	string name;
	int number;
	int date;
public:
	Employee() {
		name = "";
		number = 000;
		date = 19101998;
	}
	Employee(string n, int i, int d) {
		name = n;
		number = i;
		date = d;
	}


	void setName(string n) {
		name = n;
	}
	void setNumber(int n) {
		number = n;
	}
	void setName(int d) {
		date = d;
	}

	string getName() {
		return name;
	}
	int getNumber() {
		return number;
	}
	int getDate() {
		return date;
	}

};

class ProductionWorker : public Employee {
private:
	int shift;
	double hourlyRate;
public:
	using Employee::Employee; //does this work?

	//THIS WORKS!!!! TAKE NOTES FOR INITIALIZING BASE CLASS CONSTRUCTOR WITH DERIVED CLASS
	ProductionWorker(int s, double r, string n, int i, double d) : Employee ( n,  i,  d) { 
		shift = s;
		hourlyRate = r;
	}
	//   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	void setShift(int s) {
		shift = s;
	}
	void setRate(double r) {
		hourlyRate = r;
	}

	int getShift() {
		return shift;
	}
	double getRate() {
		return hourlyRate;
	}

	double HourlyRate() {
		return shift * hourlyRate;
	}
};

//shift 1 is day, shift 2 is night
//night shift doubles the rate

int main() {
	string name;
	int id, date, shift;
	double rate;

	cout << "\nEnter employee name: ";
	cin >> name;

	do {
		cout << "\nEnter employee number (#####): ";
		cin >> id;
	} while (id < 9999 || id > 100000);

	do {
		cout << "\nEnter todays date (ddmmyyyy): ";
		cin >> date;
	} while (date < 9999999 || date > 100000000);

	do {
		cout << "\nEnter hourly rate: ";
		cin >> rate;
	} while (rate < 10 || rate > 30);

	do {
		cout << "\nEnter current shift status.\n\t'1' for day shift.\n\t'2' for night shift.\n";
		cin >> shift;
	} while (shift != 1 && /* || */ shift != 2);

	//YOO THIS WORKS TOO, INITIALIZEING BASE AND DERIVED CLASS
	ProductionWorker guy(shift, rate, name, id, date);
	//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


	cout << endl << "The adjusted hourly rate for " << guy.getName() << " is " << guy.HourlyRate() << endl;
	//NOTICE! getName() is a member function of Employee BUT can simply be called from ProductionWorker

	cout << endl << endl;
	cout << "Name" << '\t' << "Employee #" << '\t' << "Date" << endl;
	cout << guy.getName() << '\t' << guy.getNumber() << '\t' << guy.getDate() << endl << endl;
	cout << "Hourly pay rate: " << guy.HourlyRate() << endl;
	if (guy.getShift() == 1) {
		cout << "Day ";
	}
	else cout << "Night ";

	cout << " shift.";

	cout << endl << endl;


}
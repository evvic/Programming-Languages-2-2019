#include <iostream>
#include <string>

using namespace std;

struct monthSync {
	string month;
	int days;
};

class DayOfYear {
private:
	int day;
	//monthSync mValues[12] = { {"January", 31}, {"February", 28}, {"March", 31}, {"April", 30}, {"May", 31}, {"June", 30}, {"July", 31}, {"August", 31}, {"September", 30}, {"October", 31}, {"November", 30}, {"December", 30} };

public:
	static int daysAtEndOfMonth[];
	static string monthName[];
	//static monthSync daysAtEndOfMonth;


	DayOfYear(int d) { day = d; };//constructor

	void setDay(int day) { this->day = day; }; //'this' operator points to the day variable in´the class, not the one in the member function
	int getDay() { return day; };
	void print(); //definition at bottom
};

int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
string DayOfYear::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int main() {

	int day;

	do {
		cout << "Enter a day between 1 and 365: ";
		cin >> day;
	} while (day < 1 || day > 365);
	
	DayOfYear cny(day);

	cny.print();

}

void DayOfYear::print() {
	int displayd;

	if (day < DayOfYear::daysAtEndOfMonth[0] && day > 0) { //checking for january only
		cout << monthName[0] << ' ' << day << '.' << endl;
	}

	for (int i = 0; i < 12; i++) {
		if (day < DayOfYear::daysAtEndOfMonth[i + 1] && day > DayOfYear::daysAtEndOfMonth[i]) {
			displayd = day - daysAtEndOfMonth[i];
			cout << monthName[i + 1] << ' ' << displayd << '.' << endl;
		}
	}
}

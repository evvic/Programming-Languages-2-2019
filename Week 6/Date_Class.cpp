//This is a Date class with overloaded operators to return the date in different formats
//The overloaded operators can be used to easily manipulate the date
//Eric Brown TAMK

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

void CenterString(string s);


class Date {
private:
	int day;
	int month;
	int year;
public:
	const string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const int daysPer[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	Date() { day = month = year = 0; }

	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	void setDay(int d) {
		day = d;
	}
	void setMonth(int m) {
		month = m;
	}
	void setYear(int y) {
		year = y;
	}

	int getDay() {
		return day;
	}
	int getMonth() {
		return month;
	}
	int getYear() {
		return year;
	}

	void PrintSlashes() { // 12/25/2018
		cout << month << '/' << day << '/' << year;
	}
	void PrintMDY() { // December 25, 2018
		cout << months[month - 1] << ' ' << day << ", " << year;
	}
	void PrintDMY() { // 25 Decmeber 2018
		cout << day << ' ' << months[month - 1] << ' ' << year;
	}

	string StringSlashes() {
		return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	}
	string StringMDY() {
		return months[month - 1] + " " + to_string(day) +  ", " + to_string(year);
	}
	string StringDMY() {
		return  to_string(day) + " " + months[month - 1] + " " + to_string(year);
	}


	// Define prefix increment operator
	Date& operator++() {
		//++ is a UNARY operator, operates only on one operand
		day++;
		if (day > 31) {
			day = 1;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
		}
		return *this; //THIS confuses me, what is being returned exactly?
	}
	// Define postfix increment operator
	Date operator++(int) {

		//this part confuses me
		Date temp = *this;
		++* this;
		//^^^^^^^^^^^^^^^6^^^^^

		if (temp.day > 31) {
			temp.day = 1;
			temp.month++;
		}
		if (temp.month > 12) {
			temp.month = 1;
			temp.year++;
		}
		return temp;
	}

	// Define prefix decrement operator
	Date& operator--() {
		//-- is a UNARY operator, operates only on one operand
		day--;
		if (day < 1) {
			day = 31;
			month--;
		}
		if (month < 1) {
			month = 12;
			year--;
		}
		return *this;
	}
	// Define postfix decrement operator
	Date operator--(int) {

		//this part confuses me
		Date temp = *this;
		--* this;
		//^^^^^^^^^^^^^^^6^^^^^

		if (temp.day < 1) {
			temp.day = 31;
			temp.month--;
		}
		if (temp.month < 1) {
			temp.month = 12;
			temp.year--;
		}
		return temp;
	}

	int operator-(Date other) { //collects sum of both 
		long sum1 = (year * 365) + (daysPer[month]) + day;
		long sum2 = (other.getYear() * 365) + (daysPer[other.getMonth()]) + other.getDay();

		return (int)(sum1 - sum2);
	}




};

//cout operator for Date
//takes 2 arguments (1 for each side), 1 is the 'cout' and the other is the class being displayed
ostream& operator<<(ostream& stream, Date& other) 
{
	stream << other.months[other.getMonth() - 1] << ' ' << other.getDay() << ", " << other.getYear();
	return stream;
}

istream& operator>>(istream& stream, Date& other)
{
	int day, month, year;

	//Set Day
	do {
		try {
			//while loop catches incorrect datatypes
			while (cout << "\nEnter the day: " && !(cin >> day)) {
				cin.clear();
				cin.ignore();
				throw 'e';
			}

			if (day >= 31) { throw 31; }
			else if (day < 0) { throw 0; }
		}
		catch (int param) {
			cout << "\nInvalidDay";
			if (param > 15) {
				cout << endl << "Day cannot be over " << param;
			}
			else cout << endl << "Day cannot be under " << param;
		}
		catch (char param) {
			//This catches incorrect data types
			cout << "\nInvalidDay";
			cout << "\nDay variable must be an integer.";
		}
	} while (day < 1 || day > 31);

	other.setDay(day);
	

	/*
	do {
		cout << "Enter the day: ";
		cin >> day;
	} while (day < 1 || day > 31);
	other.setDay(day);
	*/
	
	//Set Month
	do {
		try {
			//while loop catches incorrect datatypes
			while (cout << "\nEnter the month(1-12): " && !(cin >> month)) {
				cin.clear();
				cin.ignore();
				throw 'e';
			}

			if (month >= 12) { throw 12; }
			else if (month < 0) { throw 0; }
		}
		catch (int param) {
			cout << "\nInvalidDay";
			if (param > 6) {
				cout << endl << "Month cannot be over " << param;
			}
			else cout << endl << "Month cannot be under " << param;
		}
		catch (char param) {
			//This catches incorrect data types
			cout << "\nInvalidMonth";
			cout << "\nMonth variable must be an integer.";
		}
	} while (month < 1 || month > 12);
	other.setMonth(month);

	do {
		cout << "Enter the year (####): ";
		cin >> year;
	} while (year < 0 || year > 9999);
	other.setYear(year);

	cout << endl;

	return stream;

}

void DisplayDates(Date one, Date two) { //displayes two dates only
	int space = 20;

	cout << endl << endl;
	cout << setw(space) << left << "Date 1" << setw(space) << left << "Date 2" << endl;
	cout << setw(space) << left << one.StringSlashes() << setw(space) << left << two.StringSlashes() << endl;
	cout << setw(space) << left << one.StringMDY() << setw(space) << left << two.StringMDY() << endl;
	cout << setw(space) << left << one.StringDMY() << setw(space) << left << two.StringDMY() << endl;

}

void DisplayDifference(Date one, Date two) {
	int difference = one - two; //returns an int of the amount of days ebtween the 2 dates

	cout << "\nAmount of days between " << one << " and " << two << " = " << difference << " days." << endl;
}


int main() {
	int day, month, year;
	Date swag, bag;

	CenterString("Date Formatter");
	cout << endl;

	cin >> swag; //asks for DMY & input validation
	cin >> bag;

	//displaying information
	DisplayDates(swag, bag);

	int difference = swag - bag; //returns an int of the amount of days ebtween the 2 dates

	cout << "\nAmount of days between " << swag << " and " << bag << " = " << difference << " days.";

	//

	char inp;

	do {
		cout << endl << "1. " << setw(12) << right << swag;
		cout << endl << "2. " << setw(12) << right << bag;
		cout << "\n\n\tOptions:";
		cout << "\n\t\t-'1' change date 1.";
		cout << "\n\t\t-'2' change date 2.";
		cout << "\n\t\t-'f' display date formats.";
		cout << "\n\t\t-'d' display amount of days inbetween.";
		cout << "\n\t\t-'q' quit.";

		cout << "\n\n\t-";
		inp = _getch();

		system("CLS");
		inp = toupper(inp);

		switch (inp) {
		case '1':
			cin >> swag;
			break;
		case '2':
			cin >> bag;
			break;
		case 'F':
			DisplayDates(swag, bag);
			break;
		case 'D':
			DisplayDifference(swag, bag);
			break;
		case 'Q':
			cout << "\n\tExiting program.\n";
			break;
		default:
			cout << "\n\tEnter a valid key.\n";
			break;
		}
	} while (inp != 'Q');


	
}

void CenterString(string s) {

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		// an error occourred
		cerr << "Cannot determine console size." << endl;
	}
	else
	{
		//cout << "\n\nThe console is " << csbi.srWindow.Right - csbi.srWindow.Left << " wide." << endl; //checkpoint
	}


	int c_width = csbi.srWindow.Right - csbi.srWindow.Left;
	int length = s.size();
	int position = (int)((c_width - length) / 2);
	for (int i = 0; i < position; i++) {
		cout << ' ';
	}
	cout << s;
}
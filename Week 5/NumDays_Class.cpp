#include <iostream>

using namespace std;

class NumDays {
private:
	int hours;
	double days;
public:
	NumDays() {
		hours = 0;
		days = 0;
	}

	NumDays(int hours) {
		this->hours = hours;
		days = (double)hours / 8;
	}
	void setHours(int hours) {
		this->hours = hours;
		days = (double)hours / 8;
	}

	int getHours() {
		return hours;
	}

	double getDays() {
		return days;
	}

	NumDays operator + (NumDays const& obj) {
		NumDays res;
		res.hours = hours + obj.hours;

		res.days = (double)res.hours / 8;

		return res;
	}
	NumDays operator - (NumDays const& obj) {
		NumDays res;
		res.hours = hours - obj.hours;

		res.days = (double)res.hours / 8;


		return res;
	}

	NumDays operator ++ () { //prefix increment operator
		hours++;

		days = (double)hours / 8;

		return *this;
	}
	NumDays operator ++ (int) { //postfix increment operator §§§§ i++ cout << i++ << ++i
		NumDays temp = *this;
		++* this;


		return temp;
	}

	NumDays operator -- () { //prefix increment operator
		hours--;

		days = (double)hours / 8;


		return *this;
	}

	NumDays operator -- (int) { //postfix increment operator
		NumDays temp = *this;
		--* this;

		return temp;
	}
};

int main() {

	int hours;

	do {
		cout << "Enter the amount of hours worked: ";
		cin >> hours;
		cout << endl;
	} while (hours < 0);

	NumDays work(hours);


	//TESTING OPERATOR FUNCTIONS
	/*NumDays Alex(30); //test

	NumDays total = work + Alex;

	cout << "work() " << work.getHours() << endl;

	work++;

	cout << "work++ = " << work.getHours() << endl;
	cout << "Alex and you worked a total of " << total.getHours() << " hours." << endl; */

	cout << "\n\nYou have worked " << work.getDays() << " days from " << work.getHours() << " work hours.\n";

	//cout << "\n\n\tEdit hours?" << "\n\t\t";

	

}


#include "CustomerData.h"
#include "PersonData.h"

#include <iostream>
#include <string>

using namespace std;

class PreferedCustomer :
	public CustomerData
{
private:
	double purchasesAmount;
	double discountLevel;
public:

	//**********************************************
	// Constructor                                 *
	//**********************************************

	//constructs all 3 classes with ALL data
	PreferedCustomer(string ln, string fn, string addr,
					string c, string s, string z, string ph,
					int cn, bool ml, double pa) 
		: CustomerData(ln, fn, addr, c, s, z, ph, cn, ml) 
	{
		purchasesAmount = pa;
		//determine discounnt leve!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		discountLevel = determineDiscount(purchasesAmount);
	}

	//**********************************************
	// Default Constructor                         *
	//**********************************************
	PreferedCustomer() : CustomerData() {
		purchasesAmount = 0.0;
		discountLevel = determineDiscount(purchasesAmount);
	}

	double determineDiscount(double pa) {
		double d;

		if (pa < 500) {
			d = 0;
		}
		else if (pa < 1000) {
			d = 0.05;
		}
		else if (pa < 1500) {
			d = 0.06;
		}
		else if (pa < 2000) {
			d = 0.07;
		}
		else {
			d = 0.10;
		}

		return d;
	}

	//**********************************************
	// Mutator functions                           *
	//**********************************************
	
	void setPurchaseAmount(int pa) //also updates disountLevel
	{
		purchasesAmount = pa;
		discountLevel = determineDiscount(purchasesAmount);
	}

	//**********************************************
	// Accessor functions                          *
	//**********************************************

	double getPurchaseAmount() {
		return purchasesAmount;
	}

	double getDiscountLevel() {
		return discountLevel;
	}

	
};

ostream& operator<<(ostream& stream, PreferedCustomer& rightside) {
	stream << endl << endl

			<< "Member: " << rightside.getFirstName() << ' ' << rightside.getLastName() << endl
			<< "Customer number " << rightside.getCustomerNumber() << endl
			<< "Discount percentage " << rightside.getDiscountLevel() * 100 << '%' << endl

			<< endl
			<< '\t' << rightside.getAddress() << endl << '\t' << rightside.getCity() << ", " << rightside.getState() << ' ' << rightside.getZip() << endl;


	return stream;
}

string getLastname();
string getFirstname();
string getAddy();
string getCity();
string getState();
string getZIP();
string getPhone();

int getCustNum();
bool getMailList();

double getPurchaseAmount();

bool correctLength(string s, int n);
bool stringIsInt(string s);

int main() {
	//PersonData class variabes: (in order)

		string lastname = getLastname();
		string firstname = getFirstname();
		string address = getAddy();
		string city = getCity();
		string state = getState();
		string zip = getZIP();
		string phone = getPhone();

	//CustomerData class variables (in order)
		int customerNumber = getCustNum();
		bool mailingList = getMailList();

	//PreferredCustomer class variable;
	double purchasesAmount;
	
	system("CLS");

	cout << "\n\n\tWelcome " << firstname << ' ' << lastname << '!' << endl;

	purchasesAmount = getPurchaseAmount();

	//fully construct base & inherited classes
	PreferedCustomer guy(lastname, firstname, address, city, state, zip, phone, customerNumber, mailingList, purchasesAmount);

	cout << guy;
}

string getLastname() {
	string ln;

	cout << "\nLast name: ";
	getline(cin, ln);
	//cin.ignore(); //igores '\n' at the end of line

	while (ln.length() < 1) {
		cout << "\nLast name: ";
		getline(cin, ln);
		cin.ignore(); //igores '\n' at the end of line
	}

	return ln;
}
string getFirstname() {
	string fn;

	cout << "\nFirst name: ";
	getline(cin, fn);
	//cin.ignore(); //igores '\n' at the end of line

	while (fn.length() < 1) {
		cout << "\nFirst name: ";
		getline(cin, fn);
		cin.ignore(); //igores '\n' at the end of line
	}

	return fn;
}
string getAddy() {
	string addy;

	cout << "\nStreet address: ";
	getline(cin, addy);
	//cin.ignore(); //igores '\n' at the end of line

	while (addy.length() < 4) {
		cout << "\nExpected address to contain more information.";
		cout << "\nStreet Address: ";
		getline(cin, addy);
		cin.ignore(); //igores '\n' at the end of line
	}

	return addy;
}
string getCity() {
	string c;

	cout << "\nCity: ";
	getline(cin, c);
	//cin.ignore(); //igores '\n' at the end of line

	while (c.length() < 1) {
		cout << "\nCity: ";
		getline(cin, c);
		cin.ignore(); //igores '\n' at the end of line
	}

	return c;
}
string getState() {
	string s;
	string states[50] = { "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY" };
	
	cout << "\nEnter your state abbrviation, i.e. 'CA'.";
	cout << "\nState: ";
	cin >> s;

	bool correct = false;

	for (int i = 0; i < 50; i++) {
		if (s == states[i]) {
			correct = true;
			break;
		}
	}

	while (!correct) {
		cout << "\nEnter a correct state abbreviation, i.e. '" << states[rand() % 50] << "'."; //just a little extraness :)
		cout << "\nState: ";
		cin >> s;

		for (int i = 0; i < 50; i++) { //check states
			if (s == states[i]) {
				correct = true;
				break;
			}
		}
	}
	return s;
}
string getZIP() {
	string z;

	cout << "\nZIP code: ";
	cin >> z;

	while (!correctLength(z, 5) || !stringIsInt(z)) { //should have sub functions to check correct length and all digits
		"\nEnter correct ZIP code length i.e. #####";
		cout << "\nZIP code: ";
		cin >> z;
	}

	return z;
}
string getPhone() {
	string p;

	cout << "\nDisregard all special characters in phone number.";
	cout << "\nPhone number: ";
	cin >> p;

	while (!stringIsInt(p)) 
	{
		cout << "\nPhone number: ";
		cin >> p;
	}

	return p;
}

int getCustNum() {
	string num;

	cout << "\nCustomer number: ";
	cin >> num;

	while (!stringIsInt(num)) {
		cout << "\nCustomer number: ";
		cin >> num;
	}

	return stoi(num);
}

bool getMailList() {
	char c;

	cout << "\nWould you like to be on the mailing list?";
	cout << "\nEnter 'y' for yes or 'n' for no";
	cout << "\n\t> ";
	cin >> c;

	c = toupper(c);

	while (c != 'Y' && c != 'N') {
		cout << "\n\n\tEnter a valid input.";
		cout << "\nWould you like to be on the mailing list?";
		cout << "\nEnter 'y' for yes or 'n' for no";
		cout << "\n\t> ";
		cin >> c;

		c = toupper(c);
	}

	if (c == 'Y') return true;
	else return false;
}

double getPurchaseAmount() {
	double p;

	cout << "\nEnter how much you have purchased here.";
	cout << "\n\t> ";
	cin >> p;

	while (p < 0 || p > 2000000) //I'm gonna assume 2 mil is too much from a retail store
	{
		cout << "\nEnter a valid amount you have purchased from here.";
		cout << "\n\t> ";
		cin >> p;
	}

	return p;
}

bool stringIsInt(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == false) {
			cout << "\nMust contain only digits, letters and other special characters are not allowed.";
			return false; //this char in the string is not an int
		}
	}


	return true; //for loop finished with no errors, string has all ints
}

bool correctLength(string s, int n) //checks if length of s is equal to n
{
	if (s.length() == n)
	{
		return true;
	}
	else
	{
		if (n == 5/*ZIP code length*/)
		{
			cout << "\nZIP code must be 5 digits long.";
		}
		return false;
	}
}
#include <iostream>
#include <string>

using namespace std;

class temperature {
private:
	int temp;
public:
	temperature(int  t) {
		temp = t;
	}
	temperature() {
		temp = 0;
	}

	void setTemp(int t) {
		temp = t;
	}

	int getTemp() {
		return temp;
	}

	bool isEthylFreezing() { //true if AT or BELOW freezing
		int fp = -173;
		if (temp <= fp) return true;
		else return false;
	}

	bool isEthylBoiling() { //true if AT or ABOVE boiling
		int bp = 172;
		if (temp >= bp) return true;
		else return false;
	}

	bool isOxygenFreezing() { //true if AT or BELOW freezing
		int fp = -362;
		if (temp <= fp) return true;
		else return false;
	}

	bool isOxygenBoiling() {
		int bp = -306;
		if (temp >= bp) return true;
		else return false;
	}

	bool isWaterFreezing() {
		int fp = 32;
		if (temp <= fp) return true;
		else return false;
	}

	bool isWaterBoiling() {
		int bp = 212;
		if (temp >= bp) return true;
		else return false;
	}
};

	int main() {
		int jaakko;

		cout << "Enter a temperature (in Fahrenheit): ";
		cin >> jaakko;

		temperature in(jaakko);

		if (in.isEthylBoiling()) {
			cout << "Ethyl will boil at this temperature" << endl;
		}
		if (in.isEthylFreezing()) {
			cout << "Ethyl will freeze at this temperature" << endl;
		}
		if (in.isOxygenBoiling()) {
			cout << "Ocygen will boil at this temperature" << endl;
		}
		if (in.isOxygenFreezing()) {
			cout << "Oxygen will freeze at this temperature" << endl;
		}
		if (in.isWaterBoiling()) {
			cout << "Water will boil at this temperature" << endl;
		}
		if (in.isWaterFreezing()) {
			cout << "Water will freeze at this temperature" << endl;
		}
	}
#include <iostream>
#include <string>

using namespace std;

class RetailItem {
private:
	string description;
	int unitsOnHand;
	double price;
public:
	RetailItem(string d, int u, double p) {
		description = d;
		unitsOnHand = u;
		price = p;
	}
	void SetDescrition(string d) {
		description = d;
	}
	void SetUnits(int u) {
		unitsOnHand = u;
	}
	void SetPrice(double p) {
		price = p;
	}
	string GetDescription() {
		return description;
	}
	int GetUnits() {
		return unitsOnHand;
	}
	double GetPrice() {
		return price;
	}
};

int main() {
	RetailItem item1("Jacket", 12, 59.95);
	RetailItem item2("Designer Jeans", 40, 34.95);
	RetailItem item3("Shirt", 20, 24.95);
}
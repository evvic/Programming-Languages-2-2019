#include <iostream>

using namespace std;

int main() {
	int amount = 0;

	cout << "How many test scores would you like to enter: ";
	cin >> amount;

	int* oscar = new int(amount);
	//int oscar[amount];

	//pointer-variable = new data-type[size];

	for (int i = 0; i < amount; i++) {
		cout << "\nEnter test score #" << i + 1 << ": ";
		cin >> oscar[i];
	}

	int j, x = 0;

	for (int i = 1; i < amount; i++) {
		x = oscar[i];
		j = i - 1;
		while (j >= 0 && oscar[j] > x) {
			oscar[j + 1] = oscar[j];
			j = j - 1;
		}
		oscar[j + 1] = x;
	}

	cout << endl << "\tTest scores sorted: ";
	for (int i = 0; i < amount; i++) {
		cout << "\nEnter test score #" << i + 1 << "= " << oscar[i];
	}


}

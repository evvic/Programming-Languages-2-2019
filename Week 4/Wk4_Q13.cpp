#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int* students, int num);
double Median(int* students, int num);
int Mode(int* students, int num);

int main() {
	int numStud = 0;
	int total = 0;

	cout << "Enter how many students were surveyed: ";
	cin >> numStud;

	int *students = new int(numStud);



	for (int i = 0; i < numStud; i++) {
		cout << endl << "Enter the number of movies student #" << i + 1 << " watched this month: ";
		cin >> *(students + i);
		total += *(students + i);
	}

	double average = (double)total / numStud;

	insertionSort(students, numStud);

	double median = Median(students, numStud);

	int mode = Mode(students, numStud);


	cout << endl << endl;
	cout << '\t' << "Average movies watched: " << average << endl;
	cout << '\t' << "Median: " << median << endl;
	cout << '\t' << "Mode: " << mode << endl;

}

int Mode(int* students, int num) {

	int mode = students[0];

	int counter = 1;
	int counterTwo = 0;

	for (int i = 0; i < num - 1; i++)
	{
		if (students[i] == students[i + 1])
		{
			counter++;
			if (counter > counterTwo)
			{
				counterTwo = counter;
				mode = students[i];
			}
			else
			{
				counter = 1; // Reset counter
			}
		}
	}

	return mode;
	//straight up copied this
}

double Median(int* students, int num) {
	int mid;
	
	//this might be backwards or something check it out
	if (num % 2 == 1) { //odd
		mid = (num / 2);
		
		//return (students[mid] + students[mid + 1]) / 2;
		return students[mid];
	}

	else { //even
		mid = (num / 2);
		return (double)(students[mid] + students[mid - 1]) / 2.0;
	}
}

void insertionSort(int* students, int num) {

	int j, x = 0;

	for (int i = 1; i < num; i++) {
		x = students[i];
		j = i - 1;
		while (j >= 0 && students[j] > x) {
			students[j + 1] = students[j];
			j = j - 1;
		}
		students[j + 1] = x;
	}
}
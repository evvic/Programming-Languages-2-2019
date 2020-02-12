#include <iostream>
#include <string>
#include <iomanip> //for setprecision()

using namespace std;

class circle {
private:
	double radius;
	double pi = 3.14159;
public:
	circle() {
		radius = 0;
	}
	circle(double r) {
		radius = r;
	}

	void setRadius(double r) {
		radius = r;
	}
	double getRadius() {
		return radius;
	}

	double getArea() {
		return pi * radius * radius;
	}

	double getDiameter() {
		return radius * 2;
	}

	double getCircumference() {
		return 2 * pi * radius;
	}
};

int main() {
	double r;
	cout << "Enter radius of a circle: ";
	cin >> r;

	circle swag(r);

	cout << "\nArea: " << setprecision(2) << swag.getArea();
	cout << "\nDiameter: " << setprecision(2) << swag.getDiameter();
	cout << "\nCircumference: " << setprecision(2) << swag.getCircumference();
}
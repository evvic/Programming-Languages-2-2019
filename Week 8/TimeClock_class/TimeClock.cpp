#include "Time.h"
#include "MilTime.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


using namespace std;


class TimeClock :
	public MilTime
{
private:
	//first - second = difference
	MilTime first;
	MilTime second;
public:
	TimeClock(int h1, int s1, int h2, int s2) : 
	MilTime(0, 0)
	{
		first.setTime(h1, s1);
		second.setTime(h2, s2);


		this->DifferenZe(); //sets difference between time and saves it in constructor

	}

	TimeClock() : MilTime(0, 0) {
		first.setTime(0, 0);
		second.setTime(0, 0);
	}

	//scrapping this version of difference
	void Difference() { //this function sets this->MilTime to the actual difference between first and second

		cout << "\nEntered Difference()\n";

		int difSec = first.getSec();
		int changeHour = first.getHour();
		int changeMin = first.getHour() / 100;
		changeMin = first.getHour() - (changeMin * 100);

		if (second.MilTime::getSec() > first.MilTime::getSec()) { //if 2nd seconds is larger we must do this to change the minutes
			difSec = 60 + first.MilTime::getSec() - second.MilTime::getSec(); //save this

			changeMin -= 1; //removed a minute

			if (changeMin > 59) { //if the minutes has been affected badly, fix it here
				changeMin -= 40;
			}

			if (changeMin < 0) {
				changeMin += 60;
				changeHour = first.getHour() - 100;
			}
			changeHour += changeMin;
		}

		int difHour = changeHour - second.getHour();

		difHour = changeHour * 100 + changeMin;

		this->setTime(difHour, difSec); //set the MilTime difference

	}

	void DifferenZe() {
		//cout << "DifferenZe() " << endl;

		Time first = MyConvert(this->first);
		Time second = MyConvert(this->second);

		//difference in seconds
		int dsec = first.getSec() - second.getSec();

		//cout << "\ndsec: " << dsec;

		//subtract a min from first if sec is neg
		if (dsec < 0)
		{
			first.setMin(first.getMin() - 1);
			dsec += 60;
		}

		//check if first min went negative
		if (first.getMin() < 0)
		{
			first.setHour(first.getHour() - 1);
			first.setMin(first.getMin() + 60);
		}

		//cout << "\npost dsec: " << dsec;

		//differnce in minutes
		int dmin = first.getMin() - second.getMin();

		//cout << "\ndmin: " << dmin;

		//subtract an hour if if min is neg
		if (dmin < 0)
		{
			first.setHour(first.getHour() - 1);
			dmin += 60;
		}

		//cout << "\npost dmin: " << dmin;


		//difference in hours
		int dhour = first.getHour() - second.getHour();

		//cout << "\ndhour: " << dhour;

		//sets TimeClock MilTime this-> to the difference
		this->setTime((dhour * 100) + dmin, dsec);

		this->setHour(dhour);
		this->setMin(dmin);
		this->setSec(dsec);
	}


	//				FIX
	Time MyConvert(MilTime tiem) //cause I don't like the given one in MilTime.h
	{
		int mHour = tiem.getHour(); //automatically changing hour
		int tempMin, tempHour; //temp vars
		int tempSec = tiem.getMilSec();

		tempHour = mHour / 100;

		tempMin = mHour - (tempHour * 100);

		Time temp(tempHour, tempMin, tempSec);
		//cout << "\ntempHour: " << tempHour << "   tempMin: " << tempMin << "   tempSec: " << tempSec;

		return temp;
	}

	//Prints this-> for hour:min:sec difference
	void PrintDifference() {
		//cout << "\nEntered PrintDifference()\n";
		cout << endl;
		cout << "Difference: " << endl;
		cout << this->Time::getHour() << ':' << this->getMin() << ':' << this->getSec();
	}
};

int RandomMilTime();
string ConvertMilToReg(int mil);


int main() {

	srand(time(0)); //random seed

	int hour[2] = { 0, 0 };
	int sec[2] = { 0, 0 };
	int rand;

	cout << "\tTime Clock";
	cout << endl << "\tThis compares two times and gives the difference between them." << endl;

	for (int i = 0; i < 2; i++) {
		string grammar;

		switch (i) {
		case 0:
			grammar = "st";
			break;
		case 1:
			grammar = "nd";
			break;
		default:
			grammar = "";
			cout << "error in switch statement.";
			break;
		}

		do {
			rand = RandomMilTime();
			cout << endl << "Enter " << i + 1 << grammar << " hour.";
			cout << endl << "Must be in military time form (i.e. " << ConvertMilToReg(rand) << " = " << rand << ").";
			cout << endl << '\t' << "> ";
			cin >> hour[i];
		} while (hour[i] < 0 || hour[i] > 2400);

		do {
			cout << endl << "Enter " << i + 1 << grammar << " second.";
			cout << endl << '\t' << "> ";
			cin >> sec[i];
		} while (sec[i] < 0 || sec[i] > 59);
	}



	/*for (int i = 0; i < 2; i++) //checkpoint
	{
		cout << "\nHour 1: " << hour[i] << "   sec 1: " << sec[i];
	}	*/


	TimeClock what(hour[0], sec[0], hour[1], sec[1]);

	what.PrintDifference();
}

int RandomMilTime() {
	int min = rand() % 60;
	int hour = rand() % 24;
	
	return (hour * 100) + min;
}

string ConvertMilToReg(int mil) {
	string m = "error";

	int hour = mil / 100;
	int min = mil - (hour * 100);

	if (hour > 12) {
		m = "pm";
		hour -= 12;
	}
	else m = "am";

	string shour = to_string(hour);


	string smin = to_string(min);

	string final = shour + ":" + smin + " " + m;

	return final;
}
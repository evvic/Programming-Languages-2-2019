// Specification file for the MilTime class

//IMPORTANT!!!
//This given (shell of a) class was not explained well, so I might be defining the functions incorrectly to how I imagine they should work

/*
Assuming MilTime converts given time to a different format.  MILITARY FORMAT8
i.e. 3:30 pm => 1530 (hours) or 7:45 am => 0745 (hours)
*/

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime :
	public Time
{
private:
	int milHours; //holds both hours and minutes i.e. 2:45 => 0245
	int milSeconds;
public:
	MilTime(int h, int s) {
		milHours = h;
		milSeconds = s;
		convert();
	}

	MilTime() : Time() {
		milHours = 0;
		milSeconds = 0;
	}

	void convert() { //converting military time to regular time with time variables
		char m; //stores if it is am or pm

		int tempMin, tempHour; //temp vars
		int tempSec = milSeconds;

		if (milHours > 1200) {
			//What is the point of this?
			//Like if the point is to compare the difference in times why would I want it to AUTOMATICALLY remove 12 hours
			//before mathematically finding the difference?

			//milHours -= 1200;
			m = 'p'; //pm
		}
		else {
			m = 'a'; //am
		}

		tempMin = milHours % 60;
		tempHour = milHours / 1000;

		setHour(tempHour);
		setMin(tempMin);
		setSec(tempSec);
	}

	void setTime(int h, int s) {
		milHours = h;
		milSeconds = s;
		convert(); //to regular time
	}

	int getHour()
	{
		return milHours;
	}

	int getMilSec() { return milSeconds; }

	int getStandHr()
	{
		return hour;
	}
};

#endif

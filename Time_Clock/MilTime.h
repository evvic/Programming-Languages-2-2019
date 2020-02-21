// Specification file for the MilTime class
#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"
 
// Declaration of the MilTime class

class MilTime : public Time
{
private:
	int milHours;
	int milSeconds;
public:
	MilTime(int h, int s) {
		milHours = h;
		milSeconds = s;
	}

	MilTime() {
		milHours = 0;
		milSeconds = 0;
	}

	void convert() { //milHour min

	}

	void setTime(int h, int s) {
		milHours = h;
		milSeconds = s;
		convert();
	}

	int getHour()
	{
		return milHours;
	}

	int getStandHr()
	{
		return hour;
	}
};

#endif
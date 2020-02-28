#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
protected:
	int hour;
	int min;
	int sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	Time() { hour = 0; min = 0; sec = 0; }

	void setHour(int h) { hour = h; }
	void setMin(int m) { min = m; }
	void setSec(int s) { sec = s; }

	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }

	Time operator=(Time after) {
		hour = after.hour;
		min = after.min;
		sec = after.sec;

		return *this;
	}

};

#endif

#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include "MilTime.h"


class TimeClock : public MilTime
{
private:
	Time start;
	Time end;
public: 
	TimeClock() { 
		

	}
	TimeClock(Time s, Time e) {
		start = s;
		end = e;
	}


};

#endif

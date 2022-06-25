#pragma once
#include <Windows.h>
#include <iostream>

class Time
{
	unsigned short sec;
	unsigned short min;
	unsigned short hours;

public:

	Time();
	Time(unsigned short sec, unsigned short min, unsigned short hours);

	void set_sec(unsigned short sec);
	void set_min(unsigned short min);
	void set_hours(unsigned short hours);

	unsigned short get_sec() { return sec; }
	unsigned short get_min() { return min; }
	unsigned short get_hours() { return hours; }

	Time operator+(unsigned short sec);
	Time operator-(unsigned short sec);

	bool operator==(Time& time);
	bool operator!=(Time& time);
	bool operator<(Time& time);
	bool operator>(Time& time);
	friend std::ostream& operator<<(std::ostream& ost, const Time& time);
	friend std::istream& operator>>(std::istream& ist, Time& time);

	void Print();
};


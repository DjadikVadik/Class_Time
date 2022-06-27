#include "Time.h"

Time::Time()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	sec = st.wSecond;
	min = st.wMinute;
	hours = st.wHour;
}

Time::Time(unsigned short sec, unsigned short min, unsigned short hours)
{
	set_sec(sec);
	set_min(min);
	set_hours(hours);
}

void Time::set_sec(unsigned short sec)
{
	if (sec >= 0 && sec < 60) this->sec = sec;
	else throw std::exception("seconds value is not correct!!!");
}

void Time::set_min(unsigned short min)
{
	if (min >= 0 && min < 60) this->min = min;
	else throw std::exception("minutes value is not correct!!!");
}

void Time::set_hours(unsigned short hours)
{
	if (hours >= 0 && hours < 24) this->hours = hours;
	else throw std::exception("hours value is not correct!!!");
}

Time Time::operator+(unsigned short sec)
{
	if (sec == 0) return *this;
	else 
		while (sec != 0)
		{
			this->sec++;
			sec--;
			if (this->sec > 59) {
				this->min++;
				this->sec = 0;
			}
			if (this->min > 59) {
				this->hours++;
				this->min = 0;
			}
			if (this->hours > 23) this->hours = 0;
		}
}

Time Time::operator-(unsigned short sec)
{
	if (sec == 0) return *this;
	else
		while (sec != 0)
		{
			this->sec--;
			sec--;
			if (this->sec > 59) {
				this->min--;
				this->sec = 59;
			}
			if (this->min > 59) {
				this->hours--;
				this->min = 59;
			}
			if (this->hours > 23) this->hours = 23;
		}
}

Time& Time::operator++()
{
	sec++;

	if (sec > 59) {
		min++;
		sec = 0;
	}
	if (min > 59) {
	    hours++;
		min = 0;
	}
	if (hours > 23) hours = 0;

	return *this;
}

Time Time::operator++(int)
{
	Time clone = *this;

	sec++;

	if (sec > 59) {
		min++;
		sec = 0;
	}
	if (min > 59) {
		hours++;
		min = 0;
	}
	if (hours > 23) hours = 0;

	return clone;
}

Time& Time::operator--()
{
	
	sec--;
	if (sec > 59) {
		min--;
		sec = 59;
	}
	if (min > 59) {
		hours--;
		min = 59;
	}
	if (hours > 23) hours = 23;

	return *this;
}

Time Time::operator--(int)
{
	Time clone = *this;

	sec--;
	if (sec > 59) {
		min--;
		sec = 59;
	}
	if (min > 59) {
		hours--;
		min = 59;
	}
	if (hours > 23) hours = 23;

	return clone;
}

bool Time::operator==(Time& time)
{
	return hours == time.hours && min == time.min && sec == time.sec;
}

bool Time::operator!=(Time& time)
{
	return hours != time.hours || min != time.min || sec != time.sec;
}

bool Time::operator<(Time& time)
{
	if (hours < time.hours) return true;
	else if (hours > time.hours) return false;

	if (min < time.min) return true;
	else if (min > time.min) return false;

	if (sec < time.sec) return true;
	return false;
}

bool Time::operator>(Time& time)
{
	if (hours > time.hours) return true;
	else if (hours < time.hours) return false;

	if (min > time.min) return true;
	else if (min < time.min) return false;

	if (sec > time.sec) return true;
	return false;
}

std::ostream& operator<<(std::ostream& ost, const Time& time)
{
	ost << time.hours << ":" << time.min << ":" << time.sec;
	return ost;
}

std::istream& operator>>(std::istream& ist, Time& time)
{
	ist >> time.hours >> time.min >> time.sec;
	time.set_hours(time.hours);
	time.set_min(time.min);
	time.set_sec(time.sec);
	return ist;
}

void Time::Print()
{
	std::cout << hours << ":" << min << ":" << sec;
}
#include <iostream>
#include "Timer.h"
#define NDEBUG
const double Time::hourToDec = 1. / 3600.;

void Time::normalizeTime() 
{
	// обробляє атрибути поточного об'єкта 

	_hours += ((_minutes + (_seconds / 60)) / 60);
	_minutes = (_minutes + (_seconds / 60)) % 60; 
	_seconds %= 60;
}

Time::Time(const int s, const int m, const int h)
	:_hours(h), _minutes(m), _seconds(s)
{
#ifndef NDEBUG
	cout << "Time created: " << *this << endl;
#endif
	normalizeTime();
	return;
}

Time::~Time()
{
#ifndef NDEBUG
	cout << "Time deleted: " << *this << endl;
#endif
}

const Time& Time::operator++() 
{
	 _seconds+=1;
	 normalizeTime();
	return *this;
}

const Time Time::operator++(int)
{
	const Time temp(*this);
	_seconds += 1;
	normalizeTime();
	return temp;
}

const Time& Time::operator--()
{
	const int n = static_cast<int>(*this);
	if (n > 0)
	{
		_hours = 0;
		_minutes = 0;
		_seconds = n - 1;
	}
	normalizeTime();
	return *this;
}

const Time Time::operator--(int)
{
	const Time temp(*this);
	const int n = static_cast<int>(*this);
	if (n > 0)
	{
		_hours = 0;
		_minutes = 0;
		_seconds = n - 1;
	}
	normalizeTime();
	return temp;
}


Time::operator int() const {
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	return _hours + (static_cast<double>(_minutes)/60) + static_cast<double>(_seconds)/3600;
}


double operator+(const Time& a, const Time& b){
	return int(a)* Time::hourToDec + int(b)* Time::hourToDec;
}

ostream& operator<<(ostream& os, const Time& time)
{
	return os << time.hours() << ":" << time.minutes() << ":" << time.seconds() << endl;
}

// Модифікатор годин
void Time::setHours(const unsigned int h) {
	_hours = h; normalizeTime();
	return;
}
// Модифікатор хвилин
void Time::setMinutes(const unsigned int m) {
	_minutes = m; normalizeTime();
	return;
}
// Модифікатор секунд
void Time::setSeconds(const unsigned int s) {
	_seconds = s; normalizeTime();
	return;
}



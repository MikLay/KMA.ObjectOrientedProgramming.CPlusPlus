#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG

#include "Date.h"
#include <ctime>
#include <iostream>
using namespace std;

string Date::monthNames[12] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

bool Date::defaultSet = true;
Date Date::defaultDate = Date();

Date::~Date()
{
#ifndef NDEBUG
	cout << "Date deleted: " << *this << endl;
#endif
}

void Date::setDefault()
{
	// Обробка таймера й ініціалізація поточного дня в змінній timer
	time_t timer;
	time(&timer);

	// Створення указника на поточну дату
	// Тип таймера tm узято з бібліотеки ctime
	struct tm* today = gmtime(&timer);

	// Вибір дня, місяця та року із указника today
	defaultDate._day = today->tm_mday;
	defaultDate._month = ++(today->tm_mon);
	defaultDate._year = today->tm_year += 1900;

	defaultSet = false;
}

bool Date::leapYear(int y)
{
	return y % 4 == 0;
}

void Date::fillDate(int d, Month m, int y)
{
	if (defaultSet)
	{
		setDefault();
	}
#ifndef NDEBUG
	cout << "Data constructor _defaultDate: " << defaultDate;
#endif


	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;

	int numberOfDays = 0;


	switch (_month)
	{
	case feb:
		numberOfDays = 28 + leapYear(y);
		break;
	case apr:
	case jun:
	case sep:
	case nov:
		numberOfDays = 30;
		break;
	case jan:
	case mar:
	case may:
	case jul:
	case aug:
	case oct:
	case dec:
		numberOfDays = 31;
		break;

	default: throw BadDate(_day, _month, _year);
	}
	// Перевірка коректності дня та року
	if ((_day < 1) || (numberOfDays < _day) || (_year < 0))
		throw BadDate(_day, _month, _year);

#ifndef NDEBUG
	cout << "Data constructor: " << *this;
#endif
};


void Date::showDefault()
{
	cout << defaultDate;
}

const Date& Date::operator++()
{
	switch (_month)
	{
	case dec:
		if (_day == 31)
		{
			_month = 1;
			_day = 1;
			++_year;
		}
		else { ++_day; }
		break;
	case feb:
		if (leapYear(_year) && _day == 29 || (_day == 28 && !leapYear(_year)))
		{
			_day = 1;
			++_month;
		}
		else { ++_day; }
		break;

	case apr:
	case jun:
	case sep:
	case nov:
		if (_day == 30)
		{
			_day = 1;
			++_month;
		}
		else { ++_day; }
		break;
	default:
		if (_day == 31)
		{
			_day = 1;
			++_month;
		}
		else
		{
			++_day;
		}
	}
	return *this;
}


const Date Date::operator++(int)
{
	Date temp(*this);
	++*this;
	return temp;
}

const Date& Date::operator--()
{
	switch (_month)
	{
	case jan:
		if (_day == 1)
		{
			_month = 12;
			_day = 31;
			--_year;
		}
		else { --_day; }
		break;
	case mar:
		if (_day == 1)
		{
			_day = leapYear(_year) ? 29 : 28;
			--_month;
		}
		else { --_day; }
		break;

	case apr:
	case jun:
	case aug:
	case sep:
	case nov:
		if (_day == 1)
		{
			_day = 31;
			--_month;
		}
		else { --_day; }
		break;
	default:
		if (_day == 1)
		{
			_day = 30;
			--_month;
		}
		else
		{
			--_day;
		}
	}
	return *this;
}

const Date Date::operator--(int)
{
	Date temp(*this);
	++*this;
	return temp;
}

bool Date::operator<(const Date& a) const
{
	if(_year > a.year() )
	{
		return false;
	}else if(a.year() == _year)
	{
		if(_month >a.month())
		{
			return false;
		}else if(a.month() == _month)
		{
			if (_day >=a.day())
				return false;
		}
	}
	return true;
}



ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
	os << bd._day << ":" << bd._month << ":" << bd._year;
	return os;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day() << ' ' << Date::Month(d.month()) << ' ' << d.year() << endl;
	return os;
}

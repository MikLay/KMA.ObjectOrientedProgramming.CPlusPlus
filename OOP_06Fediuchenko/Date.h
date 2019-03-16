#pragma once
#pragma once
#include <iostream>
using namespace std;

class Date

{
public:

	struct BadDate;


	// to avoid problem 7.2.2002 7 feb or jul 2?

	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


	Date(int d = 0, Month m = Month(0), int y = 0)
	{
		fillDate(d, m, y);
	};

	Date(int d, int m, int y) { fillDate(d, Month(m), y); };

	Date(const Date& date) { fillDate(date.day(), date.month(), date.year()); };


	~Date();


	int day() const { return _day; };

	Month month() const { return Month(_month); };

	int year() const { return _year; };

	const std::string getMonthName() const { return monthNames[_month]; };

	void setDay(int day) { _day = day; };

	void setMonth(int month) { _month = month; };

	void setYear(int year) { _year = year; };


	static void setDefault(int d, Month m, int y) { defaultDate = Date(d, m, y); };

	static void setDefault();

	static void showDefault();

	// Declare prefix and postfix increment operators.
	const Date& operator++(); // Prefix increment operator.
	const Date operator++(int); // Postfix increment operator.

	// Declare prefix and postfix decrement operators.
	const Date& operator--(); // Prefix decrement operator.
	const Date operator--(int); // Postfix decrement operator.

	bool operator < (const Date& a) const;

private:

	int _day, _month, _year;


	static bool leapYear(int y);

	void fillDate(int d, Month m, int y);

	static string monthNames[12];

	static bool defaultSet;

	static Date defaultDate;
};

inline bool operator==(Date& a, Date& b)
{
	return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

inline bool operator!=(Date& a, Date& b)
{
	return !(a == b);
}


ostream& operator<<(ostream& os, const Date& d);


struct Date::BadDate

{
	int _day, _month, _year;

	BadDate(int d, int m, int y) : _day(d), _month(m), _year(y)
	{
	};
};


ostream& operator<<(ostream& os, const Date::BadDate& bd);


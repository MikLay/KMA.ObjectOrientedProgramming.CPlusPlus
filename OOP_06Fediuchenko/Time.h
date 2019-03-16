#pragma once
#include  <iostream>
using namespace std;
//---------------------------------------

//1. ���������� ���� Time

//

//2. ���������� ������, ���� ���������

//��������� ��� (���� Date) � ������� ���

//� ���� ������ ����� ������� ��������

//���� ���� ��������

//---------------------------------------

class Time

{

private:

	int _hours;

	int _minutes;

	int _seconds;

	//������� ��������, � ���� �������

	void normalizeTime();


public:

	static const double hourToDec;

	explicit Time(const int s = 0, const int m = 0, const int h = 0);

	Time(const Time& time) : _hours(time._hours), _minutes(time._minutes), _seconds(time._seconds)  { return; };

	~Time();


	Time& operator=(const Time& time)
	{
		_hours = time._hours;
		_minutes = time._minutes;
		_seconds = time._seconds;
		return *this;
	};

	explicit operator int() const;

	explicit operator double() const;


	int hours() const { return _hours; }

	int minutes() const { return _minutes; }

	int seconds() const { return _seconds; }


	int& hours() { return _hours; }

	int& minutes() { return _minutes; }

	int& seconds() { return _seconds; }

	void setHours(const unsigned int h);

	void setMinutes(const unsigned int m);

	void setSeconds(const unsigned int s);

	//���� �������� ������� �� ���� �������

	const Time& operator++();

	const Time operator++(int);

	const Time& operator--();

	const Time operator--(int);

	bool operator<(const Time& a) const
	{
		return static_cast<int>(*this) < static_cast<int>(a);
	}
};

//��������� ������� �������

double operator + (const Time&, const Time&);

ostream& operator<<(ostream&, const Time &);
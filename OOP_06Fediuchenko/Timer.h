#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"
using namespace std;

class Timer
{
private:
	Date _alarmDate;
	Time _alarmTime;
	Time _diapazon;

public:
	Date alarmDate() const
	{
		return _alarmDate;
	}

	Date& alarmDate()
	{
		return _alarmDate;
	}

	void setAlarmDate(const Date& date)
	{
		_alarmDate = date;
	}

	Time alarmTime() const
	{
		return _alarmTime;
	}

	Time& alarmTime()
	{
		return _alarmTime;
	}

	void setAlarmTime(const Time& time)
	{
		_alarmTime = time;
	}

	Time diapazon() const
	{
		return _diapazon;
	}

	Time& diapazon()
	{
		return _diapazon;
	}

	void setDiapazon(const Time& time)
	{
		_diapazon = time;
	}


	Timer(const Date& date, const Time& time, const Time& time1)
		: _alarmDate(date),
		  _alarmTime(time),
		  _diapazon(time1)
	{
	}

	Timer(const int d, const int m, const int y, const int inH, const int inM, const int inS, const int diapH, const int diapM, const int diapS):
		_alarmDate(d, m, y), _alarmTime(inH, inM, inS), _diapazon(diapH, diapM, diapS)
	{
	}

	~Timer()
	{
	}

	void turnOnAlarm();

	static long difftime(Date&dateOne, Date& dateTwo, Time& timeOne, Time& timeTwo);

};

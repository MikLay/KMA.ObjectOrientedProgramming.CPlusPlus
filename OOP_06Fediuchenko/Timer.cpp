#define _CRT_SECURE_NO_WARNINGS
#include "Timer.h"
#include <ctime>
#include <thread>
using namespace std;

void Timer::turnOnAlarm()
{

	time_t timer;
	time(&timer);
	// Створення указника на поточну дату
	// Тип таймера tm узято з бібліотеки ctime
	struct tm* today = gmtime(&timer);

	long time = 0;

	Date currentDate(today->tm_mday, ++(today->tm_mon), today->tm_year += 1900);
	Time currentTime(today->tm_sec, today->tm_min,today->tm_hour+2);
	cout << "Current time!!: " << currentTime;
	try
	{
		time = difftime(currentDate, _alarmDate, currentTime, _alarmTime);

	}
	catch (const char* e)
	{
		cout << e << endl;
		return;
	}

	cout <<"Sleep for:  "<< time << endl;
	std::this_thread::sleep_for(std::chrono::seconds(time));
	cout << "Alarm started!" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(static_cast<int>(_diapazon)));
	cout << "!!!!!!!!!!!!!!!!!!!!!!!" << "\a\a\a\a\a\a" << endl;
}

long Timer::difftime(Date& dateOne, Date& dateTwo, Time& timeOne, Time& timeTwo)
{	
	if (dateTwo < dateOne)
		throw "Wrong date input";


	Date tempDate(dateOne);
	long secondsBetween = 0;

	if(dateTwo == tempDate)
	{
		if (timeTwo < timeOne)
			throw "Wrong time input";

		secondsBetween += static_cast<int>(timeTwo) - static_cast<int>(timeOne);
		return secondsBetween;
	}
	else {
		while (dateTwo != tempDate)
		{
			secondsBetween += 86400;
			++tempDate;
		}
		secondsBetween -= 86400;
		secondsBetween += (86400 - static_cast<int>(timeOne)) + static_cast<int>(timeTwo);
		return  secondsBetween;
	}
}

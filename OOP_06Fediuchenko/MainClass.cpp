#include <iostream>
#include  "Timer.h"
#include  "Date.h"
#include "Time.h"
#include <thread>
using namespace std;

void runInThread()
{
	try {
		const Time firstBegin(0, 47, 15);
		const Time interval(5, 0, 0);
		const Date startDate(23, 3, 2019);

		Timer timer(startDate, firstBegin, interval);
			timer.turnOnAlarm();
	}catch(Date::BadDate& e)
	{
		cout << e << endl;
	}
}


int main()
{
	try {
		// Test Time
		{
			cout << "-+-+-+-+-+-+- #1 Test Time -+-+-+-+-+-+-" << endl;
			const Time first(0, 46, 15);
			cout << "Created and normalized Time: " << first;
			Time second(first);
			cout << "Copied by constructor Time: " << second;
			Time third(59, 24, 1);
			second = third;
			cout << "Time second: " << second;

			// Test increments and decrements
				// Increment 
			cout << "Time before increment: " << second;
			cout << "Time after prefix increment: " << ++second << endl;
			cout << "Test postfix increment before: " << (third = second++);
			cout << "Test postfix increment after: " << second;

			// Decrement
			cout << "Time before decrement: " << second;
			cout << "Time after prefix deccrement: " << --second << endl;
			cout << "Test postfix decrement before: " << (third = second--);
			cout << "Test postfix decrement after: " << second;

			// Test + operator
			cout << "First Time + Second Time : " << first + second << endl;

		}

		// Test Timer
		// TODO For testing Timer pls enter possible (validated) Date and Time
		{
			cout << "-+-+-+-+-+-+- #2 Test Timer -+-+-+-+-+-+-" << endl;
			// Run in thread
			std::thread first(runInThread);
			cout << "We have created new Alarm clock: ";
			first.join();
		}
	}catch (Date::BadDate& e)
	{
		cout << e << endl;
	}
		return 0;
}
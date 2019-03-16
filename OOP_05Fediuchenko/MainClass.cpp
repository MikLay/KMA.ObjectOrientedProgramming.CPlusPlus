#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	cout << "START:" << endl;
	try
	{
		cout << "Default date: ";
		Date::showDefault();
		
		// Set new default date
		Date::setDefault(1, Date::Month(1), 1970);
		cout << "Default new date: ";
		Date::showDefault();

		// Create new Date
		Date d, d1(14, 10, 1991), d2(d1);
		Date x(48, 14, 2008);
	}
	catch (Date::BadDate bd)
	{
		cerr << "Bad date: " << bd << endl;
	}

	try
	{
		// Test decrement
		Date d1(1, 1, 1991);
		cout << "Date before decrement: " << d1 << endl;
		--d1;
		cout << "Date after decrement: " << d1 << endl;

		// Test increment
		Date d2(31, 1, 1991);
		cout << "Date before increment: " << d2;
		++d2;
		cout << "Date after increment: " << d2;
		
		// Test set month, day, year
		d2.setDay(12);
		d2.setMonth(4);
		d2.setYear(2014);
		cout << "Date: " << d2;
		
		// Test postfix increment
		d1 = d2++;
		cout <<"Test postfix increment: \n"<<d1 << endl;
		cout << d2 << endl;
	}
	catch (Date::BadDate bd)
	{
		cerr << "Bad date: " << bd << endl;
	}

	cout << "END" << endl;
	return 0;
}

#include "Screen.h"
#include <iostream>
using namespace std;

int main()
{
	{
		Screen s1(5, 2);
		Screen s2(51, 51);
		Screen s3(10, 10, "Amazing world");
		cout << "\nShow S3:" << endl;
		s3.show();

		cout << "\nTest move and get for 15 times: " << "\n----------------------------" << endl;

		for (int i = 0; i < 15; ++i)
		{
			s3.move();
			cout << s3.get() << endl;
		}

		cout << "----------------------------" << endl;
		// Test methods

		cout << "\nTest S3 home:" << s3.home() << endl;
		cout << "\nMove cursor to (1,1): ";
		s3.move(1, 1).showCurrent();
		cout << "\nInsert new sign, get it: " <<
			s3.move().set('!').get() << endl;
	}
	auto action = 0;
	auto count = 1;

	{
		// Const
		const Screen s4(30, 30, "Now I am testing const Action!");
		const ConstAction const_menu[] = {
			&Screen::move,
			&Screen::back,
			&Screen::home,
			&Screen::show,
			&Screen::showCurrent
		};
		cout << endl << "Const Action: " << endl;

		auto askAgain = true;
		while (askAgain)
		{
			cout << endl << "0 - move()" << endl;
			cout << "1 - back()" << endl;
			cout << "2 - home()" << endl;
			cout << "3 - show()" << endl;
			cout << "4 - showCurrent()" << endl;
			cout << "5 - stop" << endl;
			cin >> action;
			switch (action)
			{
			case 0:
			case 1: cout << "How many times?" << endl;
				cin >> count;
				while (!count)
				{
					cout << "How many times?" << endl;
					cin >> count;
				}
				break;
			case 2:
			case 3:
			case 4: count = 1;
				break;
			case 5:
				askAgain = false;
				break;
			default:
				continue;
			}

			if (askAgain)
			{
				doActionConst(s4, const_menu[action], count);
			}
		}
	}

	{
		// Not const
		Screen s5(25, 25, "Test not const actions");
		NonConstAction non_const_menu[] = {

			&Screen::move,
			&Screen::back,
			&Screen::home,
			&Screen::show,
			&Screen::clear
		};
		cout << "Not Const Action: " << endl;
		auto askAgain = true;
		while (askAgain)
		{
			cout << endl << "0 - move()" << endl;
			cout << "1 - back()" << endl;
			cout << "2 - home()" << endl;
			cout << "3 - show()" << endl;
			cout << "4 - showCurrent()" << endl;
			cout << "5 - stop" << endl;
			cin >> action;
			switch (action)
			{
			case 0:
			case 1: cout << "How many times?" << endl;
				cin >> count;
				while (!count)
				{
					cout << "How many times?" << endl;
					cin >> count;
				}
				break;
			case 2:
			case 3:
			case 4: count = 1;
				break;
			case 5:
				askAgain = false;
				break;
			default:
				continue;
			}

			if (askAgain)
			{
				doActionNonConst(s5, non_const_menu[action], count);
			}
		}
	}
	return 0;
}

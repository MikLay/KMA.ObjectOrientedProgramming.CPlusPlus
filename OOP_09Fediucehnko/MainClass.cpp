#include "Array.h"
#include "Time.h"

using namespace std;

int main()
{
	{
		cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Test array with double =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" <<
			endl;
		try
		{
			Array<10, double> arrOfInt;

			for (int i = 0, len = arrOfInt.size(); i < len; ++i)
			{
				arrOfInt[i] = i * i + 0.5;
				cout << "arrOfint[" << i << "]: " << arrOfInt[i] << endl;
			}

			cout << arrOfInt[10];
		}
		catch (const Array<10, double>::BadArray& badArray)
		{
			badArray.diagnose();
		}
	}

	{
		cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Test array with Time =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" <<
			endl;

		try
		{
			Array<5, Time> arrOfTime;
			const Time t1(1, 1, 1);
			for (size_t i = 0; i < arrOfTime.size(); i++)
			{
				arrOfTime[i] = Time(i * i + 1, i + i * 61, i + i * 2);
			}

			for (size_t i = 0; i < arrOfTime.size(); i++)
			{
				cout << "arrOfTime[" << i << "]: " << arrOfTime[i] << endl;
			}
		}
		catch (const Array<5, Time>::BadArray& badArray)
		{
			badArray.diagnose();
		}
	}

	{
		cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Test array move and assign =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" <<
			endl;

		Array<2, Time> arrOfTime;
		const Time t1(19, 2, 1);
		arrOfTime[0] = t1;
		const Time t2(2, 4, 5);
		arrOfTime[1] = t2;
		Array<2, Time> arrOfTime2 = move(arrOfTime);
		
		for (size_t i = 0; i < arrOfTime2.size(); i++)
		{
			cout << "arrOfTime[" << i << "]: " << arrOfTime2[i] << endl;
		}
		Array<2, Time> arrOfTime3 = move(arrOfTime2);
		arrOfTime3[0] = Time(1, 5, 8);
		arrOfTime = move(arrOfTime3);

		for (size_t i = 0; i < arrOfTime.size(); i++)
		{
			cout << "arrOfTime[" << i << "]: " << arrOfTime[i] << endl;
		}
	}
	return 0;
}

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	cout << "Let`s create two points:" << endl;
	Point p1(4, 1);
	cout << p1;
	Point p2(2, 5);
	cout << p2;
	cout << "How many points do we have? Unswer: " << p1.amount() << endl;
	cout << "Let`s sum two points: " << p1 + p2 << endl;
	cout << "Let`s change p1 into the sum of point p1 and p2: " << (p1 += p2) << endl;
	cout << "Let`s create p3, so it will be copy of p2: ";
	Point p3(p2);
	cout << p3 << endl;
	cout << "Are p2 and p3 similar? Unswer: " << boolalpha << (p2==p3) << endl;
	cout << "Are p3 and p1 similar? Unswer: " << boolalpha << (p1 == p3) << endl;
	cout << "Let`s change p3 into p1: ";
	p3 = p1;
	cout << p3 << endl;
	cout << "Now let`s compare p1 and p3\nAre p1 and p3 similar? Unswer: "  << boolalpha << (p1 == p3) << endl;
	cout << p2 + p2 << endl;
}
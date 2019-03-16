#include <iostream>
#include "Point.h"
#include "Segment.h"
using namespace std;

int main()
{
	Segment AB(-1, -1, 1, 1);
	
	cout << AB << endl;
	cout << "Segment AB length: " << AB.length() << endl;
	Point C(2, 0);
	cout << "\nCreated point C:\n"<< C << endl;
	cout << "Distance from C to AB: " << AB.distance(C) << endl;
	cout << "\nAB starts with Point:\n" <<AB.start()<<"AB ends with Point:\n" << AB.end() <<endl;
	system("pause");
}
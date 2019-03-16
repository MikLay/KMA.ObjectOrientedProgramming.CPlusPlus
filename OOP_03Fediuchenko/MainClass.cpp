#include <iostream>
#include "Triangle.h"
#include "Point.h"
#include "Segment.h"
using namespace std;

int main()
{
	//Test INNER SCOUP
	{
		cout <<"-+-+-+-+-+-+-+-+- Test First -+-+-+-+-+-+-+-+-"<< endl;
		//Construct Triangle with 6 numbers
		Triangle ABC(2, 0, 5, 5, 0, 5);
		cout << ABC;
		cout <<"Perimeter ABC: " << ABC.perimeter()<<"\nArea ABC: "<< ABC.area()<< endl;
		cout <<"\nHeight A: " << ABC.height_a() << "Height B: "<<ABC.height_b()<<"Height C: "<< ABC.height_c()<< endl;
	}

	{
		cout << "-+-+-+-+-+-+-+-+- Test Second -+-+-+-+-+-+-+-+-" << endl;
		//Construct Triangle with 3 Points
		Point p1(0, 0), p2(8, 0), p3(0, 17);
		Triangle ABC(p1, p2, p3);
		cout << ABC;
		cout << "Perimeter ABC: " << ABC.perimeter() << "\nArea ABC: " << ABC.area() << endl;
		cout << "\nHeight A: " << ABC.height_a() << "Height B: " << ABC.height_b() << "Height C: " << ABC.height_c() << endl;
	}

	{
		cout << "-+-+-+-+-+-+-+-+- Test Third -+-+-+-+-+-+-+-+-" << endl;
		
		//Construct Triangle with another Triangle
		Point p1(0, 5), p2(14, 5), p3(0, 20);
		Triangle ABC(p1, p2, p3);
		Triangle DEF(ABC);
		cout << DEF << endl;
		
		//Test Apexes methods
		cout << "DEF Vertices: \n" << DEF.apexA() << DEF.apexB() << DEF.apexC() << endl;
		
		//Test Sides methods
		cout << "Side a: " << DEF.side_a() << "------------\nSide b:"<<DEF.side_b()<< "------------\nSide c:"<<DEF.side_c()<<endl;
	
	}

	return 0;
}
#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Segment.h"
#include "Point.h"

//#define DEBUG

 int Triangle::Segment::_freeID = 1;
 int Segment::_freeID = 1;

Triangle::Segment::Segment(const Point &start, const Point &end): _a(start), _b(end), _myId(_freeID++)
{
	#ifdef DEBUGW
		using namespace std;
		cout << "Segment is constructed with ID: " << _myId << endl;
	#endif
}

Triangle::Segment::Segment(const Triangle::Segment& segment): _a(segment._a), _b(segment._b), _myId(_freeID++)
{
#ifdef DEBUG
	using namespace std;
	cout << "Segment is constructed with ID: " << _myId << endl;
#endif

}



Triangle::Segment::~Segment() 
{
#ifdef DEBUG
	using namespace std;
	cout << "Segment deleted with ID: " << _myId << endl;
#endif
}




double Triangle::Segment::length() const
{
	return sqrt(pow(_b.x() - _a.x(), 2) + pow(_b.y() - _a.y(), 2));
}

double dot(const Point& u, const Point& v)
{
	return (u.x() * v.x() + u.y() * v.y());
}

double normalized(const Point& u)
{
	return sqrt(dot(u, u));
}

double dist(const Point& u, const Point& v)
{
	const Point tempPoint(u.x() - v.x(), u.y() - v.y());
	return normalized(tempPoint);
}


double Triangle::Segment::distance(const Point& point) const
{
	Point l(_b.x() - _a.x(), _b.y() - _a.y());
	Point r(point.x() - _a.x(), point.y() - _a.y());

	const double firstC = dot(r, l);
	if (firstC <= 0)
	{
		return dist(point, _a);
	}

	const double secondC = dot(l, l);
	if (secondC <= firstC)
	{
		return dist(point, _b);
	}
	const double b = firstC / secondC;
	const Point pointOnS(_a.x()+l.x()*b, _a.y()+l.y()*b);
	return dist(point, pointOnS);
}

ostream& operator<<(ostream& out , const Triangle::Segment& segment)
{
	return out << "Segment ID: " << segment.getID() << "\n" << segment.start() << "\n" << segment.end() << "\nSegment length: " << segment.length() << endl;
}




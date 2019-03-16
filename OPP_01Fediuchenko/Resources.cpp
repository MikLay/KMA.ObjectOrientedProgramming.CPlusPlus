#include <iostream>
#include "Point.h"

//#define DEBUG

int Point::freeID = 1;

Point::Point(double x, double y):pointID(freeID) ,_x(x), _y(y)
{
#ifdef DEBUG
	using namespace std;
	cout << "Point is constructed with ID: " << pointID << endl;
#endif

	++freeID;
	return;
}

Point::Point(const Point& point): pointID(freeID), _x(point._x), _y(point._y)
{
#ifdef DEBUG
	using namespace std;
	cout << "Point is constructed with ID: " << pointID << endl;
#endif
	++freeID;
	return;
}

Point::~Point()
{
#ifdef DEBUG
	using namespace std;
	cout << "Point delated with ID: " << pointID << endl;
#endif
}

Point& Point::operator=(const Point& another)
{
	if (this != &another)
	{
		_x = another.x();
		_y = another.y();
	}
	return *this;
}

double& Point:: x()
{
	return _x;
}

double& Point:: y()
{
	return _y;
}

const double& Point:: x()const
{
	return _x;
}

const double& Point::y()const
{
	return _y;
}

const int Point::getID() const
{
	return pointID;
}

int Point::amount()
{
	return freeID-1;
}


ostream& operator<<(ostream& out, const Point& p)
{
	return out << "Point ID:" << p.getID() << "| x:" << p.x() << "| y:" << p.y() << "|\n";
}



const Point operator+ (const Point & u, const Point & v)
{
	double x = u.x() + v.x();
	double y = u.y() + v.y();
	return Point(x, y);
}

Point& operator+=(Point & a, const Point& b)
{
	a.x() += b.x();
	a.y() += b.y();
	return a;
}

bool operator==(const Point & u, const Point &v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point & u, const Point &v)
{
	return u == v ? false : true;
}

#include <iostream>
#include "Segment.h"
#include "Point.h"

#define DEBUG
int Segment::_freeID = 1;

Segment::Segment(const double x1, const double y1, const double x2, const double y2): _a(x1,y1), _b(x2,y2), _myId(_freeID++)
{
#ifdef DEBUG
	using namespace std;
	cout << "Segment is constructed with ID: " << _myId << endl;
#endif
	return;
}

Segment::Segment(const Point &start, const Point &end): _a(start), _b(end), _myId(_freeID++)
{
	#ifdef DEBUG
		using namespace std;
		cout << "Point is constructed with ID: " << _myId << endl;
	#endif
}

Segment::Segment(const Segment& segment): _a(segment._a), _b(segment._b), _myId(_freeID++)
{
#ifdef DEBUG
	using namespace std;
	cout << "Point is constructed with ID: " << _myId << endl;
#endif

}

Segment::~Segment() 
{
}


Segment& Segment::operator=(const Segment& another)
{
	if (this != &another)
	{
		_a = another._a;
		_b = another._b;
	}
	return *this;
}

const Point& Segment::start() const
{
	return _a;
}

const Point& Segment::end() const
{
	return _b;
}

Point& Segment::start()
{
	return _a;
}

Point& Segment::end()
{
	return _b;
}

const double& Segment::startX() const
{
	return _a.x();
}

const double& Segment::startY() const
{
	return _a.y();
}

const double& Segment::endX() const
{
	return _b.x();
}

const double &Segment::endY() const
{
	return _b.y();
}

double& Segment::startX()
{
	return _a.x();
}

double& Segment::startY()
{
	return _a.y();
}

double& Segment::endX()
{
	return _b.x();
}

double &Segment::endY()
{
	return _b.y();
}

double Segment::length() const
{
	return sqrt(pow(_a.x() - _b.x(), 2) + pow(_a.y() - _b.y(), 2));
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
	Point tempPoint(u.x() - v.x(), u.y() - v.y());
	return normalized(tempPoint);
}


double Segment::distance(const Point& point) const
{
	Point l(_b.x() - _a.x(), _b.y() - _a.y());
	Point r(point.x() - _a.x(), point.y() - _a.y());

	double firstC = dot(r, l);
	if (firstC <= 0)
	{
		return dist(point, _a);
	}

	double secondC = dot(l, l);
	if (secondC <= firstC)
	{
		return dist(point, _b);
	}
	double b = firstC / secondC;
	Point pointOnS(_a.x()+l.x()*b, _a.y()+l.y()*b);
	return dist(point, pointOnS);
}


const int Segment::getID() const
{
	return _myId;
}

ostream& operator<<(ostream& out , const Segment& s)
{
	return out << "Segment ID: " << s.getID() << "\n| First point:" << s.start() << "| Second point:" << s.end() << endl;
}
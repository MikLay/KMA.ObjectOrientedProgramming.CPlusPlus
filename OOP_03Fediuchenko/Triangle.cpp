
#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Segment.h"

//#define DEBUG

//Constructors

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :_a(x1, y1), _b(x2, y2), _c(x3, y3), _ab(0), _bc(0), _ca(0)
{
#ifdef DEBUG
	using namespace std;
	cout << "Triangle is constructed"  << endl;
#endif

	return;
}


Triangle::Triangle(const Point &a, const Point &b, const Point &c) :_a(a), _b(b), _c(c), _ab(0), _bc(0), _ca(0)
{
#ifdef DEBUG
	using namespace std;
	cout << "Triangle is constructed with ID: " <<  endl;
#endif
	return;
}








Triangle::Triangle(const Triangle& t) : _a(t._a), _b(t._b), _c(t._c),
_ab(0), _bc(0), _ca(0)
{


#ifdef DEBUG
	using namespace std;
	cout << "Triangle is constructed with ID: " << endl;
#endif
	return;
}


//Destructor

Triangle::~Triangle()
{
	if (_ab != 0)
		delete _ab;
	if (_bc != 0)
		delete _bc;
	if (_ca != 0)
		delete _ca;
	return;
}


//Other constructors
Triangle &Triangle::operator=(const Triangle &t)
{
	_a = t._a;
	_b = t._b;
	_c = t._c;

	if (_ab != 0) 
		delete _ab;
	if (_bc != 0) 
		delete _bc;
	if (_ca != 0) 
		delete _ca;
	_ab = _bc = _ca = 0;
	return *this;
}

//Triangle public methods
double Triangle::perimeter() const
{
	return length_a() + length_b() + length_c();
}

double Triangle::area() const
{
	const double p = 0.5*perimeter();
	return std::sqrt(p*(p - length_a())*(p - length_b())*(p - length_c()));
}

double Triangle::length_a() const
{
	return side_a().length();
}

double Triangle::length_b() const
{
	return side_b().length();
}

double Triangle::length_c() const
{
	return side_c().length();
}



const Point& intersectionCircleAndLine(double x, double y, double k, double b, double r)
{
	const double d = (pow((2 * k*b - 2 * x - 2 * y*k), 2) - (4 + 4 * k*k)*(b*b - r * r + x * x + y * y - 2 * y*b));
	const double x1 = ((-(2 * k*b - 2 * x - 2 * y*k) - sqrt(d)) / (2 + 2 * k*k));
	const double y1 = k * x1 + b;
	return *(new Point(x1, y1));
}

const Point& findEndPointOfHeight(Triangle::Segment* const line,const Point& start, double a)
{
	const double r = 2 * a / (line->length());
	std::cout << "D;::" << r << endl;
	const double x1 = line->start().x();
	const double x2 = line->end().x();
	const double y1 = line->start().y();
	const double y2 = line->end().y();
	double k;
	if (x1 == x2)
	{
		k = (y1 - y2) / (x1);
	}
	else
	{
		k = (y1 - y2) / (x1 - x2);
	}
	const double b = y1 - k * x1;
	return intersectionCircleAndLine(start.y(), start.x(), k, b, r);
}

double dotTransform(const double x1, const double y1, const double x2, const double y2)
{
	return x1 * x2 + y1 * y2;

}

const Point& projection(Triangle::Segment* const s, const Point& start)
{
	const double t = dotTransform(start.x() - s->start().x(), start.y() - s->start().y(), s->end().x() - s->start().x(), s->end().y() - s->start().y()) / pow(s->length(), 2);
	return *(new Point(s->start().x() + t * (s->end().x() - s->start().x()), s->start().y() + t * (s->end().y() - s->start().y())));
}

const Segment& Triangle::height_a() const
{
	return *(new ::Segment(_a,projection(_bc,_a)));
}


const ::Segment& Triangle::height_b() const
{
	return *(new ::Segment(_a, projection(_ca, _b)));
}


const ::Segment& Triangle::height_c() const
{
	return *(new ::Segment(_a, projection(_ab, _c)));
}

//Sides

const Triangle::Segment& Triangle::side_a() const
{
	if (_bc == nullptr)
		_bc = new Triangle::Segment(_b, _c);
	return *_bc;
}

const Triangle::Segment& Triangle::side_b() const
{
	if (_ca == nullptr)
		_ca = new Triangle::Segment(_c, _a);
	return *_ca;
}

const Triangle::Segment& Triangle::side_c() const
{
	if (_ab == nullptr)
		_ab = new Triangle::Segment(_a, _b);
	return *_ab;
}

Triangle::Segment& Triangle::side_a()
{
	if (_bc == nullptr)
		_bc = new Triangle::Segment(_b, _c);
	return *_bc;
}

Triangle::Segment& Triangle::side_b()
{
	if (_ca == nullptr)
		_ca = new Triangle::Segment(_c, _a);
	return *_ca;
}

Triangle::Segment& Triangle::side_c()
{
	if (_ab == nullptr)
		_ab = new Triangle::Segment(_a, _b);
	return *_ab;
}

//Length of sides


//Height of Triangle



ostream& operator<<(ostream& os, const Triangle& t)
{
	return os << "Triangle -> [\nVertex a: " << t.apexA() << "Vertex b: " << t.apexB() << "Vertex c: " << t.apexC() << "            ]\n";
}




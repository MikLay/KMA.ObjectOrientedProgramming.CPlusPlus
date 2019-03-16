#pragma once
#include <iostream>
#include "Point.h"
#include "Segment.h"
using namespace  std;
//*******************************************

//    Lab task 4

//    Developed by Michael Fediuchenko

//    on 09.02.2019

//    Version 1.0 

//*******************************************



// Клас трикутників із вкладеними відрізками
// Агрегація сторін указниками
// Агрегація їх вершин відсилками

class Segment;

class Triangle
{
public:
	class Segment
	{
	private:
		const Point &_a;

		const Point &_b;

		static int _freeID;
		int _myId;

		Segment(const Segment &);

		Segment &operator=(const Segment &);

	public:

		Segment(const Point &start, const Point &end);

		~Segment();

		const Point &start() const { return _a; };
		const Point &end() const { return _b; };

		double length() const;

		double distance(const Point &) const;

		int getID() const { return _myId; };
	};

	typedef Segment *Triangle::* SidePtr;
	
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);
	
	Triangle(const Point &a,
		const Point &b,
		const Point &c);

	Triangle(const Triangle &);
	
	~Triangle();

	Triangle &operator=(const Triangle &);

	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };

	const Segment &side_a() const;
	const Segment &side_b() const;
	const Segment &side_c() const;

	Segment &side_a();
	Segment &side_b();
	Segment &side_c();

	double perimeter() const;
	
	double area() const;

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const ::Segment& height_a() const;
	const ::Segment& height_b() const;
	const ::Segment& height_c() const;


private:
	Point _a, _b, _c;
	
	mutable Segment *_ab, *_bc, *_ca;
};
ostream& operator<<(ostream &, const Triangle::Segment &);
ostream& operator<<(ostream &, const Triangle &);


#include <iostream>
#include "Point.h"
using namespace std;

//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by .....................

//at ....................

//Version 1.0

//*******************************************



// Клас відрізків

class Segment

{

private:

	// Засоби облікування відрізків

	static int _freeID;

	const int _myId;

	// Точка початку відрізку


	Point _a;

	// Точка кінця відрізку

	Point _b;

public:

	// Конструктори відрізків

	// 1) за координатами його кінців

	Segment(const double x1 = 0, const double y1 = 0,

		const double x2 = 1, const double y2 = 0);

	// 2) за точками початку і кінця

	Segment(const Point &start, const Point &end);

	// 3) копіювальний конструктор

	Segment(const Segment&);

	// Деструктор

	~Segment();

	// Присвоєння

	Segment& operator=(const Segment&);

	// Селектори  точок

	const Point& start() const;

	const Point& end() const;

	// Селектори-модифікатори точок

	Point& start();

	Point& end();

	// Селектори координат точок

	const double& startX() const;

	const double& startY() const;

	const double& endX() const;

	const double& endY() const;

	// Селектори-модифікатори координат точок

	double& startX();

	double& startY();

	double& endX();

	double& endY();

	// Обчислення довжини відрізка

	double length() const;

	// Обчислення відстані від відрізка до точки

	double distance(const Point&) const;

	// Селектор ID

	const int getID() const;

};



ostream& operator<<(ostream &, const Segment &);
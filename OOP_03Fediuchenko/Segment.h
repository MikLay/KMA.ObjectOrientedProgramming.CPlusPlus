#pragma once
#include <iostream>
#include "Point.h"
using namespace std;

// ¬кладений клас в≥др≥зк≥в
// дл€ стор≥н трикутник≥в

class Segment
{
private:
	const Point _a;

	const Point _b;

	static int _freeID;
	int _myId;

	Segment(const Segment &);

	Segment &operator=(const Segment &);

public:
	
	Segment(const Point &start, const Point &end):_a(start),_b(end), _myId(_freeID++){};
	
	~Segment(){};

	const Point &start() const { return _a; };
	const Point &end() const { return _b; };
	
	int getID() const { return _myId; };
};

inline ostream &operator<<(ostream & out, const Segment & segment)
{
	return out << "Segment ID: " << segment.getID() << "\n" << segment.start() << "\n" << segment.end() << endl;
}
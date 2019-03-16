// Complex numbers
// in polar form
#pragma once
#include <istream>

class AComplex;
class TComplex
{
private:
	double _ro, _phi;
	static int _freeId;
	int _id;

public:
	TComplex(double ro = 0, double phi = 0);
	TComplex(const TComplex&);
	TComplex(const AComplex&);
	~TComplex();

	TComplex& operator= (const TComplex&);

	double& mod() { return _ro; }
	double& arg() { return _phi;}

	double mod() const { return _ro; }
	double arg() const { return _phi; }

	double re() const { return _ro * std::cos(_phi); }
	double im() const { return _ro * std::sin(_phi); }
	int getID() const { return _id; }


};

TComplex& operator+=(TComplex& a, const TComplex& b);
TComplex& operator-=(TComplex& a, const TComplex& b);
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);

const TComplex  operator* (const TComplex&, const TComplex&);
const TComplex  operator/ (const TComplex&, const TComplex&);
const TComplex  power(const TComplex&, unsigned int);

std::ostream& operator<<(std::ostream &, const TComplex&);
std::istream& operator>>(std::istream &, TComplex&);
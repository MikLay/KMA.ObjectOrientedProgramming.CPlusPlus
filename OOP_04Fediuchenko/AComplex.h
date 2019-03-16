// Complex numbers
// in cartesian (algebraic) form
#pragma once
#include <iostream>

class TComplex;
class AComplex
{
private:
	double _re, _im;
	static int _freeId;
	int _id;

public:
	
	AComplex(double re = 0, double im = 0);
	AComplex(const TComplex&);
	AComplex(const AComplex&);
	~AComplex();

	AComplex& operator= (const AComplex&);

	double& re() { return _re;}
	double& im() { return _im;}

	double re() const { return _re; }
	double im() const { return _im; }



	double mod() const { return std::sqrt(_re * _re + _im * _im); };
	double arg() const { return std::tanh(_im / _re); }

	const AComplex conj() const { return AComplex(_re, _im*-1); };

	int getID() const { return _id; }

};

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex  operator+ (const AComplex&, const AComplex&);
const AComplex  operator- (const AComplex&, const AComplex&);
const AComplex  power(const AComplex&, unsigned int);

bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);

std::ostream& operator<<(std::ostream &, const AComplex &);
std::istream& operator>>(std::istream &, AComplex&);

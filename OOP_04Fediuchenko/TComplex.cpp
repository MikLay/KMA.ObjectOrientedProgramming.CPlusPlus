//*******************************************

//Developed by Michael Fediuchenko

//on 15.02.2019

//Version 1.0

//*******************************************

#include <iostream>
#include "TComplex.h"
#include "AComplex.h"
#define DEBUG

int TComplex::_freeId = 1;

TComplex::TComplex(double ro, double phi): _ro(ro), _phi(phi), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "TComplex is constructed with ID: " << _id << endl;
#endif

	return;
}

TComplex::TComplex(const TComplex& tComplexNumber):_ro(tComplexNumber.mod()), _phi(tComplexNumber.arg()), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "TComplex is constructed with ID: " << _id << endl;
#endif

	return;
}

TComplex::TComplex(const AComplex& aComplexNumber): _ro(aComplexNumber.mod()), _phi(aComplexNumber.arg()), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "TComplex is constructed with ID: " << _id << endl;
#endif
	return;
}

TComplex::~TComplex()
{	
#ifdef DEBUG
	using namespace std;
	cout << "TComplex deleted with ID: " << _id << endl;
#endif
}

TComplex& TComplex::operator=(const TComplex& another)
{
	if(this != &another)
	{
		_ro = another._ro;
		_phi = another._phi;
	}
	return *this;
}

//TComplex::operator AComplex() const
//{
//	return AComplex(re(), im());
//}

TComplex& operator+=(TComplex& a, const TComplex& b)
{
	
	const double real = a.re() + b.re();
	const double img = b.im() + a.im();
	a.mod() = std::sqrt(real*real + img * img);
	a.arg() = std::tanh(img / real);
	return a;
}

TComplex& operator-=(TComplex& a, const TComplex& b)
{
	const double real = a.re() - b.re();
	const double img = b.im() - a.im();
	a.mod() = std::sqrt(real*real + img * img);
	a.arg() = std::tanh(img / real);
	return a;
}

TComplex& operator*=(TComplex& a, const TComplex& b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}

TComplex& operator/=(TComplex& a, const TComplex& b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}

const TComplex  operator* (const TComplex& a, const TComplex& b)
{
	return TComplex(a.mod()*b.mod(), a.arg() + b.arg());
}

const TComplex  operator/ (const TComplex& a, const TComplex& b)
{
	return TComplex(a.mod() / b.mod(), a.arg() - b.arg());
}

const TComplex  power(const TComplex& complexNumber, unsigned int k)
{
	return TComplex(std::pow(complexNumber.mod(), k), complexNumber.arg()*k);
}
 

std::ostream& operator<<(std::ostream & out, const TComplex& complexNumber)
{
	return out << "Complex number with ID: " << complexNumber.getID() << "| " << complexNumber.mod() << "( cos(" << complexNumber.arg() << ") + i*sin(" << complexNumber.arg() << ") )" << std::endl;
}

std::istream& operator>>(std::istream & in, TComplex& number)
{
	std::cout << "Enter ro: ";
	std::cin >> number.mod();
	std::cout << "\nEnter phi: ";
	std::cin >> number.arg();
	std::cout << std::endl;
	return in;
}




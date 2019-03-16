//*******************************************

//Developed by Michael Fediuchenko

//on 15.02.2019

//Version 1.0

//*******************************************

#include <iostream>
#include "AComplex.h"
#include "TComplex.h"

#define DEBUG

int AComplex::_freeId = 1;

AComplex::AComplex(double re, double im):_re(re), _im(im), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "AComplex is constructed with ID: " << _id << endl;
#endif
	return;	
}

AComplex::AComplex(const AComplex& a_comp_number):_re(a_comp_number.re()), _im(a_comp_number.im()), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "AComplex is constructed with ID: " << _id << endl;
#endif
	return;
}

AComplex::AComplex(const TComplex& t_comp_number): _re(t_comp_number.mod()), _im(t_comp_number.arg()), _id(_freeId++)
{
#ifdef DEBUG
	using namespace std;
	cout << "AComplex is constructed with ID: " << _id << endl;
#endif
	return;
}

AComplex::~AComplex()
{
#ifdef DEBUG
	using namespace std;
	cout << "AComplex deleted with ID: " << _id << endl;
#endif
}

AComplex& AComplex::operator=(const AComplex& another)
{
	if(this != &another)
	{
		_im = another.im();
		_re = another.re();
	}
	return *this;
}



AComplex& operator+=(AComplex& result, const AComplex& adder)
{
	result.re() += adder.re();
	result.im() += adder.im();
	return result;
}
AComplex& operator-=(AComplex& result, const AComplex& subtrahend)
{
	result.re() -= subtrahend.re();
	result.im() -= subtrahend.im();
	return result;
}

AComplex& operator*=(AComplex& result, const AComplex& multiplier)
{
	result.re() = (result.re()*multiplier.re() + result.im()*multiplier.im());
	result.im() = (result.re() * multiplier.im() + result.im()*multiplier.re());
	return result;
}
AComplex& operator/=(AComplex& result, const AComplex& divider)
{
	result.re() = (result.re()*divider.re() + result.im()*divider.im())/(pow(divider.re(), 2)+pow(divider.im(), 2));
	result.im() = (result.im() * divider.re() - result.re()*divider.re())/ (pow(divider.re(), 2) + pow(divider.im(), 2));
	return result;
}

const AComplex  operator+ (const AComplex& first, const AComplex& second)
{
	return AComplex(first.re() + second.re(), first.im() + second.re());
}
const AComplex  operator- (const AComplex& first, const AComplex& second)
{
	return AComplex(first.re() - second.re(), first.im() - second.re());

}

const AComplex  power(const AComplex& first, unsigned int n)
{
	const TComplex temp(pow(first.mod(), n), n * first.arg());
	return AComplex(temp);
}

//Operations between different types
//AComplex::operator TComplex() const
//{
//	return TComplex(mod(), arg());
//}

bool operator== (const AComplex& first, const AComplex& second)
{
	return first.re() == second.re() ? first.im() == second.im() : false;
}

bool operator!= (const AComplex& first, const AComplex& second)
{
	return !(first == second);
}

std::ostream& operator<<(std::ostream & out, const AComplex & number)
{
	return out << "Complex number with ID:" << number.getID() << "| " << number.re() << (number.im() >= 0.0 ? " + i(" : " - i(") << abs(number.im()) <<")" << std::endl;
}
std::istream& operator>>(std::istream & in, AComplex& number)
{
	std::cout << "Enter re: ";
	std::cin >> number.re();
	std::cout << "\nEnter im: ";
	std::cin >> number.im();
	std::cout << std::endl;
	return in;
}










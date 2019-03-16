#include  <iostream>
#include "AComplex.h"
#include "TComplex.h"
using namespace std;

const double PI = 3.14159265359;

int main()
{
	// First InScope
	{
		// Test AComplex numbers
		cout << "-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+- Test First -+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-" << endl;
		cout << "=========================== Testing all AComplex class =========================" << endl;
		
		// Testing constructors 
		AComplex a1(1, 1);
		AComplex a2(2, 4);
		AComplex a3(a1);

		cout << "a1: \n" << a1 << endl;
		cout << "a2: \n" << a2 << endl;
		cout << "|a1 = a3|	a3: \n" << a3 << endl;
		
		// Testing Operator AComplex =
		a3 = a2;
		cout << "a3 = a2	a3: \n" << a3 << endl;

		// Testing Selectors&Modificators
		cout << "a1`s real: " << a1.re() << "\n a1`s imaginary: " << a1.im() <<"i" << endl;
		a3.im() = 3;
		a1.re() = a2.re();
		a1.im() = a3.im();
		cout << "a3`s imaginary = 3 -> \na1`s real = a2`s real -> \na1`s imaginary = a3`s imaginary\na1: " << a1 << endl;

		// Testing methods (mod arg)
		cout << "a3`s mod: " << a3.mod() << "\na3`s arg: " << a3.arg() << endl;
		cout << "a2`s conjugate" << a2.conj() << endl;

		// Testing operators
		cout << "a1+a3: " << (a1 + a3) << endl;
		cout << "a3 += a2:  " << (a3 += a2) << endl;
		cout << "a1 * a2: " << (a1*a2) << endl;
		cout << "a3*= a1: " << (a3 *= a1) << endl;
		cout << "a2 / a1: " << (a2 / a1) << endl;
		cout << "a2/=a1: " << (a2 /= a1) << endl;
		cout << "a1^(2): " << power(a1, 2) << endl;

		// Creating new number
		AComplex a4;
		cin >> a4;
		cout << "a4:\n" << a4<< endl;
	}

	// Second InScope
	{
		// Test AComplex numbers
		cout << "\n-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+- Test Second -+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-" << endl;
		cout << "============================ Testing all TComplex class ==========================" << endl;

		// Testing constructors 
		TComplex a1((2*sqrt(2)),(-(PI/4)));
		TComplex a2(64, PI);
		TComplex a3(a1);
	
		cout << "a1: \n" << a1 << endl;
		cout << "a2: \n" << a2 << endl;
		cout << "|a1 = a3|	a3: \n" << a3 << endl;

		// Testing Operator TComplex =
		a3 = a2;
		cout << "a3 = a2	a3: \n" << a3 << endl;

		// Testing Selectors&Modificators
		cout << "a1`s mod: " << a1.mod() << "\n a1`s phi: " << a1.arg() << endl;
		a3.mod()= 3;
		a1.mod() = a2.mod();
		a1.arg() = a3.arg();
		cout << "a3`s module = 3 -> \na1`s module = a2`s module -> \na1`s phi = a3`s phi\na1: " << a1 << endl;

		// Testing methods (re im)
		cout << "a3`s real: " << a3.re() << "\na3`s imaginary: " << a3.im() << endl;
		
		// Testing operators
		cout << "a1+a3: " << (a1 + a3) << endl;
		cout << "a3 += a2:  " << (a3 += a2) << endl;
		cout << "a1 * a2: " << (a1*a2) << endl;
		cout << "a3*= a1: " << (a3 *= a1) << endl;
		cout << "a3 / a2: " << (a3 / a2) << endl;
		cout << "a3 /= a2: " << (a3 /= a2) << endl;
		cout << "a2^(2): " << power(a2, 2) << endl;

		// Creating new number
		TComplex a4;
		cin >> a4;
		cout << "a4:\n" << a4 << endl;

	}

	// Third InScope
	{
		// Test operations with TComplex and AComplex 
		cout << "\n-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+- Test Third -+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-" << endl;
		cout << "========================== Testing operations between A&T =======================" << endl;

		
		AComplex a1(1, 1);
		const AComplex a2(4, 2);

		// Testing operations 
		const TComplex ta3 = a2;
		cout << "a1:\n" << a1 << "\nta3:\n" << ta3 << endl;
		cout << "a1 + ta3: " << a1 + ta3 << endl;
		cout << "ta3 - a1: " << ta3 - a1 << endl;
		cout << "ta3 * a1: " << ta3 * a1 << endl;
		cout << "a1 / ta3: " << a1 / ta3 << endl;
	}

		return 0;
}
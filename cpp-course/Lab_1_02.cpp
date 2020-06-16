#include "Lab_1_02.h"


void Lab_1_02::execute()
{
	cout << "Executing Lab 1.02" << endl;

	//## You only need to do this once.
	cout << std::fixed << setprecision(2);

	//Part 1
	int a = 5 + 2 * 2;
	cout << "a " << a << endl;

	/* //##
	If both operands are integers, C++ performs integer division. That means any
	fractional part of the answer is discarded, making the result an integer.
	If one or both operands are floating-point values, the fractional part is
	kept, making the result floating-point.
	*/
	float b = 2 / 3;
	cout << "b " << b << endl;

	double c = 2.0 * 1.5;
	cout  << "c " << c << endl;

	unsigned int d = (2 + 3) * 10;
	cout << "d " << d << endl;

	double e = floor(5.0 / 2);
	cout << "e " << e << endl;

	//## added to show the effect of ceil()
	double e1 = ceil(5.0 / 2.0);
	cout << "e1 " << e1 << endl;

	double e2 = ceil(5 / 2); // integer division truncates
	cout << "e2 " << e2 << endl;

	int e3 = 5 / 2; // repeats b above
	cout << "e3 " << e3 << endl;

	float f = 5 % 2;
	cout << "f " << f << endl;

	char g = 'g';
	cout << "g " << g << endl;

	char g2 = 0x0036; //## -127 is unprintable; choose a printable character
	cout << "g2 " << g2 << endl;

	unsigned char g3 = 254; //## changed from -127 to 254 to show unsigned value
	cout << "g3 " << static_cast<unsigned>(g3) << endl;

	bool h = true;
	cout << "h " << h << endl;

	bool i = 0;
	cout << "i " << i << endl;

	bool j = -100; //## compiler warning "truncation from int to bool"
	cout << "j " << j << endl;

	// Part 2
	cout << endl << "Part 2" << endl;

	int A2 = 10 * 2;
	cout << "A2 " << A2 << endl;

	int B2 = .5 * 2;
	cout << "B2 " << B2 << endl;

	int C2 = 10 / 2; //## simple integer division; got lucky, no remainder therefore no rounding
	cout << "C2 " << C2 << endl;

	int D2 = 10 % 2;
	cout << "D2 " << D2 << endl;

	//## c++ does not have an exponentiation operator; you have to use the built-in function pow()
	//Gets an error
	//float E2 = 2 * *3;
	//cout << E2 << endl;

	int F2 = (2 + 5) * 3;
	cout << "F2 " << F2 << endl;

	int G2 = 2 + 5 * 3;
	cout << "G2 " << G2 << endl;
	
	// compilation error
	//float H2 = "ab" + "12" + "3";
	//## H2 should be type string
	//## The this doesn't compile either because the type of "ab" is actually const char *
	//string H2 = "ab" + "12" + "3";
	string H2 = string("ab" + string("12") + string("3"));
	cout << "H2 " << H2 << endl;

	//Error, should it be "x"?
	//## Yes, but let's try an empty string:
	string I2;
	cout << "I2 " << I2 << endl;

	//## same problem as H2
	//error
	//float J2 = "ab" + "cd";
	//cout << J2 << endl;

	//## Not legal in c++ but in Python yields "abcabc".
	//error
	//int K2 = "abc" * 2; 
	//cout << K2 << endl;

	//## the answer is 248 because the binary value of '1' is 49 (ASCII character set)
	// and the value of '2' is 50.
	float L2 = '1' * 2 + '2' * 3;
	cout << "L2 " << L2 << endl;

	float M2 = 1 * 2 + '2' * 3;
	cout << "M2 " << M2 << endl << endl;

	//## same as E2
	//error
	//float N2 = 'A' * *2;
	//cout << N2 << endl;

	//error
	//float O2 = "bc" % 2;
	//cout << O2 << endl;


	// Bonus: type inference in c++!
	// Leave this code in place and let it execute. We'll talk it later..
	auto d2 = 10 % 2;
	cout << "Variable d2, type " << typeid(d2).name() << ", value " << d2 << endl;

}

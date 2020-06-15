#include "Lab_1_02.h"


void Lab_1_02::execute()
{
	cout << "Executing Lab 1.02" << endl;

	//Part 1
	int a = 5 + 2 * 2;
	cout << a << endl;

	float b = 2 / 3;
	cout << b << endl;

	double c = 2.0 * 1.5;
	cout << c << endl;

	unsigned int d = (2 + 3) * 10;
	cout << d << endl;

	double e = floor(5.0 / 2);
	cout << e << endl;

	double e2 = ceil(5 / 2);
	cout << e2 << endl;

	int e3 = 5 / 2;
	cout << e3 << endl;

	float f = 5 % 2;
	cout << f << endl;

	char g = 'g';
	cout << g << endl;

	char g2 = -127;
	cout << g2 << endl;

	unsigned char g3 = -127;
	cout << g3 << endl;

	bool h = true;
	cout << h << endl;

	bool i = 0;
	cout << i << endl;

	bool j = -100;
	cout << j << endl;

	//Part 2

	int A2 = 10 * 2;
	cout << A2 << endl;

	int B2 = .5 * 2;
	cout << B2 << endl;

	int C2 = 10 / 2;
	cout << C2 << endl;

	int D2 = 10 % 2;
	cout << D2 << endl;

	//Gets an error
	//float E2 = 2 * *3;
	//cout << E2 << endl;

	int F2 = (2 + 5) * 3;
	cout << F2 << endl;

	int G2 = 2 + 5 * 3;
	cout << G2 << endl;
	
	//error
	//float H2 = "ab" + "12" + "3";
	//cout << H2 << endl;

	//Error, shoud it be "x"?
	//string I2 = x;
	//cout << I2 << endl;

	//error
	//float J2 = "ab" + "cd";
	//cout << J2 << endl;

	//error
	//int K2 = "abc" * 2; 
	//cout << K2 << endl;

	float L2 = '1' * 2 + '2' * 3;
	cout << L2 << endl;

	float M2 = 1 * 2 + '2' * 3;
	cout << M2 << endl;

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

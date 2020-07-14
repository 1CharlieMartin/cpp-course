#include "Lab_2_03.h"


void Lab_2_03::execute()
{
	cout << "Executing Lab 2.03" << endl;

	string triType;
	float a;
	float b;
	float c;
	bool validTri = false;

	cout << "Please enter the three side lengths of your triangle:";
	cin >> a >> b >> c;

	if ((b + c < a) || (a + b < c) || (c + a < b)) {
		//** FIX Don't ignore warnings!
		//** 1>C:\Users\726Admin\source\repos\cpp-course\cpp-course\Lab_2_03.cpp(24,17): warning C4805: '==': unsafe mix of type 'bool' and type 'float' in operation
		// Can you figure out what the problem is here?

		cout << "Your triangle is not valid." << endl;
		exit(0);
	}


	if (a == b == c) {
		triType = "equilateral";
	}

	//** FIX This can be simplified because (a != b) is the same as (b != a), etc.
	else if ((a != b) && (a != c) && (b != a) && (b != c) && (c != a) && (c != b)) {
		triType = "scalene";
	}

	else if ((a == b) || (a == c) || (b == c)) {
		triType = "isosceles";
	}

	cout << "Your triangle is " << triType << " and its perimeter is " << a + b + c << "." << endl;

}

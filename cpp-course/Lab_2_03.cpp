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
	
		cout << "Your triangle is not valid." << endl;
		exit(0);
	}


	if ((a == b) && (a == c) && (b == c)) {
		triType = "equilateral";
	}

	else if ((a != b) && (c != a) && (c != b)) {
		triType = "scalene";
	}

	else if ((a == b) || (a == c) || (b == c)) {
		triType = "isosceles";
	}

	cout << "Your triangle is " << triType << " and its perimeter is " << a + b + c << "." << endl;

}

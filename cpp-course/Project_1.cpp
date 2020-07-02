#include "Project_1.h"

void Project_1::execute()
{

	int userNum;

	cout << "Executing Project 1" << endl;

	cout << " Welcome to Magic Square" << endl;
	cout << "Enter a number from 21 to 65: ";
	cin >> userNum;
	if (cin.fail())
	{
		cout << "Sorry, your input was in the wrong format." << endl;
		exit(1);
	}

	if (userNum < 21 || userNum>65)
	{
		cout << "Sorry, the number that you entered is not within 21 and 65." << endl;
		exit(1);
	}


	cout << "You have entered " << userNum << ".";

	cout << "Your magic square is:" << endl;
	cout << endl;
	cout << userNum - 20 << " 1 12 7" << endl;
	cout << "11 8 " << userNum - 21 << " 2" << endl;
	cout << "5 10 3 " << userNum - 18 << endl;
	cout << "4 " << userNum - 19 << " 6 9" << endl;
}

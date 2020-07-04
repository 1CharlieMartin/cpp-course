#include "Lab_2_01.h"


void Lab_2_01::execute()
{
	cout << "Executing Lab 1.01" << endl;


	//## Begin starter code
	int a = 0;
	while (true) // i.e. an infinite loop
	{
		cout << "Enter an integer ";
		cin >> a;
		if (!cin.fail()) {
			if (cin.peek() == '\n') // at eol?
				break; // yes, exit loop
			else
				cout << "Sorry, you have extraneous input, please try again" << endl;
		}
		else {
			// cin.fail() is true
			cin.clear(); // clear the fail() condition
			cout << "You have entered an invalid integer, please try again" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flushes input up to eol
	}

	cout << "The number is : " << a << endl;
	//## End starter code

	//** Lab 2.01
	// Convert the code below to use a copy of the starter code to validate
	// the input. Do not call exit(1) if the user enters invalid input.
	int x = 0;
	float y = 0.0f;
	cout << "Please enter an integer and a float ";
	cin >> x >> y;

	if (cin.fail())
	{
		cout << "Sorry, your input was in the wrong format." << endl;
		exit(1);
	}

}

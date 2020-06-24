#include "Lab_1_04.h"


void Lab_1_04::execute()
{
	cout << "Executing Lab 1.04" << endl;

	float x;
	cout << "Please enter a float value ";
	cin >> x;
	cout << "You entered " << x << endl;

	string z;
	cout << "Please enter a string with embedded spaces ";
	cin >> z;
	cout << "You entered " << z << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please try again" << endl;
	getline(cin, z);
	cout << "You entered " << z << endl;

	cout << "What would you like to wish for ? " << endl;

	const string ask("What would you like to wish for ? "); // const means that you may not change this string
	// this will not compile ask[0] = 'X';

	string my("My ");
	string dog("dog ");
	string has("has ");
	string fleas("fleas ");
	cout << my << dog << has << fleas << endl;

	string final = my + dog + has + fleas; // string may not be const here
	cout << "final " << final << endl;

	// The next example uses the "append” member function of the string class:
	string final2; // string may not be const here
	final2.append(my);
	final2.append(dog);
	final2.append(has);
	final2.append(fleas);

	cout << "final2 " << final2 << endl;

	//Code Goes Here 
	string Question1;
	string Question2;
	string Question3;

	string genieQuestion = "What would you like to wish for?";


	cout << "Hello! I am a magic genie. You have three wishes." << endl;

	cout << genieQuestion;
	getline(cin, Question1);

	cout << genieQuestion;
	getline(cin, Question2);

	cout << genieQuestion;
	getline(cin, Question3);

	cout << "You wished for " << Question2 << ", " << Question3 << ", and " << Question1 << endl;







}

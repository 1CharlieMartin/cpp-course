#include "Lab_3_01.h"


void Lab_3_01::execute()
{
	cout << "Executing Lab 3.01" << endl;
	
	string input;

	std::array<string, 8> Array = {"Outlook is good", "Ask again later", "Yes", "No", "Most likely no", "Most likely yes", "Maybe", "Outlook is not good"};


	int randNum;

	srand((unsigned int) time(NULL)); //## PY cast to unsigned int avoids warning
	randNum = rand() % 8 + 1;

	cout << "Ask a yes or no question." << endl;
	cin >> input;

	//## PY I think this is a better way ...
	cout << Array[(size_t) randNum - 1] << endl;

	if (randNum == 1) {
		cout << Array[0] << endl;
	}

	if (randNum == 2) {
		cout << Array[1] << endl;
	}

	if (randNum == 3) {
		cout << Array[2] << endl;
	}

	if (randNum == 4) {
		cout << Array[3] << endl;
	}

	if (randNum == 5) {
		cout << Array[4] << endl;
	}

	if (randNum == 6) {
		cout << Array[5] << endl;
	}

	if (randNum == 7) {
		cout << Array[6] << endl;
	}

	if (randNum == 8) {
		cout << Array[7] << endl;
	}






}

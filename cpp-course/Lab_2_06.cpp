#include "Lab_2_06.h"


void Lab_2_06::execute()
{
	cout << "Executing Lab 2.06" << endl;

	int userChoice;
	int PLAYER_X_SELECTION = -1;
	vector<int> board{ 0,0,0,0,0,0,0,0,0 };

	while (true) // i.e. an infinite loop
	{
		cout << "Enter the a number from 1-9 to pick the square that you would like to place an X: ";
		cin >> userChoice;
		if (!cin.fail()) {
			if ((userChoice > 9) || (userChoice < 1))
				cout << "Your number is out of bounds. Please try again." << endl;
			else {
				break; // yes, exit loop
			}
		}
		else {
			// cin.fail() is true
			cin.clear(); // clear the fail() condition
			cout << "You have entered an invalid integer, please try again" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flushes input up to eol

	}

	board[(size_t) userChoice - 1] = PLAYER_X_SELECTION; // use symbolic constant here; need cast to size_t to get around warning

	cout << "------" << endl;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 0)
			cout << "Z|";
		if (board[i] == PLAYER_X_SELECTION) // use symbolic constant here
			cout << "X|";
		if ((i + 1) % 3 == 0)
			cout << endl << "------" << endl;

	};

}

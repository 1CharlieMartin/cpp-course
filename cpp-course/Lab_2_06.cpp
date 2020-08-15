#include "Lab_2_06.h"


void Lab_2_06::execute()
{
	cout << "Executing Lab 2.06" << endl;

	int userChoiceX;
	int userChoiceO;
	const int PLAYER_X_SELECTION = -1;
	const int SPOT_OPEN = 0;
	const int PLAYER_O_SELECTION = 1;
	vector<int> board{ SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN,SPOT_OPEN };
	int p = 1;


	cout << "Welcome to tic-tac-toe. X goes first" << endl;
	string x_name;
	string o_name;
	cout << "What is your name X? ";
	cin >> x_name;
	cout << endl << "What is your name O? ";
	cin >> o_name;
	cout << endl;

	while (p < 5) // i.e. an infinite loop
	{
		while (true){
			cout << "Enter the a number from 1-9 to pick the square that you would like to place an X: ";
			cin >> userChoiceX;
			if (!cin.fail()) {
				if ((userChoiceX > 9) || (userChoiceX < 1))
					cout << "Your number is out of bounds. Please try again." << endl;
				else if (board[userChoiceX] != SPOT_OPEN)
					cout << "That spot is not open. Please try again." << endl;
				else
					break;

			}
			else {
				// cin.fail() is true
				cin.clear(); // clear the fail() condition
				cout << "You have entered an invalid integer, please try again" << endl;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flushes input up to eol
		}

		while (true) {
			cout << "Enter the a number from 1-9 to pick the square that you would like to place an O: ";
			cin >> userChoiceO;
			if (!cin.fail()) {
				if ((userChoiceO > 9) || (userChoiceO < 1))
					cout << "Your number is out of bounds. Please try again." << endl;
				else if (board[userChoiceO] != SPOT_OPEN)
					cout << "That spot is not open. Please try again." << endl;
				else
					break;

			}
			else {
				// cin.fail() is true
				cin.clear(); // clear the fail() condition
				cout << "You have entered an invalid integer, please try again" << endl;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flushes input up to eol
			
		}
		

		board[(size_t)userChoiceX - 1] = PLAYER_X_SELECTION; // use symbolic constant here; need cast to size_t to get around warning
		board[(size_t)userChoiceO - 1] = PLAYER_O_SELECTION;

		cout << "------" << endl;
		for (int i = 0; i < board.size(); i++) {
			if (board[i] == SPOT_OPEN)
				cout << "Z|";
			if (board[i] == PLAYER_X_SELECTION) // use symbolic constant here
				cout << "X|";
			if (board[i] == PLAYER_O_SELECTION) // use symbolic constant here
				cout << "O|";
			if ((i + 1) % 3 == 0)
				cout << endl << "------" << endl;

		};

	}

	

}

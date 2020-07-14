#include "Lab_2_04.h"


void Lab_2_04::execute()
{
	cout << "Executing Lab 2.04" << endl;

	//** Code for Simple Prize Selector goes here
	cout << "Simple Prize Selector" << endl;

	//** Code for Food Guessing Quiz goes here
	cout << "Food Guessing Quiz" << endl;

	// Starter code
	std::array<string, 6> food { "donuts", "pancakes", "bacon", "waffles", "eggs", "bagels" }; // initializer list
	std::array<int, 6> score { 0, 0, 0, 0, 0, 0 };

	cout << "Please answer y or n to each question" << endl;
	char YorN;

	cout << "Do you like food with holes? ";
	cin >> YorN;
	//** error checking goes here

	if (YorN == 'y') {
		score[0] = score[0] + 1;
		score[5] = score[5] + 1;
    }

	//** other questions go here

}

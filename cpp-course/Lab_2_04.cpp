#include "Lab_2_04.h"


void Lab_2_04::execute()
{
	cout << "Executing Lab 2.04" << endl;

	//** Code for Simple Prize Selector goes here
	int userNum;
	cout << "Simple Prize Selector" << endl;
	std::array<string, 10> prize{ "Teddy Bear", "Gift Card", "Bracelet", "Toy Car", "Prize Tickets", "$10,000", "Dog", "Dog food", "Tortilla","Sombrero" };
	cout << "Pick a number from 0 to 9 determine your prize:";
	cin >> userNum;

	if ((userNum < 0) || (userNum > prize.size() - 1)) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	else {
		cout << "Your prize is: " << prize[userNum] << endl;
	}

	//** Code for Food Guessing Quiz goes here
	cout << "Food Guessing Quiz" << endl;

	// Starter code - part 1
	//** You can change these if you like but you need 6 foods.
	std::array<string, 6> food{ "donuts", "pancakes", "bacon", "waffles", "eggs", "bagels" }; // initializer list
	std::array<int, 6> score{ 0, 0, 0, 0, 0, 0 };

	cout << "Please answer y or n to each question" << endl;
	char YorN;

	cout << "Do you like food with holes? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[0] = score[0] + 1;
		score[5] = score[5] + 1;
	}

	cout << "Do you like food that is sweet ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[0] = score[0] + 1;
		score[1] = score[1] + 1;
		score[3] = score[3] + 1;

	}

	cout << "Do you like food that comes from animals? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[2] = score[2] + 1;
		score[4] = score[4] + 1;
	}

	cout << "Do you like meat? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[2] = score[2] + 1;
	}

	cout << "Do you like food with syrup? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[1] = score[1] + 1;
		score[3] = score[3] + 1;
	}

	cout << "Do you like breakfast foods? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[0] = score[0] + 1;
		score[1] = score[1] + 1;
		score[2] = score[2] + 1;
		score[3] = score[3] + 1;
		score[4] = score[4] + 1;
		score[5] = score[5] + 1;
	}

	cout << "Do you like food made of bread? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[0] = score[0] + 1;
		score[5] = score[5] + 1;
		score[1] = score[1] + 1;
		score[3] = score[3] + 1;
	}

	cout << "Do you like food that gets cooked? ";
	cin >> YorN;

	if ((YorN != 'y') && (YorN != 'n')) {
		cout << "Your input is out of range." << endl;
		exit(0);
	}

	if (YorN == 'y') {
		score[2] = score[2] + 1;
		score[4] = score[4] + 1;
	}

	//** Starter code - part 2
	// std::sort(score.begin(), score.end());  //once I sort score how will I know which position corresponds to which food?

	array<int, 6>::const_iterator it = max_element(score.begin(), score.end());
	int max_element_index = (int) (it - score.begin());
	cout << "The food with the highest score is " << food[max_element_index] << endl;;
	cout << "The highest score is " << to_string(score[max_element_index]) << endl;

}

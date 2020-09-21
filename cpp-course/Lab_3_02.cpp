#include "Lab_3_02.h"


void Lab_3_02::execute()

{

	string userName;

	cout << "Executing Lab 3.02" << endl;
	
	//** Code for Part 1 goes here
	cout << "Enter your name:" << endl;
	cin >> userName;

// Note that here in the cpp file you can't tell if the birthday_song function
// is public or private. You have to look in the header file.
/*
Name: birthday_song
Purpose: Prints out a personalized birthday song.
Input: name (string)
Returns: void
*/
	birthday_song(userName);

	//** Code for Part 2 goes after the array declaration.
	array<string, 13> deck_of_cards = {"A", "2", "3", "4", "5", "6", "7", "8", "9",
	"10", "J", "Q", "K"};

/*
Name: card_picker
Purpose: Prints out 5 randomized cards.
Input: deck (array)
Returns: void
*/
	card_picker(deck_of_cards);

}


void Lab_3_02::birthday_song(const string& name) {
	//** Code goes here
	cout << "Happy birthday to you!" << endl << "Happy birthday to you!" << endl << "Happy birthday dear " << name << "!" << endl << "Happy birthday to you!" << endl;
};

void Lab_3_02::card_picker(const array<string, 13>& deck) {
	int randNum1;
	int randNum2;
	int randNum3;
	int randNum4;
	int randNum5;

	srand((unsigned int)time(NULL));
	randNum1 = rand() % 13 + 1;

	//srand((unsigned int)time(NULL));
	randNum2 = rand() % 13 + 1;

	//srand((unsigned int)time(NULL)); 
	randNum3 = rand() % 13 + 1;

	//srand((unsigned int)time(NULL));
	randNum4 = rand() % 13 + 1;

	//srand((unsigned int)time(NULL)); 
	randNum5 = rand() % 13 + 1;

	
	cout << "Your 1st card is: " << deck[randNum1 - 1] << endl;
	cout << "Your 2nd card is: " << deck[randNum2 - 1] << endl;
	cout << "Your 3rd card is: " << deck[randNum3 - 1] << endl;
	cout << "Your 4th card is: " << deck[randNum4 - 1] << endl;
	cout << "Your 5th card is: " << deck[randNum5 - 1] << endl;

};


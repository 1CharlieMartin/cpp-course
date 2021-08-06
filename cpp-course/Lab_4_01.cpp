#include "Lab_4_01.h"

void Lab_4_01::execute() {

	cout << "Executing Lab 4.01" << endl;

	// Get an entire line of text from the user.
	string inputLine;

	cout << "Enter a word or sentence" << endl;
	getline(cin, inputLine);
	if (inputLine.empty())
		cout << "You didn't enter any input" << endl;

	//** Code goes here
	// call remove_vowels() with the user input as a parameter
	// and display the returned string.

	// call count_vowels() with the same user input as a parameter
	// and display the number of vowels.
	
	// combine the two operations into one.
	// call remove_and_count_vowels with the same user input as a parameter
	// and return a pair in which first is the vowel free string and second
	// is the number of vowels removed.
	pair<string, int> retVal = remove_and_count_vowels(inputLine);
	cout << "Your input string without vowels is " << retVal.first << endl;
	cout << "Your input string contained " << retVal.second << " vowels" << endl;

	}


string Lab_4_01::remove_vowels(const string& pUserInput) {
	string vowel_free_string;

	//** Code goes here; use a loop and check each character.

	return vowel_free_string;
}

int Lab_4_01::count_vowels(const string& pUserInput) {
	int vowel_count = 0;

	//** Code goes here; use a loop and check each character.

	return vowel_count;
}

//## This is a different way of solving the problem.
// We will go over it in a Zoom session.
pair<string, int> Lab_4_01::remove_and_count_vowels(const string& pUserInput) {
	string output_string(pUserInput);
	int vowel_count = 0;

	    size_t pos{0};
		while ((pos = output_string.find_first_of ("aeiouAEIOU", pos)) != string::npos)
		{
			vowel_count++;
			output_string.erase (pos, 1);
		}

		return make_pair(output_string, vowel_count);
}

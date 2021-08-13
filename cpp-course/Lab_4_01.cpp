#include "Lab_4_01.h"

void Lab_4_01::execute() {

	cout << "Executing Lab 4.01" << endl;

	// Get an entire line of text from the user.
	string inputLine;

	cout << "Enter a word or sentence" << endl;
	getline(cin, inputLine);
	if (inputLine.empty())
		cout << "You didn't enter any input" << endl;

	cout << "Vowel free output: " << remove_vowels(inputLine) << endl;
	cout << "There were " << count_vowels(inputLine) << " vowels in your string." << endl;


	// Combine the two operations into one.
	// call remove_and_count_vowels with the same user input as a parameter
	// and return a pair in which first is the vowel free string and second
	// is the number of vowels removed.
	pair<string, int> retVal = remove_and_count_vowels(inputLine);
	/*cout << "Your input string without vowels is " << retVal.first << endl;
	cout << "Your input string contained " << retVal.second << " vowels" << endl;*/

	}


string Lab_4_01::remove_vowels(const string& pUserInput) {
	string vowel_free_string;

	for (char current_char : pUserInput) {
		if (current_char != 'a' && current_char != 'e' && current_char != 'i' && current_char != 'o' && current_char != 'u' &&
			current_char != 'A' && current_char != 'E' && current_char != 'I' && current_char != 'O' && current_char != 'U')
			vowel_free_string.append(1, current_char);
	}

	return vowel_free_string;
}

int Lab_4_01::count_vowels(const string& pUserInput) {
	int vowel_count = 0;

	for (char current_char : pUserInput) {
		if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u' ||
			current_char == 'A' || current_char == 'E' || current_char == 'I' || current_char == 'O' || current_char == 'U')
			vowel_count++;
	}
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

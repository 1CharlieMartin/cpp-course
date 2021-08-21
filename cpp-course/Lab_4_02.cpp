#include "Lab_4_02.h"

void Lab_4_02::execute() {

	cout << "Executing Lab 4.02" << endl;

	// Get an entire line of text from the user.
	string inputLine;

	cout << "Enter one or more fruits in the singular, separated by one or more spaces)" << endl;
	getline(cin, inputLine);
	if (inputLine.empty()) {
		cout << "You didn't enter any input" << endl;
		return;
	}

	// The input from the user is a single string. We need to split the string up into a list
	// of individual fruits.
	vector<string> listOfFruits = splitString(inputLine, "\\s+");

	cout << "Fruit plurals: " << pluralize_fruits(listOfFruits) << endl;

	cout << "Enter a single word to be reversed" << endl;
	getline(cin, inputLine);
	if (inputLine.empty()) {
		cout << "You didn't enter any input" << endl;
		return;
	}

	//** CODE goes here to call reverse_string and display the results.
	}


string Lab_4_02::pluralize_fruits(const vector<string>& pSingularFruits) {
	string oneFruit;
	string pluralized_fruits;

	// Use a standard 'for' loop
	for (int i = 0; i < pSingularFruits.size(); i++) {
		oneFruit = pSingularFruits[i];

		if (oneFruit.back() = 'y') { // back() is a function that returns the last character in a string
			oneFruit.pop_back(); // remove the last character
			oneFruit.append("ies");
		}

		cout << (pluralized_fruits) << endl;

	}

	return pluralized_fruits;
}

//** CODE goes here for reverse_string.


std::vector<std::string> Lab_4_02::splitString(const std::string& stringToSplit, const std::string& regexPattern)
{
	std::vector<std::string> result;

	const std::regex rgx(regexPattern);
	std::sregex_token_iterator iter(stringToSplit.begin(), stringToSplit.end(), rgx, -1);

	for (std::sregex_token_iterator end; iter != end; ++iter)
	{
		result.push_back(iter->str());
	}

	return result;
}



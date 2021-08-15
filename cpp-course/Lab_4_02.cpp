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
	list<string> listOfFruits = splitString(inputLine, "\\s+");

	cout << "Fruit plurals: " << pluralize_fruits(listOfFruits) << endl;

	cout << "Enter a single word to be reversed" << endl;
	getline(cin, inputLine);
	if (inputLine.empty()) {
		cout << "You didn't enter any input" << endl;
		return;
	}

	//** CODE goes here to call reverse_string and display the results.
	}


string Lab_4_02::pluralize_fruits(const list<string>& pListOfSingularFruits) {
	string pluralized_fruits;

	// Use a standard 'for' loop
	for (int i = 0; i < pListOfSingularFruits.size(); i++) {

		//** CODE goes here

	}

	return pluralized_fruits;
}

//** CODE goes here for reverse_string.


std::list<std::string> Lab_4_02::splitString(const std::string& stringToSplit, const std::string& regexPattern)
{
	std::list<std::string> result;

	const std::regex rgx(regexPattern);
	std::sregex_token_iterator iter(stringToSplit.begin(), stringToSplit.end(), rgx, -1);

	for (std::sregex_token_iterator end; iter != end; ++iter)
	{
		result.push_back(iter->str());
	}

	return result;
}

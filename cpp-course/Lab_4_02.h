#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <regex>

using namespace std;

// We define each of our labs as a c++ class.
class Lab_4_02 {

public:
	// The execute function is public so that it can be called from another part of
	// the program, in our case the main function in cpp-course.cpp.
	void execute();

private:

	// Functions declared in this section of the header file may only be called
	// from inside the execute() function or from any other private function in
	// class Lab_4_02.

	string pluralize_fruits(const list<string>& pListOfSingularFruits);

	// Utility to split a string into tokens.
	std::list<std::string> splitString(const std::string& stringToSplit, const std::string& regexPattern);

};
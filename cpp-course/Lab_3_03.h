#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

// We already define each of our labs as a c++ class.
class Lab_3_03 {

public:
	// The execute function is public so that it can be called from another part of
	// the program, in our case the main function in cpp-course.cpp.
	void execute();

private:
    // Notice how the Card class is declared in the private section of the
    // Lab_3_03 class. This means that only functions that belong to
    // Lab_3_03 (either public or private) can use the Card class. In the
	// parlance of object-oriented programming thi is called "encapsulation".
	class Card {
	public:
		Card(const string& pSuit, const string& pCard, int pValue);

		string getSuit();
		string getCard();
		int getValue();

	private:
		string suit;
		string card;
		int value;
	};

	// Functions declared in this section of the header file may only be called
    // from inside the execute() function or from any other private function in
    // class Lab_3_03.

   int player_turn(const string& player_name, vector<Card>& deck);

   int round_winner(int& p1value, int& p2value);

};



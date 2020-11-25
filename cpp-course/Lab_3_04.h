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
#include <random>

using namespace std;

// We already define each of our labs as a c++ class.
class Lab_3_04 {

public:
	// The execute function is public so that it can be called from another part of
	// the program, in our case the main function in cpp-course.cpp.
	void execute();

private:
	//## Use static constexpr as self-documentation to show that these values are used
    // as symbolic constants and will not change.
	static constexpr int PLAYER1 = 1;
	static constexpr int PLAYER2 = 2;
	static constexpr int TIE = 0;
	static constexpr int DECKEMPTY = -1;

	// Notice how the Card class is declared in the private section of the
	// Lab_3_04 class. This means that only functions that belong to
	// Lab_3_04 (either public or private) can use the Card class. In the
	// parlance of object-oriented programming this is called "encapsulation".
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

	//## Note: in order to declare the deck as a class member variable we have to put the declaration here,
	// after Card, because Card must be visible.
	vector<Card> deck = vector<Card>{
		Card("Clubs", "2", 2), Card("Clubs", "3", 3), Card("Clubs", "4", 4), Card("Clubs", "5", 5), Card("Clubs", "6", 6), Card("Clubs", "7", 7),
		Card("Clubs", "8", 8), Card("Clubs", "9", 9), Card("Clubs", "10", 10), Card("Clubs", "Jack", 11), Card("Clubs", "Queen", 12), Card("Clubs", "King", 13), Card("Clubs", "Ace", 14),
		Card("Diamonds", "2", 2), Card("Diamonds", "3", 3), Card("Diamonds", "4", 4), Card("Diamonds", "5", 5), Card("Diamonds", "6", 6), Card("Diamonds", "7", 7),
		Card("Diamonds", "8", 8), Card("Diamonds", "9", 9), Card("Diamonds", "10", 10), Card("Diamonds", "Jack", 11), Card("Diamonds", "Queen", 12), Card("Diamonds", "King", 13), Card("Diamonds", "Ace", 14),
		Card("Hearts", "2", 2), Card("Hearts", "3", 3), Card("Hearts", "4", 4), Card("Hearts", "5", 5), Card("Hearts", "6", 6), Card("Hearts", "7", 7),
		Card("Hearts", "8", 8), Card("Hearts", "9", 9), Card("Hearts", "10", 10), Card("Hearts", "Jack", 11), Card("Hearts", "Queen", 12), Card("Hearts", "King", 13), Card("Hearts", "Ace", 14),
		Card("Spades", "2", 2), Card("Spades", "3", 3), Card("Spades", "4", 4), Card("Spades", "5", 5), Card("Spades", "6", 6), Card("Spades", "7", 7),
		Card("Spades", "8", 8), Card("Spades", "9", 9), Card("Spades", "10", 10), Card("Spades", "Jack", 11), Card("Spades", "Queen", 12), Card("Spades", "King", 13), Card("Spades", "Ace", 14) };

	// Functions declared in this section of the header file may only be called
	// from inside the execute() function or from any other private function in
	// class Lab_3_04.

	//## Since the card deck is a class variable we don't need to pass it as a parameter.
	// int player_turn(const string& player_name, vector<Card>& deck);
	int player_turn(const string& player_name);

	int round_winner(int p1value, int p2value);

};
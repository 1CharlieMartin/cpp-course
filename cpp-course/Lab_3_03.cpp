#include "Lab_3_03.h"


void Lab_3_03::execute() {

	cout << "Executing Lab 3.03 Part 1" << endl;

	vector<Card> deck{
	Card("Clubs", "2", 2), Card("Clubs", "3", 3), Card("Clubs", "4", 4), Card("Clubs", "5", 5), Card("Clubs", "6", 6), Card("Clubs", "7", 7),
	Card("Clubs", "8", 8), Card("Clubs", "9", 9), Card("Clubs", "10", 10), Card("Clubs", "Jack", 11), Card("Clubs", "Queen", 12), Card("Clubs", "King", 13), Card("Clubs", "Ace", 14),
	Card("Diamonds", "2", 2), Card("Diamonds", "3", 3), Card("Diamonds", "4", 4), Card("Diamonds", "5", 5), Card("Diamonds", "6", 6), Card("Diamonds", "7", 7),
	Card("Diamonds", "8", 8), Card("Diamonds", "9", 9), Card("Diamonds", "10", 10), Card("Diamonds", "Jack", 11), Card("Diamonds", "Queen", 12), Card("Diamonds", "King", 13), Card("Diamonds", "Ace", 14), 
	Card("Hearts", "2", 2), Card("Hearts", "3", 3), Card("Hearts", "4", 4), Card("Hearts", "5", 5), Card("Hearts", "6", 6), Card("Hearts", "7", 7),
	Card("Hearts", "8", 8), Card("Hearts", "9", 9), Card("Hearts", "10", 10), Card("Hearts", "Jack", 11), Card("Hearts", "Queen", 12), Card("Hearts", "King", 13), Card("Hearts", "Ace", 14),
	Card("Spades", "2", 2), Card("Spades", "3", 3), Card("Spades", "4", 4), Card("Spades", "5", 5), Card("Spades", "6", 6), Card("Spades", "7", 7),
	Card("Spades", "8", 8), Card("Spades", "9", 9), Card("Spades", "10", 10), Card("Spades", "Jack", 11), Card("Spades", "Queen", 12), Card("Spades", "King", 13), Card("Spades", "Ace", 14)};

	// Call the standard library algorithm to shuffle the deck.
	random_shuffle(deck.begin(), deck.end());

	//** Code goes here

	//** You can put this at the bottom of your while loop.
	cout << "Remaining cards in deck " << to_string(deck.size()) << endl;
}


//** Put the contract here.
int Lab_3_03::player_turn(const string& player_name, vector<Card>& deck) {
	Card card = deck.back(); // access a card
	deck.pop_back(); // remove the card from the deck

	//** Code goes here according to the contract.

	//** Use the "getter" functions to access the private fields in the Card class.

	return card.getValue();
};

// Constructor for the private Card class.
Lab_3_03::Card::Card(const string& pSuit, const string& pCard, int pValue) : suit(pSuit), card(pCard), value(pValue) {}

// Getters
string Lab_3_03::Card::getSuit() {
	return suit;
};

string Lab_3_03::Card::getCard() {
	return card;
}

int Lab_3_03::Card::getValue() {
	return value;
}

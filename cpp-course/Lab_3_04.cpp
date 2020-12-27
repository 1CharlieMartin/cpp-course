#include "Lab_3_04.h"
#include <random>

void Lab_3_04::execute() {

	cout << "Executing Lab 3.04" << endl;

	//## The card deck was declared here as a local variable within execute()
	// but we've moved it and made it a class variable.
	// vector<Card> deck = vector<Card>{ ...

	string player1Name;
	string player2Name;


	// deprecated since c++14 random_shuffle(deck.begin(), deck.end());
	shuffle(deck.begin(), deck.end(), std::default_random_engine(std::random_device()()));

	cout << "Please enter Player 1's name: " << endl;
	cin >> player1Name;
	cout << "Please enter Player 2's name:" << endl;
	cin >> player2Name;
	cout << endl;

	while (!deck.empty()) {

		//## Since the card deck is a class variable we don't need to pass it as a parameter.
		// int p1Value = player_turn(player1Name, deck);
		int p1Value = player_turn(player1Name);
		int p2Value = player_turn(player2Name);

		if (round_winner(p1Value, p2Value) == PLAYER1) {
			player1Score++;
			cout << player1Name << " has won this round!" << endl;
		}

		else if (round_winner(p1Value, p2Value) == PLAYER2) {
			player2Score++;
			cout << player2Name << " has won this round!" << endl;
		}

		else if (round_winner(p1Value, p2Value) == TIE) {
			//** Move this code into a new function called resolveTie.
			resolveTie(player1Name, player2Name);
		}

		cout << player1Name << "'s current score is: " << player1Score << endl;
		cout << player2Name << "'s current score is: " << player2Score << endl;
		cout << "Remaining cards in deck " << to_string(deck.size()) << endl;
		cout << endl;
	}


	if (player1Score > player2Score) {
		cout << "THE WINNER OF THE GAME IS " << player1Name << "!!" << endl;
	}

	if (player2Score > player1Score) {
		cout << "THE WINNER OF THE GAME IS " << player2Name << "!!" << endl;
	}

	if (player1Score == player2Score)
		cout << "IT IS A TIE!" << endl;

}

// round_winner
// Purpose: determine the winner of the round and return the winner in the form of an int.
// Arguments:
// non-const reference to player 1's score for the round (int)
// non-const reference to player 2's score for the round (int)
// Returns: int

// int& implies that you are changing the caller's value but this is not the case here.
// So it is more correct to just use int. The header file must be changed also.
// was int Lab_3_04::round_winner(int& p1value, int& p2value) {
int Lab_3_04::round_winner(int p1value, int p2value) {
	if (p1value > p2value)
		return PLAYER1; //## use symbolic constant
	else if (p2value > p1value)
		return PLAYER2; //## use symbolic constant;

	return TIE; //## use symbolic constant
};


// player_turn
// Purpose: Remove a card from a randomized deck, print the name of the player
// who drew the card, print out the suit and name of the card, and return the value of the card
// Arguments:
// const reference to a player name (string)
// non-const reference to a deck of cards
// Returns: int

//## Since the card deck is a class variable we don't need to pass it as a parameter.
// int Lab_3_04::player_turn(const string& player_name, vector<Card>& deck) { ...
int Lab_3_04::player_turn(const string& player_name) {

	if (deck.empty()) {
		return DECKEMPTY;
	};

	Card card = deck.back(); // access a card
	deck.pop_back(); // remove the card from the deck

	string playerSuit = card.getSuit();
	string playerCard = card.getCard();
	cout << player_name << "'s card is a " << playerCard << " of " << playerSuit << "." << endl;

	return card.getValue();
};

// Constructor for the private Card class.
Lab_3_04::Card::Card(const string& pSuit, const string& pCard, int pValue) : suit(pSuit), card(pCard), value(pValue) {}

// Getters
string Lab_3_04::Card::getSuit() {
	return suit;
};

string Lab_3_04::Card::getCard() {
	return card;
}

int Lab_3_04::Card::getValue() {
	return value;
}


void Lab_3_04::resolveTie(const string& player1_name, const string& player2_name) {

	cout << "Both player's cards have the same value. This is war." << endl;

	int spoils = 2;
	while (true) {

		//## Since the card deck is a class variable we don't need to pass it as a parameter.
		// int p1ValueWar = player_turn(player1Name, deck);
		int p1ValueWar = player_turn(player1_name);
		if (p1ValueWar == DECKEMPTY)
			break;
		int p2ValueWar = player_turn(player2_name);

		if (p1ValueWar > p2ValueWar) {
			player1Score = player1Score + 2 + spoils;
			cout << player1_name << " has won the war, +" + to_string(spoils + 2) + " points!" << endl;
			break;
		}

		else if (p1ValueWar < p2ValueWar) {
			player2Score = player2Score + 2 + spoils;
			cout << player2_name << " has won the war, +" + to_string(spoils + 2) + " points!" << endl;
			break;
		}

		spoils += 2; // war continues, add to spoils
	}

};

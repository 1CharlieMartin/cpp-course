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

	string player1Name;
	string player2Name;
	int player1Score = 0;
	int player2Score = 0;
	
	

	// Call the standard library algorithm to shuffle the deck.
	random_shuffle(deck.begin(), deck.end());

	//** Code goes here
	cout << "Please enter Player 1's name: " << endl;
	cin >> player1Name;
	cout << "Please enter Player 2's name:" << endl;
	cin >> player2Name;
	cout << endl;

	while (!deck.empty()) {

		int p1Value = player_turn(player1Name, deck);
		int p2Value = player_turn(player2Name, deck);

		if (p1Value > p2Value) {
			player1Score++;
			cout << player1Name << " has won this round!" << endl;
			cout << player1Name << "'s current score is: " << player1Score << endl;
			cout << player2Name << "'s current score is: " << player2Score << endl;
		}

		else if (p2Value > p1Value) {
			player2Score++;
			cout << player2Name << " has won this round!" << endl;
			cout << player1Name << "'s current score is: " << player1Score << endl;
			cout << player2Name << "'s current score is: " << player2Score << endl;
		}

		else {
			cout << "Both player's cards have the same value. This is war." << endl;
		}

		cout << "Remaining cards in deck " << to_string(deck.size()) << endl;

		if ((deck.empty()) && (player1Score > player2Score)) {
			cout << "THE WINNER OF THE GAME IS " << player1Name << "!!" << endl;
			cout << player1Name << "'s final score was: " << player1Score << endl;
			cout << player2Name << "'s final score was: " << player2Score << endl;
		}

		if ((deck.empty()) && (player2Score > player1Score)) {
			cout << "THE WINNER OF THE GAME IS " << player2Name << "!!" << endl;
			cout << player1Name << "'s final score was: " << player1Score << endl;
			cout << player2Name << "'s final score was: " << player2Score << endl;
		}


		cout << endl;
	}
}


// player_turn
// Purpose: Remove a card from a randomized deck, print the name of the player
// who drew the card, print out the suit and name of the card, and return the value of the card
// Arguments:
// const reference to a player name (string)
// non-const reference to a deck of cards
// Returns: int

int Lab_3_03::player_turn(const string& player_name, vector<Card>& deck) {
	Card card = deck.back(); // access a card
	deck.pop_back(); // remove the card from the deck

	string playerSuit = card.getSuit();
	string playerCard = card.getCard();

	//** Code goes here according to the contract.
	cout << player_name << "'s card is a " << playerCard << " of " << playerSuit << "." << endl;
	

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

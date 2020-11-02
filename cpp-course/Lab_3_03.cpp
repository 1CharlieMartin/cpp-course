#include "Lab_3_03.h"
#include <random>


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
	Card("Spades", "8", 8), Card("Spades", "9", 9), Card("Spades", "10", 10), Card("Spades", "Jack", 11), Card("Spades", "Queen", 12), Card("Spades", "King", 13), Card("Spades", "Ace", 14) };

	string player1Name;
	string player2Name;
	int player1Score = 0;
	int player2Score = 0;
	int PLAYER1 = 1;
	int PLAYER2 = 2;
	int TIE = 0;



	// deprecated since c++14 random_shuffle(deck.begin(), deck.end());
	shuffle(deck.begin(), deck.end(), std::default_random_engine(std::random_device()()));

	//** Code goes here
	cout << "Please enter Player 1's name: " << endl;
	cin >> player1Name;
	cout << "Please enter Player 2's name:" << endl;
	cin >> player2Name;
	cout << endl;

	while (!deck.empty()) {

		int p1Value = player_turn(player1Name, deck);
		int p2Value = player_turn(player2Name, deck);

		if (round_winner(p1Value, p2Value) == PLAYER1) {
			player1Score++;
			cout << player1Name << " has won this round!" << endl;
			//** common - see below cout << player1Name << "'s current score is: " << player1Score << endl;
			//** cout << player2Name << "'s current score is: " << player2Score << endl;
		}

		else if (round_winner(p1Value, p2Value) == PLAYER2) {
			player2Score++;
			cout << player2Name << " has won this round!" << endl;
			//** common - see below cout << player1Name << "'s current score is: " << player1Score << endl;
			//** cout << player2Name << "'s current score is: " << player2Score << endl;
		}

		else if (round_winner(p1Value, p2Value) == TIE) {
			cout << "Both player's cards have the same value. This is war." << endl;
			
			int spoils = 2; //** new: keep track of spoils
			while (true) {

				int p1ValueWar = player_turn(player1Name, deck);
				int p2ValueWar = player_turn(player2Name, deck);

				if (p1ValueWar > p2ValueWar) {
					//** was player1Score = player1Score + 4;
					player1Score = player1Score + 2 + spoils;
					//** was cout << player1Name << " has won the war, +4 points!" << endl;
					cout << player1Name << " has won the war, +" + to_string(spoils + 2) + " points!" << endl;
					break;
				}

				else if (p1ValueWar < p2ValueWar) {
					//** was player2Score = player2Score + 4;
					player2Score = player2Score + 2 + spoils;
					//** was cout << player2Name << " has won the war, +4 points!" << endl;
					cout << player2Name << " has won the war, +" + to_string(spoils + 2) + " points!" << endl;
					break;
				}

				spoils += 2; //** new: war continues, add to spoils

				if (deck.empty())
					break;
			}
		}

		cout << player1Name << "'s current score is: " << player1Score << endl; //**common - move here
		cout << player2Name << "'s current score is: " << player2Score << endl; //** common - move here
		cout << "Remaining cards in deck " << to_string(deck.size()) << endl;

		//** If you move this code to the right place then you won't need to check deck.empty()
		//** starting here
		if ((deck.empty()) && (player1Score > player2Score)) {
			cout << "THE WINNER OF THE GAME IS " << player1Name << "!!" << endl;
			//** And you can eliminate this redundancy
			cout << player1Name << "'s final score was: " << player1Score << endl;
			cout << player2Name << "'s final score was: " << player2Score << endl;
		}

		if ((deck.empty()) && (player2Score > player1Score)) {
			cout << "THE WINNER OF THE GAME IS " << player2Name << "!!" << endl;
			cout << player1Name << "'s final score was: " << player1Score << endl;
			cout << player2Name << "'s final score was: " << player2Score << endl;
		}
		//** ending here


		cout << endl;
	}
}

// round_winner
// Purpose: determine the winner of the round and return the winner in the form of an int.
// Arguments:
// non-const reference to player 1's score for the round (int)
// non-const reference to player 2's score for the round (int)
// Returns: int
//** int& implies that you are changing the caller's value but this is not the case here.
//** So it is more correct to just use int. Changed the header file also.
//** was int Lab_3_03::round_winner(int& p1value, int& p2value) {
int Lab_3_03::round_winner(int p1value, int p2value) {
	if (p1value > p2value)
		return 1;
	else if (p2value > p1value)
		return 2;

	//** warning C4715: 'Lab_3_03::round_winner': not all control paths return a value
	//** was else if (p1value == p2value)
		return 0;
};


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

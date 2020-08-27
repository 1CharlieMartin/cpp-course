#include "Project_2.h"


void Project_2::execute()
{
	cout << "Executing Project 2" << endl;

	// Text Monster Game
	// Define symbolic constants
	const int FLOOR_1 = 0;
	const int FLOOR_2 = 1;
	const int FLOOR_3 = 2;
	const int ROOM_1 = 0;
	const int ROOM_2 = 1;
	const int ROOM_3 = 2;
	const int ROOM_4 = 3;
	const int ROOM_5 = 4;
	const int ROOM_6 = 5;

	// We'll use a std::list to hold the user's weapons.
	std::list<string> user_weapons; // start with an empty list

	std::list<string>::const_iterator weapons_it;

	string userInput;
	string helpFile1 = "Pick Up: Pick up the contents of the room";
	string helpFile2 = "Right: Enter the room to the right";
	string helpFile3 = "Left: Enter the room to the left";
	string helpFile4 = "Fight: Fight the monster in the current room";
	string helpFile5 = "Upstairs: Move you to the next floor up";
	string helpFile6 = "Downstairs: Move you to the next floor down";
	string helpFile7 = "Retreat: Run away from the boss monster";
	string helpFile8 = "QUIT: Quit the game";

	
	// This is the declaration of the two-dimensional array for the game board.
	// The first dimension is for the 3 floors, the second dimension is for the
	// room within each floor. You will access the contents of the two-dimensional
	// array like this: game_board[0][1], which will give you "monster".
	std::array<std::array<string, 6>, 3> game_board = { { /* floor 1 */ {"stairs up", "monster", "nothing", "sword", "nothing", "monster"}, //after player picks up object replace in here with nothing
		/* floor 2 */ {"nothing", "stairs up", "nothing", "magic crystals", "stairs down", "sword"},
		/* floor 3 */ { "PRIZE", "boss monster", "nothing", "nothing", "stairs down", "monster" }} };


	

	cout << "Welcome to Charlie's Dungeon Masterpiece!" << endl << "Type START to play!" << endl;
	cin >> userInput;

	while (true) {
		if (userInput == "START") {

			// We can represent a room on the board with a std::pair, where "first" is the
			// floor and "second" is the room.
			std::pair<int, int> user_position(FLOOR_1, ROOM_5);
			game_board[FLOOR_1][ROOM_1] = "stairs up";
			game_board[FLOOR_1][ROOM_2] = "monster";
			game_board[FLOOR_1][ROOM_3] = "nothing";
			game_board[FLOOR_1][ROOM_4] = "sword";
			game_board[FLOOR_1][ROOM_5] = "nothing";
			game_board[FLOOR_1][ROOM_6] = "monster";
			game_board[FLOOR_2][ROOM_1] = "nothing";
			game_board[FLOOR_2][ROOM_2] = "stairs up";
			game_board[FLOOR_2][ROOM_3] = "nothing";
			game_board[FLOOR_2][ROOM_4] = "magic crystals";
			game_board[FLOOR_2][ROOM_5] = "stairs down";
			game_board[FLOOR_2][ROOM_6] = "sword";
			game_board[FLOOR_3][ROOM_1] = "PRIZE";
			game_board[FLOOR_3][ROOM_2] = "boss monster";
			game_board[FLOOR_3][ROOM_3] = "nothing";
			game_board[FLOOR_3][ROOM_4] = "nothing";
			game_board[FLOOR_3][ROOM_5] = "stairs down";
			game_board[FLOOR_3][ROOM_6] = "monster";



			while (true) {
				cout << "You see " << game_board[user_position.first][user_position.second] << " in this room" << endl;
				cout << "What do you want to do?" << endl;
				cin >> userInput;

				if (userInput == "Help") {
					cout << helpFile1 << endl << helpFile2 << endl << helpFile3 << endl << helpFile4 << endl << helpFile5 << endl << helpFile6 << endl << helpFile7 << endl << helpFile8 << endl;
				}

				if (userInput == "Right") {
					if (user_position.second == ROOM_6)
						cout << "You are already in the farthest room to the right." << endl;

					//if ((game_board[user_position.first][user_position.second] == "monster") || (game_board[user_position.first][user_position.second] == "boss monster")) {
					//	cout << "YOU DIED" << endl << "You walked past a monster"
					//}

					else
						user_position.second++;
				}

				if (userInput == "Left") {
					if (user_position.second == ROOM_1)
						cout << "You are already in the farthest room to the left." << endl;

					//if ((game_board[user_position.first][user_position.second] == "monster") || (game_board[user_position.first][user_position.second] == "boss monster")) {
					//	cout << "YOU DIED" << endl << "You walked past a monster"
					//}

					else
						user_position.second--;
				}

				if (userInput == "Pickup") {
					if ((game_board[user_position.first][user_position.second] != "sword") && (game_board[user_position.first][user_position.second] != "magic crystals") && (game_board[user_position.first][user_position.second] != "PRIZE")) {
						cout << "There is nothing to pickup." << endl;
					}
					else if (user_weapons.size() < 3) {
						user_weapons.push_back(game_board[user_position.first][user_position.second]);
						cout << "You added the item." << endl;
						game_board[user_position.first][user_position.second] = "nothing";
					}
					else
						cout << "You can't pick this up because your bag is full." << endl;
				}

				if (userInput == "Upstairs") {
					if (game_board[user_position.first][user_position.second] == "stairs up") {
						user_position.first++;
					}

					else
						cout << "There are no upwards stairs in this room." << endl;
				}

				if (userInput == "Downstairs") {
					if (game_board[user_position.first][user_position.second] == "stairs down") {
						user_position.first--;
					}

					else
						cout << "There are no downwards stairs in this room." << endl;
				}

				if (userInput == "Fight") {
					if (game_board[user_position.first][user_position.second] == "monster") {

						weapons_it = find(user_weapons.begin(), user_weapons.end(), "sword");
						if (weapons_it == user_weapons.end()) {
							cout << "YOU DIED" << endl << "You fought the monster without a sword." << endl;
							break;
						}
						else {
							cout << "You killed the monster, but your sword broke!" << endl;
							user_weapons.erase(weapons_it);
							game_board[user_position.first][user_position.second] = "nothing";
						}

					}

					if (game_board[user_position.first][user_position.second] == "boss monster") {

						weapons_it = find(user_weapons.begin(), user_weapons.end(), "sword");
						if (weapons_it == user_weapons.end()) {
							cout << "YOU DIED" << endl << "You fought the monster without a sword." << endl;
							break;
						}
						else {
							user_weapons.erase(weapons_it);
							
							weapons_it = find(user_weapons.begin(), user_weapons.end(), "magic crystals");
							if (weapons_it == user_weapons.end()) {
								cout << "YOU DIED" << endl << "You fought the monster without magic crystals." << endl;
								break;
							}
							else {
								user_weapons.erase(weapons_it);
								game_board[user_position.first][user_position.second] = "nothing";
								cout << "You killed the Boss Monster! Unfortunately your sword and magic crystals are now broken." << endl;
							}
						}
					}
				}

				if (userInput == "Retreat") {
					if (game_board[user_position.first][user_position.second] == "boss monster") {
						user_position.first--;
					}
				}

				if (userInput == "QUIT")
					break;

				if ((userInput != "QUIT") && (userInput != "START") && (userInput != "Retreat") && (userInput != "Fight") && (userInput != "Help") && (userInput != "Right") && (userInput != "Left") && (userInput != "Pickup") && (userInput != "Upstairs") && (userInput != "Downstairs")) {
					cout << "That is not a command. Type Help to view the list of commands." << endl;
				}

				if (user_weapons.size() > 0) {
					if (user_weapons.front() == "PRIZE") {
						cout << "YOU WIN!" << endl;
						break;
					}
				}
			}
			cout << "Type START to play again! Or, type QUIT to quit the game." << endl;
			cin >> userInput;

			if (userInput == "QUIT")
				break;
		}
	}
	// Here's how you might use the pair.
	//cout << "The user's starting position is floor " << user_position.first + 1 << ", room " << user_position.second + 1 << endl;

	/*
	//user_weapons.push_back(game_board[user_position.first][user_position.second]); // here's how you add an element
	// And here's how you access the first element in the list (you probably won't need this)
	cout << "You added the weapon " << user_weapons.front() << endl;

	// Now find an element in a list.
	//std::list<string>::const_iterator weapons_it;
	cout << "Let's see if the user has magic crystals" << endl;
	weapons_it = find(user_weapons.begin(), user_weapons.end(), "magic crystals");
	if (weapons_it == user_weapons.end()) // here's how you tell if the find was not successful
		cout << "Nope, no magic crystals" << endl;
	else
		cout << "The user has magic crystals" << endl;

	cout << "Let's give the user magic crystals" << endl;
	//user_weapons.push_back(game_board[user_position.first][user_position.second]);  // game_board[user_position.first][user_position.second];        eg: game_board[FLOOR_2][ROOM_4]
	cout << "Let's see if the user has magic crystals" << endl;
	weapons_it = find(user_weapons.begin(), user_weapons.end(), "magic crystals");
	if (weapons_it == user_weapons.end())
		cout << "Nope, no magic crystals" << endl;
	else
		cout << "The user has magic crystals" << endl;

	// You need to know how many weapons are in the list.
	cout << "You have " << user_weapons.size() << " weapon(s)" << endl;

	// Remove an element from a list.
	cout << "Let's take away the sword" << endl;
	// First you have to find the element so that you can get an iterator to it.
	weapons_it = find(user_weapons.begin(), user_weapons.end(), "sword");
	if (weapons_it == user_weapons.end())
		cout << "The user didn't have a sword" << endl;
	else {
		// The iterator points to the element you just found ("sword").
		// You can "dereference" an iterator to get the object that it's
		// pointing to.
		cout << "Just confirming that you have a " << *weapons_it << endl;

		// Then use the same iterator to remove the element.
		user_weapons.erase(weapons_it);
		cout << "The sword has been removed" << endl;
	}
	*/
}

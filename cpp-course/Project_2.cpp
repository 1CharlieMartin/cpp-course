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

	// This is the declaration of the two-dimensional array for the game board.
	// The first dimension is for the 3 floors, the second dimension is for the
	// room within each floor. You will access the contents of the two-dimensional
	// array like this: game_board[0][1], which will give you "monster".
	std::array<std::array<string, 6>, 3> game_board = { { /* floor 1 */ {"stairs up", "monster", "nothing", "sword", "nothing", "monster"},
		/* floor 2 */ {"nothing", "stairs up", "nothing", "magic crystals", "stairs down", "sword"},
		/* floor 3 */ { "PRIZE", "boss monster", "nothing", "nothing", "stairs down", "monster" }} };

	// We can represent a room on the board with a std::pair, where "first" is the
	// floor and "second" is the room.
	std::pair<int, int> user_position(FLOOR_1, ROOM_5);

	// Here's how you might use the pair.
	cout << "The user's starting position is floor " << user_position.first + 1 << ", room " << user_position.second + 1 << endl;

	// We'll use a std::list to hold the user's weapons.
	std::list<string> user_weapons; // start with an empty list
	user_weapons.push_back(game_board[FLOOR_1][ROOM_4]); // here's how you add an element
	// And here's how you access the first element in the list (you probably won't need this)
	cout << "You added the weapon " << user_weapons.front() << endl;

	// Now find an element in a list.
	std::list<string>::const_iterator weapons_it;
	cout << "Let's see if the user has magic crystals" << endl;
	weapons_it = find(user_weapons.begin(), user_weapons.end(), "magic crystals");
	if (weapons_it == user_weapons.end()) // here's how you tell if the find was not successful
		cout << "Nope, no magic crystals" << endl;
	else
		cout << "The user has magic crystals" << endl;

	cout << "Let's give the user magic crystals" << endl;
	user_weapons.push_back(game_board[FLOOR_2][ROOM_4]);
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

}

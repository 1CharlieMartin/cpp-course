#include "Project_3.h"

void Project_3::execute() {

	cout << "Please enter the player's name: ";
	cin >> player_name;

	// handle_status();
	while (playing) {
		cout << endl << "Choose an action, " << player_name << ": ";
		string action;
		cin >> action;
		if (action == "travel" or action == "t")
			handle_travel();
		else if (action == "rest" or action == "r")
			cout << "Not yet implemented." << endl;
		//handle_rest();
		else if (action == "hunt" or action == "h")
			cout << "Not yet implemented." << endl;
		//handle_hunt();
		else if (action == "quit" or action == "q")
			playing = false;
		else if (action == "help" or action == "?")
			cout << "Not yet implemented." << endl;
		    //handle_help();
		else if (action == "status" or action == "s")
			cout << "Not yet implemented." << endl;
			//handle_status();
		else
			cout << "'" << action << "' is not a valid action. Try again." << endl;
	};

}

// Converts the current numeric date into a string.
// class variable month - a month in the range 1-12
// class variable day - a day in the range 1-31
// output: a string such as "December 24".
// Note: this function enforces calendar rules. It throws
// an exception and terminates the program on invalid
// dates such as "June 95" or "February 31".
string Project_3::date_report() {
	if (day > months[month].second) // internal safety check
		throw logic_error("Invalid day " + to_string(day) + " for month " + months[month].first);

	return "Today is " + months[month].first + " " + to_string(day);
}

int Project_3::miles_remaining() {
	return TOTAL_MILES_TO_OREGON - miles_traveled;
}

// Rolls over to the next month when the current day is larger than the number of
// days in the month. If this happens, this function also adjusts the current day
// and causes the month to wrap around if it crosses into the next year.
// Returns true if the class variables month and day were altered.
bool Project_3::maybe_rollover_month() {
	bool rolled_over = false;
	pair<string, int> current_month = months[month]; // look up current month

	if (day > months[month].second) {
		month++;
		day = 1;
		return rolled_over = true;
	}

	if (month == 13) {
		month = 1;
	}
	//if month and day are altered return rolled_over true

	return rolled_over;
}

// Causes a certain number of travel days to elapse. The days pass
// pass one at a time; this function calls the helper function
// maybe_rollover_month to keep the travel calendar on track.
// [**PY placeholder] each day brings with it a random chance
// of sickness. 
//
// input: pNumDays - an integer number of days.
void Project_3::advance_game_clock(int pNumDays) {

	int daysthisTravel = 0;
	while (daysthisTravel < pNumDays) {
		
		//random sickness placeholder
		day++;
		maybe_rollover_month();
		daysthisTravel++;
	}

	
	
}

//## PY - no need to change.
void Project_3::handle_travel() {
	// Travel a random number of miles.
	std::default_random_engine generator(std::random_device{}());;
	std::uniform_int_distribution<int> miles(MIN_MILES_PER_TRAVEL, MAX_MILES_PER_TRAVEL);
	int miles_this_travel = miles(generator);
	miles_traveled = min(miles_traveled + miles_this_travel, TOTAL_MILES_TO_OREGON);

	// Travel for a random number of days.
	std::uniform_int_distribution<int> days_this_travel(MIN_DAYS_PER_TRAVEL, MAX_DAYS_PER_TRAVEL);
	int random_travel = days_this_travel(generator);

	advance_game_clock(random_travel);

	cout << "You have traveled for " << to_string(random_travel) << " days and have covered " << to_string(miles_this_travel) << " miles." << endl;
	cout << "You are now " << to_string(miles_traveled) << " miles from Independence, with " << to_string(miles_remaining()) << " miles remaining." << endl;
	cout << date_report() << endl;
}




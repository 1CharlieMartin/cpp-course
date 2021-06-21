#include "Project_3.h"

void Project_3::execute() {

	//** choose two random days for the first month

	cout << "Please enter the player's name: ";
	cin >> player_name;

	// handle_status();
	while (playing) {
		cout << endl << "Choose an action, " << player_name << ": ";
		string action;
		cin >> action;
		if (action == "travel" or action == "t") {
			handle_travel();
			set_sick_days();
		}
		else if (action == "rest" or action == "r")
			handle_rest();
		else if (action == "hunt" or action == "h")
			handle_hunt();
		else if (action == "quit" or action == "q")
			quit = true;
		else if (action == "help" or action == "?")
			handle_help();
		else if (action == "status" or action == "s")
			handle_status();
		else
			cout << "'" << action << "' is not a valid action. Try again." << endl;
		playing = !game_is_over();
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
	pair<string, int> current_month = months[month]; // look up current month

	if (day > months[month].second) {
		month++;
		if (month > 12) // sanity check
			throw logic_error("Month illegally exceeded 12");

		day = 1;
		//** choose two random days for the next month
		//** make a function to do this
		//** void setSickDays();

		return true;
	}

	return false;
}

//bool Project_3::random_sickness_occurs() {
	//** CODE goes here
//}

void Project_3::set_sick_days() {
	//** CODE goes here
	// Need two random numbers between 1 and the number of days in the current month 
	// but they can't be the same.
	// set sick_days.first and sick_days.second
	std::default_random_engine generator2(std::random_device{}());;
	std::uniform_int_distribution<int> sickday(1, (months[month].second)/2);
	sick_days.first = sickday(generator2);
	
	std::default_random_engine generator3(std::random_device{}());;
	std::uniform_int_distribution<int> sickday2((((months[month].second) / 2) + 1), months[month].second);
	sick_days.second = sickday2(generator3);
	}
	

// Causes a certain number of travel days to elapse. The days pass
// pass one at a time; this function calls the helper function
// maybe_rollover_month to keep the travel calendar on track.
// [**PY placeholder] each day brings with it a random chance
// of sickness. 
//
// input: pNumDays - an integer number of days.
void Project_3::advance_game_clock(int pNumDays) {
	pair<string, int> current_month = months[month]; // look up current month
	int daysthisTravel = 0;
	while (daysthisTravel < pNumDays) {

		food_remaining -= 5; // eat

		//random sickness placeholder
		if (day == sick_days.first || day == sick_days.second) {
			health_level--;
			cout << "You got sick. Your health level has been decreased by one point." << endl;
		}

		if (month == 12 && day == 31)
			return;

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

void Project_3::handle_rest() {
	// Increase player's health level by 1
	bool healthLevelIncreased = false;
	if (health_level < 5) {
		health_level++;
		healthLevelIncreased = true;
	}


	// Take up random amount of days
	std::default_random_engine generator(std::random_device{}());;
	std::uniform_int_distribution<int> randDays(MIN_DAYS_PER_REST, MAX_DAYS_PER_REST);
	int days_this_rest = randDays(generator);

	advance_game_clock(days_this_rest);

	if (healthLevelIncreased == true) {
		cout << "Your health level has been increased by 1 point and it is now " << health_level << ". You rested for  " << days_this_rest << " days." << endl;
		cout << date_report() << endl;
	}

	else {
		cout << "Your health level was the maximum (5) so it has not been increased. You rested for " << days_this_rest << " days." << endl;
		cout << date_report() << endl;
	}
}

void Project_3::handle_hunt() {
	// Add 100lbs of food
	food_remaining = food_remaining + 100;
	
	// Take up random amount of days
	std::default_random_engine generator(std::random_device{}());;
	std::uniform_int_distribution<int> randDays(MIN_DAYS_PER_HUNT, MAX_DAYS_PER_HUNT);
	int days_this_hunt = randDays(generator);
	

	advance_game_clock(days_this_hunt);

	cout << "Your food supply has been increased by 100lbs. The hunt took up " << days_this_hunt << " days." << endl;
	cout << date_report() << endl;
}

void Project_3::handle_status() {
	cout << "Food: " << to_string(food_remaining) << endl;
	cout << "Health Level: " << to_string(health_level) << endl;
	cout << "Total Distance Traveled: " << to_string(miles_traveled) << endl;
	cout << date_report() << endl;
}

bool Project_3::game_is_over() {
	
	if (quit) {
		cout << player_name << ", you loser. You quit before the game was done!!" << endl;
		return true;
	}

	if (health_level < 1 || food_remaining <= 0 || ((month == 12 && day == 31) && miles_traveled < TOTAL_MILES_TO_OREGON)) {
		cout << "You lost!" << endl;
		handle_status();
		return true;
	}

	if (miles_traveled >= TOTAL_MILES_TO_OREGON) {
		cout << "You Won!!!!" << endl;
		handle_status();
		return true;
	}

	return false;
}

void Project_3::handle_help() {
	cout << help_text << endl;
}





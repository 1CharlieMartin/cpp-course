#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

class Project_3 {

public:
	// The execute function is public so that it can be called from another part of
	// the program, in our case the main function in cpp-course.cpp.
	void execute();

private:
	//## Use static constexpr as self-documentation to show that these values are used
	// as symbolic constants and will not change.
	static constexpr int MIN_MILES_PER_TRAVEL = 30;
	static constexpr int MAX_MILES_PER_TRAVEL = 60;
	static constexpr int MIN_DAYS_PER_TRAVEL = 3;
	static constexpr int MAX_DAYS_PER_TRAVEL = 7;

	static constexpr int MIN_DAYS_PER_REST = 2;
	static constexpr int MAX_DAYS_PER_REST = 5;
	static constexpr int HEALTH_CHANGE_PER_REST = 1;
	static constexpr int MAX_HEALTH = 5;

	static constexpr int FOOD_PER_HUNT = 100;
	static constexpr int MIN_DAYS_PER_HUNT = 2;
	static constexpr int MAX_DAYS_PER_HUNT = 5;

	static constexpr int FOOD_EATEN_PER_DAY = 5;
	static constexpr int TOTAL_MILES_TO_OREGON = 2000;

	// Variables that represent the state of the game.
	int miles_traveled = 0;
	int food_remaining = 500;
	int health_level = 5;
	pair<int, int> sick_days;
	int month = 3;
	int day = 1;
	int sicknesses_suffered_this_month = 0;
	string player_name;
	bool playing = true;
	bool quit = false;
	bool loop = true;

	// Months and the number of days in each month. Put a dummy entry in location 0 so that
	// we can use the number of the month as the index into the array. Since we don't know
	// the year in which our journey takes place, we'll use 28 as the number of days for
	// February.
	array<pair<string, int>, 13> months = { { {"not_used", 0 }, { "January", 31 }, { "February", 28 },
			 { "March", 31 }, { "April", 30 }, { "May", 31 }, { "June", 30 },
			 { "July", 31 }, { "August", 31 }, { "September", 30 }, { "October", 31 },
			 { "November", 30 }, { "December", 31 } }  };

	string welcome_text =
		R"(Welcome to the Oregon Trail! The year is 1850 and Americans are\n)"
		R"(headed out West to populate the frontier.Your goal is to travel\n)"
		R"(by wagon train from New York City to Oregon(2000 miles).You start\n)"
		R"(on March 1st, and your goal is to reach Oregon by December 31st.\n)"
		R"(The trail is arduous.Each day costs you food and health. You\n")"
		R"(can hunt and rest, but you have to get there before winter!\n)";

	string help_text =
		R"("Each turn you can take one of 3 actions:\n\n)"
		R"(travel - moves you randomly between 30 - 60 miles and takes\n)"
		R"(3 - 7 days(random).\n)"
		R"(rest - increases health 1 level(up to 5 maximum) and takes\n)"
		R"(2 - 5 days(random).\n)"
		R"(hunt - adds 100 lbs of food and takes 2 - 5 days(random).\n\n)"
		R"(When prompted for an action, you can also enter one of these\n)"
		R"(commands : \n\n)"
		R"(status - lists food, health, distance traveled, and day.\n)"
		R"(help - lists all the commands.\n)"
		R"(quit - will end the game.\n\n)"
		R"(You can also use these shortcuts for commands:\n\n)"
		R"('t', 'r', 'h', 's', '?', 'q'\n\n)";

	string good_luck_text = R"("Good luck, and see you in Oregon!\n)";

	// Functions declared in this section of the header file may only be called
	// from inside the execute() function or from any other private function in
	// class Project_3.

	// Functions called from the main loop.
	void handle_travel();

	void handle_rest();

	void handle_hunt();

	void handle_status();

	void handle_help();

	// Helper functions.
	void advance_game_clock(int pNumDays, const string& pActivity);

	void maybe_rollover_month();

	string date_report();

	void set_sick_days();

	bool game_is_over();

};
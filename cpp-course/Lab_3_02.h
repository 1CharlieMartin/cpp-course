#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>

using namespace std;

// We already define each of our labs as a c++ class.
class Lab_3_02 {

public:
	// The execute function is public so that it can be called from another part of
	// the program, in our case the main function in cpp-course.cpp.
	void execute();

private:
   // Functions declared in this section of the header file may only be called
   // from inside the execute() function or from any other private function in
   // class Lab_3_02.
   void birthday_song(const string& name);
   void card_picker(const array<string, 13>& deck);

};

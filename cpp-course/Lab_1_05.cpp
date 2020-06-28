#include "Lab_1_05.h"

void Lab_1_05::execute()
{
	cout << "Executing Lab 1.05" << endl;

	exercise_1();
	exercise_2();
	exercise_3();
}

void Lab_1_05::exercise_1()
{
	cout << "Executing Lab 1.05, exercise_1" << endl;
	int height;
	//const float INCHES_PER_FOOT = 12.0f;
	const int INCHES_PER_FOOT = 12;

	cout << "Please enter your height in integer inches: ";
	cin >> height;

	//cin_fail is undefined
	//## Since cin is a class and fail() is a function, the correct syntax is
	// cin.fail()
	//## You can also try google: c++ cin fail and you'll see lots of examples
	//if (cin_fail())
	if (cin.fail())
	{
		cout << "Sorry, your input was in the wrong format" << endl;
		exit(1);
	}

	//## Please fix and test all uses of cin

	int heightFeet = height / INCHES_PER_FOOT;
	int heightInches = height % INCHES_PER_FOOT; //## constant must be an integer
	//##int heightInches = height - (heightFeet * INCHES_PER_FOOT);
	cout << "You are " << heightFeet << " feet and " << heightInches << " inches tall." << endl;

}
void Lab_1_05::exercise_2()
{
	cout << "Executing Lab 1.05, exercise_2" << endl;

	const float INCHES_TO_METERS = 0.0254f;
	const float POUNDS_TO_KILOS = 2.2f;
	int feetOfHeight;
	int inchesOfHeight;
	float weightInPounds;
	

	cout << "Please enter your height in feet and inches: ";
	cin >> feetOfHeight;
	cin >> inchesOfHeight;

	cout << "Please enter your weight in pounds: ";
	cin >> weightInPounds;

	int fullHeightInches = (feetOfHeight * 12) + inchesOfHeight;
	float heightMeters = fullHeightInches * INCHES_TO_METERS;
	//## The instructions say to divide weight in pounds by the number of pounds in a kilo
	float weightInKilos = weightInPounds * POUNDS_TO_KILOS;
	float BMI = weightInKilos / (pow(heightMeters, 2));

	cout << "Your BMI is " << BMI << "." << endl;
	//the BMI is not correct but I don't know why.
}

void Lab_1_05::exercise_3()
{
	const float SEC_TO_MIN = 60.0f;
	const float MIN_TO_DEGREE = 60.0f;
	int degreesInitial;
	int minsInitial;
	int secInitial;
	float finalDegrees;

	cout << "Executing Lab 1.05, exercise_3" << endl;

	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First, enter the degrees: ";
	cin >> degreesInitial;
	cout << "Next, enter the minutes of arc: ";
	cin >> minsInitial;
	cout << "Finally, enter the seconds of arc: ";
	cin >> secInitial;

	finalDegrees = (secInitial / SEC_TO_MIN / SEC_TO_MIN) + (minsInitial / MIN_TO_DEGREE) + degreesInitial;
	cout << degreesInitial << " degrees, " << minsInitial << " minutes, " << secInitial << " seconds = " << finalDegrees << " degrees." << endl;
}
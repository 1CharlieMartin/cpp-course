#include "Lab_2_02.h"


void Lab_2_02::execute()
{
	cout << "Executing Lab 2.02" << endl;

	int a = 100;
	string b = "science";
	bool c = true;
	bool d = (!c && (a > 75) && (b == "science"));



	cout << "Done" << endl;


	//Part 2: President
	string age;
	string resident;
	string natural;
	bool ageBool = false;
	bool residentBool = false;
	bool naturalBool = false;

	cout << "Executing President" << endl << "Answer each question with yes or no." << endl;

	cout << "Are you older than 35?";
	cin >> age;
	cout << "Have you been a resident of the US for at least 14 years?";        //wouldn't this be true automatically if the person is over 35 and natual born citizen?
	cin >> resident;
	cout << "Are you a natural born citizen?";
	cin >> natural;

	if (age == "yes") {
		ageBool = true;
	}

	if (resident == "yes") {
		residentBool = true;
	}

	if (age == "yes") {
		naturalBool = true;
	}



	if (ageBool == true && residentBool == true && naturalBool == true) {
		cout << "TRUE" << endl;
	}

	else {
		cout << "FALSE" << endl;
	}


	//Part 3 Roller Coaster

	string height;
	string over18;
	string frequentPass;
	string money;
	bool heightBool = false;
	bool over18Bool = false;
	bool FrequentPassBool = false;
	bool moneyBool = false;
	cout << "Excecuting Roller Coaster" << endl << "Answer each question with yes or no." << endl;

	cout << "Are you over 50 inches tall?";
	cin >> height;

	if (height == "no") {
		cout << "Are you over the age of 18?";
		cin >> over18;
	}

	cout << "Do you have a Frequent Rider Pass?";
	cin >> frequentPass;

	if (frequentPass == "yes") {
		cout << "Do you have 2 quarters?";
		cin >> money;
	}

	else {
		cout << "Do you have 4 quarters?";
		cin >> money;
	}


	if (height == "yes") {
		heightBool = true;
	}

	if (over18 == "yes") {
		over18Bool = true;
	}

	if (frequentPass == "yes") {
		FrequentPassBool = true;
	}

	if (money == "yes") {
		moneyBool = true;
	}

	if ((heightBool || over18Bool) && moneyBool) {
		cout << "TRUE" << endl;
	}

	else {
		cout << "FALSE" << endl;
	}




}

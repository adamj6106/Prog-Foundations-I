// JohnsonAMenuProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Adam Johnson
//9.21.2026
//Menu Program V1: Create a menu and error check

#include <iostream>
#include <string>

using namespace std;


int main()
{
	//variables
	int wizardChoice;
	string wizardName;
	char patronusChoice;
	string patronusName;

	//program title and description
	cout << "Menu program - Create a Wizard" << endl;
	cout << "Created by: Adam Johnson" << endl;
	cout << "This program will ask the user to make 2 menu selections" << endl;
	cout << "by choising a wizard and their patronus and then error check" << endl << endl;

	//wizard menu and selection
	cout << "Wizard Choices" << endl;
	cout << "1: Harry Potter" << endl;
	cout << "2: Ron Weasley" << endl;
	cout << "3: Hermione Granger" << endl;
	cout << "Enter the number for your wizard choice (1,2,3)";
	cin >> wizardChoice;

	//error check
	if (!cin)
	{
		cout << "You entered invalid data. Program terminating" << endl;
	}

	else if (wizardChoice < 1 || wizardChoice > 3)
	{
		cout << "Entered a number outside the range. Program terminating" << endl;
		return 1;
	}

	//assign a wizard
	if (wizardChoice == 1)
	{
		wizardName = "Harry Potter";
	}
	else if (wizardChoice == 2)
	{
		wizardName = "Ron Weasley";
	}
	else
	{
		wizardName = "Hermione Granger";
	}

	//patronus menu and selection
	cout << endl;
	cout << "Patrounus Menu" << endl;
	cout << "a: Stag" << endl;
	cout << "b: Otter" << endl;
	cout << "c: Dog" << endl;
	cout << "Enter a letter for your potrounus choice (a,b,c):";
	cin >> patronusChoice;

	//error check
	if (patronusChoice == 'a' || patronusChoice == 'A')
	{
		patronusName = "Stag";
	}
	else if (patronusChoice == 'b' || patronusChoice == 'B')
	{
		patronusName = "Otter";
	}
	else if (patronusChoice == 'c' || patronusChoice == 'C')
	{
		patronusName = "Dog";
	}
	else
	{
		patronusName = "<Invalid choice made>";
	}

	//output to the console
	cout << endl;
	cout << "you chose the wizzard " << wizardName << " and the patronus " << patronusName << "." << endl;

	return 0;
}


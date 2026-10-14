// JohnsonAErrorChecking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Error Checking V1: error check if input file and error check user input

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//Variables
	int num1;

	//file stream variables
	ifstream fin;

	//open file
	fin.open("adam.txt");


	//program title and description
	cout << "Error Checking Program" << endl;
	cout << "Created by Adam Johnson" << endl;
	cout << "This program is an example of how to use if/else statments" << endl;
	cout << "to check to see if an input file is found and to" << endl;
	cout << "error check user input" << endl << endl;

	//example 1- if file is not found, report to user and terminate
	/*if (!fin) //! means not, so the statment is is fin not working b/c there is no file for input
	{
		cout << "Input file not found";


	}*/

	//exmaple 2- check user input for valid data
	cout << "Enter an integer between 1 and 5: ";
	cin >> num1;

	if (!cin) //asks "is cin not working correctly because the user entered invalid data
	{
		cout << "you entered invalid data. Program terminated" << endl;
		return 1;

	}
	else if (num1 < 1 || num1 > 5)
	{
		cout << "you entered a number outside the range. Program terminated" << endl;
	}
	else //else cannot have a condition
	{
		cout << "Congrats your program finished successfully. Goodbye" << endl;
	}


	//close file
	fin.close();



	return 0;
}

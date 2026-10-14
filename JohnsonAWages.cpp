// JohnsonAWages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Adam Johnson
//8.26.26
//Wages V1: This program will ask the user for info, calculate wages, print to the console

#include <iostream>
#include <string>

using namespace std;

//constant variables (do not change)
const double TAX_RATE = .10;

int main()
{
	//declare variables
	string fName;
	string lName;
	double hoursWorked; 
	double hourlyWage;
	double net;
	double gross;

	//program title and description 
	cout << "wages program" << endl;
	cout << "created by Adam Johnson" << endl;
	cout << "This program will ask the user for their first and last name, hours worked,\n";
	cout << "and hourly wage. We will calculate net and gross pay and print to the console." << endl << endl;
	
	//collect user input
	cout << "Enter your first name: ";
	cin >> fName; 
	cout << "Enter your last name: ";
	cin >> lName;
	cout << "Enter your hours worked (can be patrial hours): ";
	cin >> hoursWorked;
	cout << "Enter your hourly wage (ex 13.75): ";
	cin >> hourlyWage;
	
	//Calculations
	gross = hourlyWage * hoursWorked;
	net = gross - (gross * TAX_RATE);

	//Output to the console
	cout << endl << endl;
	cout << fName << " " << lName << endl;
	cout << "Your gross pay is: $" << gross << endl;
	cout << "Your net pay is: $" << net << " calculated with a " << TAX_RATE *100 << "% tax rate." << endl;

	return 0;
}
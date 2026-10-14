// JohnsonAdamPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adam Johnson
// Practice V1: Ask  the user for info and print it to the console

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//declare variables
	string fName;
	string lName;
	char mInital;
	int age;
	double gpa;
	string major;
	char hopefulGrade;
	string graduationYear;
	string clas;



	//program title and description
	cout << "Practice program" << endl;
	cout << "Created by: Adam Johnson" << endl;
	cout << "This program will ask the user for the first and last name, middle inital, age, \n";
	cout << "and current gpa. we will then print that info to the console." << endl << endl; 

	//collect the user input 
	cout << "Enter your first name: ";
	cin >> fName;
	cout << "Enter your middle intial: ";
	cin >> mInital;
	cout << "Enter your last name: ";
	cin >> lName;
	cout << "Enter your age in years: ";
	cin >> age;
	cout << "Enter your GPA (ex: 4.00) : ";
	cin >> gpa;
	cout << "Enter your hopefull grade in this class (ex: A,B) : ";
	cin >> hopefulGrade;
	cout << "Enter your graduation year : ";
	cin >> graduationYear;
	cout << "Enter your class (ex: Junior, Senior) : ";
	cin >> clas;
	cin.ignore();
	cout << "Enter your Major: ";
	getline(cin, major); //gets the user input including the space

	//output to the console
	cout << endl << endl; 
	cout << fName << " " << mInital << ". " << lName << endl;
	cout << "your age is : " << age << endl;
	cout << "your current major is: " << major << " and your current GPA is: " << gpa << endl;
	cout << "Your hopefull grade in this class is a " << hopefulGrade << ", your graduation year is " << graduationYear << ", and your a " << clas << endl;
	

	return 0;
}


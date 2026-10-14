// JohnsonACinerrors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


int main()
{
  //declaring variables 
	int int1, int2;
	double dbl;
	char ch;

	cout << "this program is designed to read two integer values follwed by \n";
	cout << "a double value, followed by a character value." << endl << endl;

	cout << "Enter a number, number, double, character seperated by spaces: ";
	cin >> int1 >> int2 >> dbl >> ch;

	cout << "Integer 1: " << int1 << endl;
	cout << "Integer 2: " << int2 << endl;
	cout << "Double: " << dbl << endl;
	cout << "Character: " << ch << endl;






	return 0;


}

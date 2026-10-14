// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Adam Johnson
//8.31.26
//Budget V1: ask the usre for pay rate and hours worked. will use this to calculate a budget and print to the console

#include <iostream>
#include <string>

using namespace std;

//Constants
const double TAX_RATE = 0.1;
const double MORTGAGE_RATE = 0.2;
const double UTILITY_RATE = 0.2;
const double SAVINGS_RATE = 0.15;
const double FOOD_RATE = 0.25;

int main()
{
    //declare variables 
    string fName;
    string lName;
    double payRate;
    double hoursWorked;
    double gross;
    double taxes;
    double mortgage;
    double food;
    double utilities;
    double net;
    double savings;
    double leftover;

    //program title and decription
    cout << "budget program" << endl;
    cout << "Created by: Adam Johnson" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "This program will create a budget for the user based on \n";
    cout << "based on total hours worked and pay rate. Then cacluate a buidget based on the following" << endl;
    cout << "10% for taxes, " << endl;
    cout << "20% for mortgage, " << endl;
    cout << "20% for utilities, " << endl;
    cout << "20% for food, " << endl;
    cout << "15% for savings, " << endl;
    cout << "Then print gross, net , and budget to the screen" << endl;
    cout << "**********************************************************************************************************" << endl;
    
    //Collect user inout
    cout << "Enter your fist name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName; 
    cout << "Enter your hourly wage (Ex: 13.75): ";
    cin >> payRate;
    cout << "Enter your hours worked this month (Ex: 40 or 75.5) :";
    cin >> hoursWorked;
    
    // Calculations
    gross = payRate * hoursWorked;
    taxes = gross * TAX_RATE;
    net = gross - taxes;
    mortgage = net * MORTGAGE_RATE;
    utilities = net * UTILITY_RATE;
    food = net * FOOD_RATE;
    savings = net * SAVINGS_RATE;
    leftover = net - (mortgage + utilities + food + savings);

    //output to console
    cout << endl << endl;
    cout << "Your name is: " << fName << " " << lName << "." << endl;
    cout << "Your worked " << hoursWorked << " hours this month."<<endl;
    cout << "Your hourly wage is: $" << payRate << endl;
    cout << "Your gross pay this month is: $" << gross << endl;
    cout << "Your taxes on your gross earnings is: $" << taxes << endl;
    cout << "Your net pay after taxes is: $" << net << endl;
    cout << "Your mortgages this month is: $" << mortgage << endl;
    cout << "Your utilities this month is: $" << utilities << endl;
    cout << "Your food cost this month is: $" << food << endl;
    cout << "Your savings this month is: $" << savings << endl;
    cout << "Your total amount left over is: $" << leftover << endl;

    return 0;
}

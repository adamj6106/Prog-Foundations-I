// JohnsonABudgetV3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Budget V3

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//constant variables
const double TAX_RATE = .10;
const int COLUMN_ONE = 11;
const int DOLLAR_SIGN = 2;
const int MONEY = 8;
const int NAME = 40;

int main()
{
    //declare variables
    int outputChoice;
    char periodChoice;
    string payPeriod;
    int multiplyer;
    string name;
    double payRate;
    double hoursWorked;
    double gross;
    double taxes;
    double mortgage;
    double mortgageRate;
    double utilities;
    double utilitiesRate;
    double food;
    double foodRate;
    double net;
    double savings;
    double savingsRate;
    double leftover;
    double beauty;
    double beautyRate;
    double books;
    double booksRate;


    //delclare file variables
    ofstream fout;

    //open file
    fout.open("budget.txt");

    //program title and description
    cout << "Budget Program" << endl;
    cout << "Created by: Mrs. Mitchell" << endl;
    cout << "******************************************************************************" << endl;
    cout << "This program will create a budget for the user based on " << endl;
    cout << "total hours worked, payrate and tax rate of 10% then calculate a budget based on the precentages " << endl;
    cout << "provided by the user for: food, mortgage, utilities, savings, beauty, and books. \n";
    cout << "Then print gross, net, leftover, and budget info to the screen." << endl;
    cout << "******************************************************************************" << endl;


    //user menu
    cout << "    menu" << endl;
    cout << "Time Period Options" << endl;
    cout << "W) Weekly" << endl;
    cout << "B) Bi-Weekly" << endl;
    cout << "M) Monthly" << endl;
    cout << "Output menu" << endl;
    cout << "------------" << endl;
    cout << "1: print to the console" << endl;
    cout << "2: Print to the file" << endl;
    cout << "3: Print to both" << endl;
    cout << "Please enter your time period choice (W,B,M)" << endl;
    cin >> periodChoice;

    //error checking
    if (periodChoice != 'W' && periodChoice != 'w' && periodChoice != 'B' && periodChoice != 'b' && periodChoice != 'M' && periodChoice != 'm')
    {
        cout << "You choice a invalid option; Program terminating" << endl;
        return 1;
    }

    cout << "please enter your output choice (1,2,3)" << endl;
    cin >> outputChoice;

    //error check
    if (!cin)
    {
        cout << "Invlaid menu input. program is terminating" << endl;
        return 1;
    }
    else if (outputChoice < 1 || outputChoice > 3)
    {
        cout << "You choice an invalid option; Program terminating" << endl;
        return 1;
    }


    //collect user input 
    cin.ignore();
    cout << "Enter your first and last name: ";
    getline(cin, name);
    cout << "Enter your hourly wage (ex: 13.75): ";
    cin >> payRate;
    cout << "Enter your hours worked this pay period (ex: 160 or 76.5): ";
    cin >> hoursWorked;
    cout << endl << endl;
    cout << "Please note that all percentages must sum to 100% or less" << endl;
    cout << "Enter the amount you want to allocate for food as a decimal: ";
    cin >> foodRate;
    cout << "Enter the amount you want to allocate for mortgage as a decimal: ";
    cin >> mortgageRate;
    cout << "Enter the amount you want to allocate for savings as a decimal: ";
    cin >> savingsRate;
    cout << "Enter the amount you want to allocate for utilities as a decimal: ";
    cin >> utilitiesRate;
    cout << "Enter the amount you want to allocate for books as a decimal: ";
    cin >> booksRate;
    cout << "Enter the amount you want to allocate for beauty as a decimal: ";
    cin >> beautyRate;


    //calculations
    if (periodChoice == 'W' || periodChoice == 'w')
    {
        payPeriod = "Weekley";
        multiplyer = 4;

    }
   
    else if (periodChoice == 'B' || periodChoice == 'b')
    {
        payPeriod = "Bi-Weekley";
        multiplyer = 2;

    }
    
    else
    {
        payPeriod = "Monthly";
        multiplyer = 1;
    }
    
    gross = (payRate * hoursWorked) * multiplyer;
    taxes = gross * TAX_RATE;
    net = gross - taxes;
    mortgage = net * mortgageRate;
    utilities = net * utilitiesRate;
    food = net * foodRate;
    savings = net * savingsRate;
    beauty = net * beautyRate;
    books = net * booksRate;
    leftover = net - (mortgage + utilities + food + savings + beauty + books);

    //clear the screen 
    system("cls");

    //formatted money
    cout << fixed << setprecision(2) << showpoint;
    fout << fixed << setprecision(2) << showpoint;


    //if structure for options (1,2,3)
    if (outputChoice == 1)
    {
       
        cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        cout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        cout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        cout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        cout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        cout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        cout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        cout << setw(COLUMN_ONE) << left << "Beauty: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << beauty << endl << endl;
        cout << "You have $" << leftover << " left over this month" << endl;
    }

    else if (outputChoice == 2)
    {
      
        fout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        fout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        fout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        fout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        fout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        fout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        fout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        fout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        fout << setw(COLUMN_ONE) << left << "Beauty: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << beauty << endl << endl;
        fout << "You have $" << leftover << " left over this month" << endl;
        cout << "please check output file \"budget.txt\" for your results" << endl;
    }

    else
    {
        cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        cout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        cout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        cout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        cout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        cout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        cout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        cout << setw(COLUMN_ONE) << left << "Beauty: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << beauty << endl << endl;
        cout << "You have $" << leftover << " left over this month" << endl;
  


        fout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        fout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        fout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        fout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        fout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        fout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        fout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        fout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        fout << setw(COLUMN_ONE) << left << "Beauty: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << beauty << endl << endl;
        fout << "You have $" << leftover << " left over this month" << endl;
    }


    //output to console
    cout << fixed << setprecision(2) << showpoint;
    cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
    cout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
    cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
    cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
    cout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
    cout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
    cout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
    cout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
    cout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
    cout << setw(COLUMN_ONE) << left << "Beauty: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << beauty << endl << endl;
    cout << "You have $" << leftover << " left over this month" << endl;

    return 0;
}
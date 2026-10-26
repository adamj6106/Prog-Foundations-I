// JohnsonABudgetV3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Budget V5: adding arrays 


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
const int A_SIZE = 6;

int main()
{
    //arrays
    //creating an array that is already initilized using the names of the categorys
    string categories[A_SIZE] = { "Morgrage", "Utilities", "Savings", "Food", "Beauty", "Books" };

    //array where we story user defined rates
    double rates[A_SIZE];

    //array where we story the calculated amounts per category
    double amounts[A_SIZE];


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
    double totPerc;
    double otHours = 0;
    double otPay = 0;


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
    while (periodChoice != 'W' && periodChoice != 'w' && periodChoice != 'B' && periodChoice != 'b' && periodChoice != 'M' && periodChoice != 'm')
    {
        cout << "Invalid input, please enter a valid option (W,B,M)" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> periodChoice;
    }

    cout << "please enter your output choice (1,2,3)" << endl;
    cin >> outputChoice;

    while (!cin || outputChoice < 1 || outputChoice > 3)
    {
        cout << "Invalid inout please enter an option between 1 and 3: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> outputChoice;
    }
    //error check


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
   
    //calculations
    if (periodChoice == 'W' || periodChoice == 'w')
    {
        payPeriod = "Weekley";
        multiplyer = 4;
        if (hoursWorked > 40)
        {
            otHours = hoursWorked - 40;
        }

    }

    else if (periodChoice == 'B' || periodChoice == 'b')
    {
        payPeriod = "Bi-Weekley";
        multiplyer = 2;
        if (hoursWorked > 80)
        {
            otHours = hoursWorked - 80;
        }
    }

    else
    {
        payPeriod = "Monthly";
        multiplyer = 1;
        if (hoursWorked > 160)
        {
            otHours = hoursWorked - 160;
        }
    }

    //enter the rates with an array
    do {
        totPerc = 0;
        cout << endl;
        cout << "Please enter each budget percentage as a decimal. " << endl;
        cout << "Example: 25% should be entered as 0.25." << endl;
        cout << "Total percentages should be less then 100." << endl << endl;

        for (int i = 0; i < A_SIZE; i++)
        {
            //we stored the category names in a veraiable the same size as the rates and calulations
            //think of this as an excel spreadsheet 
            //array 1 index zero is morgage, arry 2 indeex zero is the rate for morgage, array 3 index zero is the amount of the morgage

            cout << "Enter the percentage for " << categories[i] << ": ";
            cin >> rates[i];

            while (!cin || rates[i] < 0 || rates[i] > 1)
            {
                cout << "Invalid input, enter a deciaml between 0 and 1.";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> rates[i];
            }
            //running total for percentages calculations
            totPerc = totPerc + rates[i];
        }

        if (totPerc > 1.0)
        {
            cout << endl;
            cout << "The total percentages are greater then 100, please try again" << endl;
        }

    } while (totPerc > 1.0 );

    gross = (payRate * hoursWorked) * multiplyer;
    if (otHours > 0)
    {
        otPay = (otHours * payRate * multiplyer) * .5;
    }
    gross = gross + otPay;
    taxes = gross * TAX_RATE;
    net = gross - taxes;
    leftover = net;

    for (int i = 0; i < A_SIZE; i++)
    {
        amounts[i] = net * rates[i];
        leftover = leftover - amounts[i];
    }

   
    //clear the screen 
    system("cls");

    //formatted money
    cout << fixed << setprecision(2) << showpoint;
    fout << fixed << setprecision(2) << showpoint;


    //if structure for options (1,2,3)
    if (outputChoice == 1)
    {

        cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        cout << setw(COLUMN_ONE) << left << "Pay Period: " << setw(NAME) << payPeriod << endl;
        cout << setw(COLUMN_ONE) << left << "Gross Pay: " << setw(DOLLAR_SIGN) << '$' << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;

        for (int i = 0; i < A_SIZE; i++)
        {
            cout << setw(COLUMN_ONE) << left << categories[i] << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << amounts[i];
        }

        cout << setw(COLUMN_ONE) << left << "Leftover" << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << leftover << endl;

       
    }

    else if (outputChoice == 2)
    {
        fout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        fout << setw(COLUMN_ONE) << left << "Pay Period: " << setw(NAME) << payPeriod << endl;
        fout << setw(COLUMN_ONE) << left << "Gross Pay: " << setw(DOLLAR_SIGN) << '$' << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;

        for (int i = 0; i < A_SIZE; i++)
        {
            fout << setw(COLUMN_ONE) << left << categories[i] << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << amounts[i];
        }

        fout << setw(COLUMN_ONE) << left << "Leftover" << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << leftover << endl;

        fout << "please check output file \"budget.txt\" for your results" << endl;
    }

    else
    {
        cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        cout << setw(COLUMN_ONE) << left << "Pay Period: " << setw(NAME) << payPeriod << endl;
        cout << setw(COLUMN_ONE) << left << "Gross Pay: " << setw(DOLLAR_SIGN) << '$' << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;

        for (int i = 0; i < A_SIZE; i++)
        {
            cout << setw(COLUMN_ONE) << left << categories[i] << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << amounts[i];
        }

        cout << setw(COLUMN_ONE) << left << "Leftover" << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << leftover << endl;


        fout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        fout << setw(COLUMN_ONE) << left << "Pay Period: " << setw(NAME) << payPeriod << endl;
        fout << setw(COLUMN_ONE) << left << "Gross Pay: " << setw(DOLLAR_SIGN) << '$' << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;

        for (int i = 0; i < A_SIZE; i++)
        {
            fout << setw(COLUMN_ONE) << left << categories[i] << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << amounts[i];
        }

        fout << setw(COLUMN_ONE) << left << "Leftover" << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << leftover << endl;

        fout << "please check output file \"budget.txt\" for your results" << endl;
    }



    

    fout.close();

    return 0;
}
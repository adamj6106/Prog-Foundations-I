// AdamJohnsonSalesArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

//constants
const int ARRAY_SIZE = 7;
const int COL_1 = 4;
const int COL_2 = 2;
const int COL_3 = 8;

int main()
{
    //declare variables
    double num[ARRAY_SIZE];
    double high;
    double low;
    double total;
    double average;
    double sum = 0;

    ifstream fin;

    //open file
    fin.open("daily_sales.txt");
    
    if (!fin)
    {
        cout << "Input file not found. program terminating" << endl;
            return 1;
    }
    //progrma title and describtion
    cout << "Sales Array" << endl;
    cout << "Created by: Adam Johnson" << endl;
    cout << "This program will read in sales information from a file" << endl;
    cout << "calculate sales states, and print to the console" << endl << endl;

    //console output
    cout << setprecision(2) << fixed << showpoint;
    cout << "Weekly Sales Report" << endl;
    cout << "--------------------" << endl;

    //read in to the array

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        fin >> num[i];
        cout << setw(COL_1) << left << "Day" << setw(COL_2) << i + 1 << setw(COL_2) << ":" << setw(COL_2) << "$" << setw(COL_3) << right << num[i] << endl;
        sum = sum + num[i];
    }
    average = sum / ARRAY_SIZE;
    cout << endl << endl;

    cout << " your total sales for this week are: $" << sum << endl;
    cout << "Average sales fo this week are: $" << average << endl;

    high = num[0];
    low = num[0];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (num[i] > high)
        {
            high = num[i];
        }
        if (num[i] > low)
        {
            low = num[i];
        }
    }

    cout << "Highest daily sales this week are: $" << high << endl;
    cout << "lowest daily sales this week are: $" << low << endl;
    fin.close();
    return 0;

}



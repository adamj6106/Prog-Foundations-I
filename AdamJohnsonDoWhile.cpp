// AdamJohnsonDoWhile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int main()
{
    int i;
    int guess;
    bool numError = false;
    char menuChoice;

   /* i = 11;
    do
    {
        cout << i << " ";
        i = i + 5;
    } while (i <= 10);*/

    /*do
    {
        cout << "Enter a number between one and ten: ";
        cin >> guess;
        if (!cin)
        {
            cout << "Invalid input. Please try again." << endl;
            numError = true;
        }
        else if (guess < 1 || guess > 10)
        {
            cout << "You ented a number outside the range please try again." << endl;
            numError = true;
        }
        else
        {
            cout << "Great job sucsessful attempt." << endl;
            numError = false;
        }
        cin.clear();
        cin.ignore();
        
    } while (numError == true);*/


    do
    {
        cout << "Menu Options" << endl;
        cout << "A- option A" << endl;
        cout << "B- option B" << endl;
        cout << "C- option C" << endl;
        cout << "D- Exit program" << endl;

        do
        {
            cout << "Enter your menu choice: ";
            cin >> menuChoice;

            if (menuChoice != 'A' && menuChoice != 'B' && menuChoice != 'C' && menuChoice != 'D')
            {
                cout << "You've entered an invalid menu choice please try again" << endl;
            }
            cin.clear();
            cin.ignore();
        } while (menuChoice != 'A' && menuChoice != 'B' && menuChoice != 'C' && menuChoice != 'D');
            if (menuChoice == 'A')
            {
                cout << "You've picked A" << endl;
            }
            else if (menuChoice == 'B')
             {
                cout << "You've picked B" << endl;
             }
        else if (menuChoice == 'C')
            {
                cout << "You've picked C" << endl;
            }
    } while (menuChoice != 'D');
    {
        cout << "Thanks for using our program" << endl;
    }
}


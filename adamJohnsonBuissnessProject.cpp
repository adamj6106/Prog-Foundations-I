// Adam Johnson
// Business Project V1
// In this project, the user will be deciding what it is that they want to buy at cosmic comics
//10-4-2026

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

//Constants
const double TAX_RATE = 0.10;
const double SMALL_AC = 10.00;
const double MEDIUM_AC = 18.00;
const double LARGE_AC = 25.00;
const double SINGLE = 5.00;
const double TRADE = 15.00;
const double OMNIBUS = 35.00;




int main()
{
    //Setting all numbers to 2 decimal places

    cout << fixed << showpoint << setprecision(2);


    //Variables

    char itemChoice;
    int actionFigureSize;
    char comicBookSize;


    //Menu

    cout << "Welcome to Cosmic Comics" << endl;
    cout << "Come catch your favorite heroes and villains at Cosmic Comics" << endl << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "                         MENU" << endl << endl;
    cout << "Comics" << endl << endl;
    cout << "Single Issue (S)     $ 5.00" << endl;
    cout << "Trade Paperback (T)  $ 15.00" << endl;
    cout << "Omnibus (O)          $ 35.00" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Action Figures" << endl << endl;
    cout << "Small (1)     $ 10.00" << endl;
    cout << "Medium (2)    $ 18.00" << endl;
    cout << "Large (3)     $ 25.00" << endl;
    cout << "------------------------------------------------------------" << endl << endl;


    //Customer choice

    cout << "Would you like a Comic book or Action Figure? (Please enter C or A): ";
    cin >> itemChoice;
    cout << endl;


    //Error Checking

    if (itemChoice == 'C' || itemChoice == 'c')
    {
        //Comic size    

        cout << "Select your comic size (S, T, O): ";
        cin >> comicBookSize;



        if (comicBookSize == 'S' || comicBookSize == 's')
        {
            cout << endl;
            cout << "You've ordered a single issue." << endl << endl;
            cout << "Subtotal:      $" << SINGLE << endl;
            cout << "Tax (10%):     $" << SINGLE * TAX_RATE << endl;
            cout << "Total:         $" << SINGLE * TAX_RATE + SINGLE << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;

        }
        else if (comicBookSize == 'T' || comicBookSize == 't')
        {
            cout << endl;
            cout << "You've ordered a Trade Paperback." << endl << endl;
            cout << "Subtotal:      $" << TRADE << endl;
            cout << "Tax (10%):     $" << TRADE * TAX_RATE << endl;
            cout << "Total:         $" << TRADE * TAX_RATE + TRADE << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;
        }
        else if (comicBookSize == 'O' || comicBookSize == 'o')
        {
            cout << endl;
            cout << "You've ordered an Omnibus." << endl << endl;
            cout << "Subtotal:      $" << OMNIBUS << endl;
            cout << "Tax (10%):     $" << OMNIBUS * TAX_RATE << endl;
            cout << "Total:         $" << OMNIBUS * TAX_RATE + OMNIBUS << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;
        }
        else
        {
            cout << "You've entered an invalid input, program terminating" << endl;
        }
    }
    else if (itemChoice == 'A' || itemChoice == 'a')
    {
        //Action figure size

        cout << "Select your action figure size (1, 2, 3): ";
        cin >> actionFigureSize;

        if (!cin)
        {
            cout << "You've entered an invalid input, program terminating" << endl;
            return 0;
        }
        if (actionFigureSize == 1)
        {
            cout << endl;
            cout << "You've ordered a small Action Figure." << endl << endl;
            cout << "Subtotal:      $" << SMALL_AC << endl;
            cout << "Tax (10%):     $" << SMALL_AC * TAX_RATE << endl;
            cout << "Total:         $" << SMALL_AC * TAX_RATE + SMALL_AC << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;
        }
        else if (actionFigureSize == 2)
        {
            cout << endl;
            cout << "You've ordered a medium Action Figure." << endl << endl;
            cout << "Subtotal:      $" << MEDIUM_AC << endl;
            cout << "Tax (10%):     $" << MEDIUM_AC * TAX_RATE << endl;
            cout << "Total:         $" << MEDIUM_AC * TAX_RATE + MEDIUM_AC << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;
        }
        else if (actionFigureSize == 3)
        {
            cout << endl;
            cout << "You've ordered a large Action Figure." << endl << endl;
            cout << "Subtotal:      $" << LARGE_AC << endl;
            cout << "Tax (10%):     $" << LARGE_AC * TAX_RATE << endl;
            cout << "Total:         $" << LARGE_AC * TAX_RATE + LARGE_AC << endl << endl;
            cout << "Thank you for coming to Cosmic Comics! Have a good day!" << endl;
        }
        else
        {
            cout << "You've entered an invalid input, program terminating" << endl;
        }
    }
    else
    {
        cout << "You've entered an invalid input, program terminating" << endl;
    }




    return 0;
}
